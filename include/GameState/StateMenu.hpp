#ifndef STATEMENU_HPP
#define STATEMENU_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "include/GameState/State.hpp"
#include "include/GameState/StateAnim.hpp"
#include "include/Tools/auto_Texture.hpp"
#include "include/Manager/InputManager.hpp"

#include "include/Enemie/EnemieAll.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <array>

class StateMenu : public State
{
public:
    StateMenu();

    void Init() override;
    void Free() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Event() override;
    void Update() override;
    void Pause() override;
    void UnPause() override;

private:
    sf::Sprite m_PlayButton;
	sf::Text m_CheatText;
    sf::Texture m_TileSet;
    sf::Font m_CheatFont;
    std::vector<std::shared_ptr<Enemie>> m_EnemieList;
    std::array<sf::Keyboard::Key, 10> m_konami;
    unsigned int m_iKonamiIndex;
    bool m_bDrawGorilla;
};

#endif // STATEMENU_HPP
