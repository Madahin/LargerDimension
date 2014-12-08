#ifndef ENEMIE_L
#define ENEMIE_L

#include "include/Enemie/Enemie.hpp"

class EnemieL : public Enemie
{
public:
    EnemieL(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
