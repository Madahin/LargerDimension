#ifndef ENEMIE
#define ENEMIE

#include "include/Tir/Tir.hpp"
#include "include/Tools/Mathf.hpp"
#include "include/Manager/PlayerManager.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

class Enemie
{
public:
    Enemie(sf::Texture &a_Tileset);
    virtual void Anim() = 0;
    virtual void Fire() = 0;
    virtual void Draw(sf::RenderWindow &a_window) = 0;
    virtual void Move(sf::Sprite &a_Player) = 0;
    virtual void Finish() = 0;
    virtual void Death() = 0;
    void Hit(sf::Sprite &a_Player);
    void SetPos(float a_X, float a_Y);
    void MoveBack();
    sf::Sprite& GetSprite();
    bool IsUsable();

    bool m_bAnimOver;

protected:
    sf::Texture& m_Tileset;
    sf::Clock m_ClockAnim;
    sf::Clock m_ClockFire;
    std::vector<sf::IntRect> m_PosFrame;
    std::vector<Tir> m_TirList;
    sf::Sprite m_Enemie;
    unsigned int m_iFrameIndex;
    bool m_bUsable;
};

#endif
