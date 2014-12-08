#ifndef ENEMIE_I
#define ENEMIE_I

#include "include/Enemie/Enemie.hpp"

class EnemieI : public Enemie
{
public:
    EnemieI(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
