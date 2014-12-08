#ifndef ENEMIE_G
#define ENEMIE_G

#include "include/Enemie/Enemie.hpp"

class EnemieG : public Enemie
{
public:
    EnemieG(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;
};

#endif
