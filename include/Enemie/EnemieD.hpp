#ifndef ENEMIE_D
#define ENEMIE_D

#include "include/Enemie/Enemie.hpp"

class EnemieD : public Enemie
{
public:
    EnemieD(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
