#ifndef ENEMIE_E
#define ENEMIE_E

#include "include/Enemie/Enemie.hpp"

class EnemieE : public Enemie
{
public:
    EnemieE(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
