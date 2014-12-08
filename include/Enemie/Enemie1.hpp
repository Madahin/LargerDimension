#ifndef ENEMIE_1
#define ENEMIE_1

#include "include/Enemie/Enemie.hpp"

class Enemie1 : public Enemie
{
public:
    Enemie1(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;

private:
    float m_Angle;
};

#endif
