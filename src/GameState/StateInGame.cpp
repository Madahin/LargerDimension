#include "include/GameState/StateInGame.hpp"

StateInGame::StateInGame()
{
    for(bool &b : m_bMovement){
        b = false;
    }
    m_PlayerShot = false;

    m_IndexData = 0;
    std::ifstream t_File("Ressources/wave.txt");
    std::string t_sLine;
    while(std::getline(t_File, t_sLine)){
        if(t_sLine.empty() || t_sLine[0] == ';') continue;
        std::vector<std::string> tokens = split(t_sLine, ';');
        EnemiesData t_Data = {atof(tokens[0].c_str()), tokens[1][0], atoi(tokens[2].c_str())};
        m_WaveData.push_back(t_Data);
    }
	m_iIndexDeath = 0;
}

void StateInGame::Init()
{
    m_Clock.restart();
    m_TileSet.loadFromFile("Ressources/Texture/Vaisseaux.png");
    m_Player.setTexture(m_TileSet);
    m_Player.setTextureRect(sf::IntRect(78*7, 0, 78, 72));
    m_Player.setPosition(473, 450);

    m_boomBuffer.loadFromFile("Ressources/SFX/boom.wav");
    m_BoomSound.setBuffer(m_boomBuffer);
}

void StateInGame::Free()
{
}

void StateInGame::Draw(sf::RenderWindow &a_window)
{
    for(auto &e : m_EnemieList){
        e->Draw(a_window);
    }
    for(Tir& tir : m_Tir){
        tir.Draw(a_window);
    }
    a_window.draw(m_Player);
}

void StateInGame::Event()
{
    sf::Event& t_Event = InputManager::Get().GetEvent();
    switch (t_Event.type)
    {
        case sf::Event::KeyPressed:
        {
            switch(t_Event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    m_bMovement[BUP] = true;
                    break;
                }
                case sf::Keyboard::Down:
                {
                    m_bMovement[BDOWN] = true;
                    break;
                }
                case sf::Keyboard::Left:
                {
                    m_bMovement[BLEFT] = true;
                    break;
                }
                case sf::Keyboard::Right:
                {
                    m_bMovement[BRIGHT] = true;
                    break;
                }
                case sf::Keyboard::Space:
                {
                    m_PlayerShot = true;
                    break;
                }
                default:
                    break;
            }

            break;
        }
        case sf::Event::KeyReleased:
        {
            switch(t_Event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    m_bMovement[BUP] = false;
                    break;
                }
                case sf::Keyboard::Down:
                {
                    m_bMovement[BDOWN] = false;
                    break;
                }
                case sf::Keyboard::Left:
                {
                    m_bMovement[BLEFT] = false;
                    break;
                }
                case sf::Keyboard::Right:
                {
                    m_bMovement[BRIGHT] = false;
                    break;
                }
                case sf::Keyboard::Space:
                {
                    m_PlayerShot = false;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void StateInGame::Update()
{
	if (PlayerManager::Get().Over){
        m_PlayerShot = false;
        if(m_AnimDeath.getElapsedTime().asMilliseconds() >= 200){
            m_Player.setTextureRect(sf::IntRect(m_iIndexDeath * 78, 13*72, 78, 72));
            m_iIndexDeath++;
            m_AnimDeath.restart();
            if(m_iIndexDeath == 3){
                PlayerManager::Get().CanChange = true;
            }
        }
    }

    GenerateEnemies();
    if(m_bMovement[BUP]){
        m_Player.move(0, -1);
        if(m_Player.getPosition().y < 0){
            m_Player.move(0, 1);
        }
    }if(m_bMovement[BDOWN]){
        m_Player.move(0, 1);
        if((m_Player.getPosition().y + m_Player.getLocalBounds().height) > 768){
            m_Player.move(0, -1);
        }
    }if(m_bMovement[BLEFT]){
        m_Player.move(-1, 0);
        if(m_Player.getPosition().x < -10){
            m_Player.move(1, 0);
        }
    }if(m_bMovement[BRIGHT]){
        m_Player.move(1, 0);
        if((m_Player.getPosition().x + m_Player.getLocalBounds().width) > 1034){
            m_Player.move(-1, 0);
        }
    }

    for(auto it = m_Tir.begin(); it != m_Tir.end(); it++){
        if(!it->IsUsable())continue;
        it->Anim();
        it->Move();
        for(auto &e : m_EnemieList){
            if(e->IsUsable() && it->GetSprite().getGlobalBounds().intersects(e->GetSprite().getGlobalBounds())){
                e->Death();
                it->Destroy();
                if(m_BoomSound.getStatus() != sf::Sound::Status::Playing)m_BoomSound.play();
                break;
            }
        }
    }

    for(auto &e : m_EnemieList){
        e->Anim();
        e->Move(m_Player);
        e->Fire();
        if(e->IsUsable() && Mathf::IsPlayerTouched(m_Player, e->GetSprite())){//m_Player.getGlobalBounds().intersects(e->GetSprite().getGlobalBounds())){
            e->Death();
            if(m_BoomSound.getStatus() != sf::Sound::Status::Playing)m_BoomSound.play();
            PlayerManager::Get().LostPV();
        }
    }

    if(m_PlayerShot){
        if(m_clockShot.getElapsedTime().asMilliseconds() >= 375){
            bool ok = true;
            for(auto it = m_Tir.begin(); it != m_Tir.end(); it++){
                if(it->IsOut()){
                    it->SetPos(m_Player.getPosition().x, m_Player.getPosition().y);
                    it->Revive();
                    ok = false;
                    break;
                }
            }
            if(ok) m_Tir.push_back(Tir(m_TileSet, 0, 1, 3, 1.5f, -Mathf::PI * 0.5f, m_Player.getPosition().x, m_Player.getPosition().y));
            m_clockShot.restart();
        }
    }

    //Si Gagner, PlayerManager::Get().CanChange = true;

    if(m_IndexData == m_WaveData.size() && AllDeadOrFleeing()){
        PlayerManager::Get().CanChange = true;
    }
}

void StateInGame::Pause()
{
}

void StateInGame::UnPause()
{
}

void StateInGame::GenerateEnemies()
{
    if((m_IndexData < m_WaveData.size()) && (m_Time.getElapsedTime().asSeconds() >= m_WaveData[m_IndexData].waveTime)){
        std::shared_ptr<Enemie> t_Enemie;
        switch (m_WaveData[m_IndexData].type) {
            case '1':
                t_Enemie.reset(new Enemie1(m_TileSet));
                break;
            case '3':
                t_Enemie.reset(new Enemie3(m_TileSet));
                break;
            case 'A':
                t_Enemie.reset(new EnemieA(m_TileSet));
                break;
            case 'D':
                t_Enemie.reset(new EnemieD(m_TileSet));
                break;
            case 'E':
                t_Enemie.reset(new EnemieE(m_TileSet));
                break;
            case 'G':
                t_Enemie.reset(new EnemieG(m_TileSet));
                break;
            case 'I':
                t_Enemie.reset(new EnemieI(m_TileSet));
                break;
            case 'L':
                t_Enemie.reset(new EnemieL(m_TileSet));
                break;
            case 'M':
                t_Enemie.reset(new EnemieM(m_TileSet));
                break;
            case 'N':
                t_Enemie.reset(new EnemieN(m_TileSet));
                break;
            case 'O':
                t_Enemie.reset(new EnemieO(m_TileSet));
                break;
            case 'R':
                t_Enemie.reset(new EnemieR(m_TileSet));
                break;
            case 'S':
                t_Enemie.reset(new EnemieS(m_TileSet));
                break;
        }
        t_Enemie->Finish();
        t_Enemie->SetPos(m_WaveData[m_IndexData].posX, -t_Enemie->GetSprite().getGlobalBounds().height);
        m_EnemieList.push_back(t_Enemie);
        m_IndexData++;
    }
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

bool StateInGame::AllDeadOrFleeing()
{
    bool over = true;
    for(auto &e : m_EnemieList){
        if(e->IsUsable() && e->GetSprite().getPosition().y < 768){
            over = false;
            break;
        }
    }
    return over;
}
