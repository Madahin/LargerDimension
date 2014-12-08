#ifndef ENEMIE_R
#define ENEMIE_R

#include "include/Enemie/Enemie.hpp"

class EnemieR : public Enemie
{
public:
    EnemieR(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
