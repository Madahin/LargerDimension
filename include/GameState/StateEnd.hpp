#ifndef STATEEND_HPP
#define STATEEND_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "include/GameState/State.hpp"
#include "include/GameState/StateAnim.hpp"
#include "include/Tools/auto_Texture.hpp"
#include "include/Manager/InputManager.hpp"
#include "include/Manager/PlayerManager.hpp"

#include "include/Enemie/EnemieAll.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <array>

class StateEnd : public State
{
public:
    StateEnd();

    void Init() override;
    void Free() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Event() override;
    void Update() override;
    void Pause() override;
    void UnPause() override;

private:
    sf::Font m_Font;
    sf::Text m_Text;
    sf::Text m_RestartText;

    sf::Texture m_GorillaTex;
    sf::Sprite m_Gorilla;
};

#endif // STATEMENU_HPP
