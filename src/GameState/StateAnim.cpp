#include "include/GameState/StateAnim.hpp"

StateAnim::StateAnim() :
    m_frameCount(0),
    m_backStep(0),
    m_bAnimPlayerOver(false)
{
}

void StateAnim::Init()
{
    m_Clock.restart();
    for(int i=0; i < 9; i++){
        sf::IntRect t_pos(78*i, 0, 78, 72);
        m_PosTexture[i] = t_pos;
    }
    m_TileSet.loadFromFile("Ressources/Texture/Vaisseaux.png");
    m_Player.setTexture(m_TileSet);
    m_Player.setTextureRect(m_PosTexture[m_frameCount]);
    m_Player.setPosition(473, 450);

    const float beginX = 278;
    const float beginY = 50;

    std::shared_ptr<Enemie> char1(new EnemieL(m_TileSet));
    char1->SetPos(beginX, beginY);
    m_EnemieList.push_back(char1);

    std::shared_ptr<Enemie> char2(new EnemieA(m_TileSet));
    char2->SetPos(beginX + 78, beginY);
    m_EnemieList.push_back(char2);

    std::shared_ptr<Enemie> char3(new EnemieR(m_TileSet));
    char3->SetPos(beginX + 78*2, beginY);
    m_EnemieList.push_back(char3);

    std::shared_ptr<Enemie> char4(new EnemieG(m_TileSet));
    char4->SetPos(beginX + 78*3, beginY);
    m_EnemieList.push_back(char4);

    std::shared_ptr<Enemie> char5(new EnemieE(m_TileSet));
    char5->SetPos(beginX + 78*4, beginY);
    m_EnemieList.push_back(char5);

    std::shared_ptr<Enemie> char6(new EnemieR(m_TileSet));
    char6->SetPos(beginX + 78*5, beginY);
    m_EnemieList.push_back(char6);

    std::shared_ptr<Enemie> char7(new EnemieD(m_TileSet));
    char7->SetPos(beginX - 78 * 0.5f - 78, beginY + 72);
    m_EnemieList.push_back(char7);

    std::shared_ptr<Enemie> char8(new EnemieI(m_TileSet));
    char8->SetPos(beginX - 78 * 0.5f, beginY + 72);
    m_EnemieList.push_back(char8);

    std::shared_ptr<Enemie> char9(new EnemieM(m_TileSet));
    char9->SetPos(beginX + 78 * 0.5f, beginY + 72);
    m_EnemieList.push_back(char9);

    std::shared_ptr<Enemie> char10(new EnemieE(m_TileSet));
    char10->SetPos(beginX + 78 * 0.5f + 78, beginY + 72);
    m_EnemieList.push_back(char10);

    std::shared_ptr<Enemie> char11(new EnemieN(m_TileSet));
    char11->SetPos(beginX + 78 * 0.5f + 78*2, beginY + 72);
    m_EnemieList.push_back(char11);

    std::shared_ptr<Enemie> char12(new EnemieS(m_TileSet));
    char12->SetPos(beginX + 78 * 0.5f + 78*3, beginY + 72);
    m_EnemieList.push_back(char12);

    std::shared_ptr<Enemie> char13(new EnemieI(m_TileSet));
    char13->SetPos(beginX + 78 * 0.5f + 78*4, beginY + 72);
    m_EnemieList.push_back(char13);

    std::shared_ptr<Enemie> char14(new EnemieO(m_TileSet));
    char14->SetPos(beginX + 78 * 0.5f + 78*5, beginY + 72);
    m_EnemieList.push_back(char14);

    std::shared_ptr<Enemie> char15(new EnemieN(m_TileSet));
    char15->SetPos(beginX + 78 * 0.5f + 78*6, beginY + 72);
    m_EnemieList.push_back(char15);

    std::shared_ptr<Enemie> char16(new Enemie3(m_TileSet));
    char16->SetPos(beginX + 78*2, beginY + 144);
    m_EnemieList.push_back(char16);

    std::shared_ptr<Enemie> char17(new Enemie1(m_TileSet));
    char17->SetPos(beginX + 78*3, beginY + 144);
    m_EnemieList.push_back(char17);
}

void StateAnim::Free()
{
}

void StateAnim::Draw(sf::RenderWindow &a_window)
{
    a_window.draw(m_Player);
    for(auto &e : m_EnemieList){
        e->Draw(a_window);
    }
}

void StateAnim::Event()
{
}

void StateAnim::Update()
{
    if(m_Clock.getElapsedTime().asMilliseconds() >= ANIM_FRAME){
        if(!m_bAnimPlayerOver){
            m_frameCount++;
            m_Player.setTextureRect(m_PosTexture[m_frameCount]);
            m_Clock.restart();
            if(m_frameCount == 8){
                m_bAnimPlayerOver = true;
                //m_manager->PushState(new StateInGame);
            }
        }
    }

    bool over = true;
    for(auto &e : m_EnemieList){
        e->Anim();
        if(!e->m_bAnimOver){
            over = false;
        }
    }

    if(over){
        for(auto &e : m_EnemieList){
            e->MoveBack();
        }
        m_backStep++;
        if(m_backStep == 300){
            m_manager->PushState(new StateInGame);
        }
    }
}

void StateAnim::Pause()
{
}

void StateAnim::UnPause()
{
}
