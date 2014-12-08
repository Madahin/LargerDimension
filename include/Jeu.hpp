#ifndef JEU
#define JEU

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "include/Manager/InputManager.hpp"
#include "include/Manager/StateManager.hpp"
#include "include/Manager/PlayerManager.hpp"
#include "include/GameState/StateMenu.hpp"
#include "include/GameState/StateEnd.hpp"
#include "include/Background.hpp"

class Jeu
{
public:
    Jeu();

    void launch();

private:
    sf::RenderWindow m_window;
    StateManager m_manager;

    const sf::Int64 MS_PER_UPDATE = static_cast<sf::Int64>((1.0 / 180.0) * 1000000);

    sf::Music m_Music;
};

#endif
