#include "include/Jeu.hpp"

Jeu::Jeu() :
    m_window()
{
    m_manager.PushState(new StateMenu);
    m_Music.openFromFile("Ressources/SFX/music.wav");
    m_Music.setLoop(true);
}

void Jeu::launch()
{
    m_Music.play();
    m_window.create(sf::VideoMode(1024, 768, 32), "Larger Dimension 31");
    m_window.setFramerateLimit(60);
    m_window.setVerticalSyncEnabled(true);

    InputManager& t_Input = InputManager::Get();
    t_Input.SetWindow(m_window);

    bool t_bIsOpen = true;

    sf::Clock t_Clock;
    sf::Int64 t_iLag = 0;

    Background t_Background;

    while(t_bIsOpen)
    {
        if(PlayerManager::Get().CanChange){
            m_manager.PushState(new StateEnd);
            PlayerManager::Get().CanChange = false;
        }
        if(PlayerManager::Get().Restart){
            PlayerManager::Get().Restart = false;
            m_manager.Clear();
            m_manager.PushState(new StateMenu);
            PlayerManager::Get().Over = false;
        }

        sf::Int64 t_iElapsed = t_Clock.restart().asMicroseconds();
        t_iLag += t_iElapsed;

        sf::Event t_event;
        while(m_window.pollEvent(t_event))
        {
            switch (t_event.type) {
            case sf::Event::Closed:
            {
                t_bIsOpen = false;
                break;
            }
            case sf::Event::GainedFocus:
            {
                m_manager.GetState()->UnPause();
                break;
            }
            case sf::Event::LostFocus:
            {
                m_manager.GetState()->Pause();
                break;
            }
            default:
            {
                t_Input.SetEvent(t_event);
                m_manager.GetState()->Event();
                break;
            }
            }
        }

        while(t_iLag >= MS_PER_UPDATE){
            t_Background.Update();
            m_manager.GetState()->Update();
            t_iLag -= MS_PER_UPDATE;
        }

        m_window.clear();
        t_Background.Draw(m_window);
        m_manager.GetState()->Draw(m_window);
        m_window.display();
    }
}
