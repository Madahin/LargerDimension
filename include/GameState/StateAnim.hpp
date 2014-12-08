#ifndef STATEINANIM_HPP
#define STATEINANIM_HPP

#include "include/GameState/State.hpp"
#include "include/GameState/StateInGame.hpp"
#include "include/Enemie/EnemieAll.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <memory>

#define ANIM_FRAME 100

class StateAnim : public State
{
public:
    StateAnim();

    void Init() override;
    void Free() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Event() override;
    void Update() override;
    void Pause() override;
    void UnPause() override;

private:
    sf::Clock m_Clock;
    std::array<sf::IntRect, 9> m_PosTexture;
    sf::Texture m_TileSet;
    sf::Sprite m_Player;
    unsigned short m_frameCount;
    unsigned int m_backStep;
    bool m_bAnimPlayerOver;

    std::vector<std::shared_ptr<Enemie>> m_EnemieList;
};

#endif // STATEINGAME_HPP
