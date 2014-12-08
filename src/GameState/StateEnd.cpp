#include "include/GameState/StateEnd.hpp"
StateEnd::StateEnd()
{

}

void StateEnd::Init()
{
    m_Font.loadFromFile("Ressources/fonts/Hanken-Book.ttf");
    m_Text.setFont(m_Font);

    m_GorillaTex.loadFromFile("Ressources/Texture/snowGorilla.png");
    m_Gorilla.setTexture(m_GorillaTex);
    m_Gorilla.setPosition(100, 100);

    m_RestartText.setFont(m_Font);
    m_RestartText.setString("Press SPACE to restart");
    m_RestartText.setPosition(512 - m_RestartText.getGlobalBounds().width * 0.5f, 700);
    m_RestartText.setColor(sf::Color::White);

    if(PlayerManager::Get().Over){
        m_Text.setString("Look like you lost, maybe next time ?");
        m_Text.setPosition(512 - m_Text.getGlobalBounds().width * 0.5f, 350);
    }else{
        m_Text.setString("Wow, you win !!! Here, take this badly draw snowman !");
        m_Text.setPosition(512 - m_Text.getGlobalBounds().width * 0.5f, 30);
    }
    m_Text.setColor(sf::Color::White);

}

void StateEnd::Free()
{
}

void StateEnd::Draw(sf::RenderWindow &a_window)
{
    if(!PlayerManager::Get().Over){
        a_window.draw(m_Gorilla);
    }
    a_window.draw(m_Text);
    a_window.draw(m_RestartText);
}

void StateEnd::Event()
{
    sf::Event& t_Event = InputManager::Get().GetEvent();
    switch (t_Event.type)
    {
        case sf::Event::KeyReleased:
        {
            switch(t_Event.key.code)
            {
                case sf::Keyboard::Space:
                {
                    PlayerManager::Get().Restart = true;
                    PlayerManager::Get().CanChange = false;
                    PlayerManager::Get().FullLife();
                    break;
                }
                default:
                    break;
            }
        }
        default:
            break;
    }
}

void StateEnd::Update()
{
}

void StateEnd::Pause()
{
}

void StateEnd::UnPause()
{
}
