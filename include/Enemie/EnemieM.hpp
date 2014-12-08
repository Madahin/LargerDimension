#ifndef ENEMIE_M
#define ENEMIE_M

#include "include/Enemie/Enemie.hpp"

class EnemieM : public Enemie
{
public:
    EnemieM(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
