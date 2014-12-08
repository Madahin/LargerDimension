#ifndef ENEMIE_3
#define ENEMIE_3

#include "include/Enemie/Enemie.hpp"

class Enemie3 : public Enemie
{
public:
    Enemie3(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
