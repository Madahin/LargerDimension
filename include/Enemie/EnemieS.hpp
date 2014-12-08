#ifndef ENEMIE_S
#define ENEMIE_S

#include "include/Enemie/Enemie.hpp"

class EnemieS : public Enemie
{
public:
    EnemieS(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;

private:
    unsigned int m_cmpt;
};

#endif
