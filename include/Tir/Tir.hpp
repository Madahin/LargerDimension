#ifndef TIR
#define TIR

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <include/Tools/Mathf.hpp>

#define FRAME 50

class Tir
{
public:
    Tir(sf::Texture& a_Texture, int a_iColumn, int a_iRow, int a_iFrameNumber, float a_fSpeed, float a_fAngle, float a_x, float a_y);
    void Anim();
    void Draw(sf::RenderWindow &a_window);
    void Move();
    bool IsOut();
    void SetPos(float a_x, float a_y);
    sf::Sprite& GetSprite();
    void Destroy();
    void Revive();
    bool IsUsable();

    //Tir& operator=(Tir&& a_tir);
    //Tir& operator=(const Tir& a_tir);

protected:
    sf::Clock m_clock;
    unsigned int m_iFrame;
    sf::Texture& m_Texture;
    sf::Sprite m_TirSprite;
    std::vector<sf::IntRect> m_PosFrame;
    float m_fSpeed;
    float m_fAngle;
    bool m_bUsable;
};

#endif
