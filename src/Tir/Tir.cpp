#include "include/Tir/Tir.hpp"

Tir::Tir(sf::Texture &a_Texture, int a_iColumn, int a_iRow, int a_iFrameNumber, float a_fSpeed, float a_fAngle, float a_x, float a_y) :
    m_iFrame(0),
    m_Texture(a_Texture),
    m_fSpeed(a_fSpeed),
    m_fAngle(a_fAngle),
    m_bUsable(true)
{
    m_TirSprite.setTexture(m_Texture);
    for(int i=0; i < a_iFrameNumber; i++){
        sf::IntRect t_pos((78*a_iColumn) + 78*i, 72 * a_iRow, 78, 72);
        m_PosFrame.push_back(t_pos);
    }
    m_TirSprite.setTextureRect(m_PosFrame[m_iFrame]);
    m_TirSprite.setPosition(a_x, a_y);
    //m_TirSprite.setRotation(a_fAngle * Mathf::RAD2DEG + 90);
}

void Tir::Anim()
{
    if(m_clock.getElapsedTime().asMilliseconds() >= FRAME){
        m_iFrame = ((m_iFrame+1 == m_PosFrame.size())? 0 : m_iFrame+1);
        m_TirSprite.setTextureRect(m_PosFrame[m_iFrame]);
        m_clock.restart();
    }
}

void Tir::Draw(sf::RenderWindow &a_window)
{
    a_window.draw(m_TirSprite);
}

void Tir::Move()
{
    m_TirSprite.move(cos(m_fAngle) * m_fSpeed, sin(m_fAngle) * m_fSpeed);
}

bool Tir::IsOut()
{
    sf::Vector2f t_Pos = m_TirSprite.getPosition();
    sf::FloatRect t_Bound = m_TirSprite.getGlobalBounds();
    if((t_Pos.x < -t_Bound.width) || (t_Pos.x > 1024 + t_Bound.width) ||
       (t_Pos.y < -t_Bound.height) || (t_Pos.y > 768 + t_Bound.height)){
        return true;
    }else{
        return false;
    }
}

void Tir::SetPos(float a_x, float a_y)
{
    m_TirSprite.setPosition(a_x, a_y);
}

sf::Sprite& Tir::GetSprite()
{
    return m_TirSprite;
}

void Tir::Destroy()
{
    sf::Color c = m_TirSprite.getColor();
    c.a = 0;
    m_TirSprite.setColor(c);
    m_bUsable = false;
}

void Tir::Revive()
{
    sf::Color c = m_TirSprite.getColor();
    c.a = 255;
    m_TirSprite.setColor(c);
    m_bUsable = true;
}

bool Tir::IsUsable()
{
    return m_bUsable;
}
