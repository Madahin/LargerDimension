#ifndef ENEMIE_O
#define ENEMIE_O

#include "include/Enemie/Enemie.hpp"

class EnemieO : public Enemie
{
public:
    EnemieO(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
