#ifndef ENEMIE_A
#define ENEMIE_A

#include "include/Enemie/Enemie.hpp"

class EnemieA : public Enemie
{
public:
    EnemieA(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
