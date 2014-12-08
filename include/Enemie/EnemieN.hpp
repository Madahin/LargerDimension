#ifndef ENEMIE_N
#define ENEMIE_N

#include "include/Enemie/Enemie.hpp"

class EnemieN : public Enemie
{
public:
    EnemieN(sf::Texture &a_tileset);
    void Anim() override;
    void Fire() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Move(sf::Sprite &a_Player) override;
    void Finish() override;
    void Death() override;

private:
    unsigned int m_cmpt;
    short m_step;
};

#endif
