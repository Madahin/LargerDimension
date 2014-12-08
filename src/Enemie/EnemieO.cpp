#include "include/Enemie/EnemieO.hpp"

EnemieO::EnemieO(sf::Texture &a_tileset) :
    Enemie::Enemie(a_tileset)
{
    for(int i=0; i < 1; i++){
        sf::IntRect pos(i*78, 11*72, 78, 72);
        m_PosFrame.push_back(pos);
    }
    m_Enemie.setTexture(a_tileset);
    m_Enemie.setPosition(320, -36);
    m_Enemie.setTextureRect(m_PosFrame[0]);
}

void EnemieO::Anim()
{
    for(Tir &tir : m_TirList){
        tir.Anim();
    }
    if(!m_bAnimOver){
        if(m_ClockAnim.getElapsedTime().asMilliseconds() >= 200){
            m_Enemie.setTextureRect(m_PosFrame[m_iFrameIndex]);
            m_iFrameIndex++;
            m_ClockAnim.restart();
        }
        if(m_iFrameIndex == m_PosFrame.size()){
            m_bAnimOver = true;
        }
    }
}

void EnemieO::Fire()
{
}

void EnemieO::Draw(sf::RenderWindow &a_window)
{
    for(Tir &tir : m_TirList){
        tir.Draw(a_window);
    }
    a_window.draw(m_Enemie);
}

void EnemieO::Move(sf::Sprite &a_Player)
{
    sf::Vector2f posPlayer = a_Player.getPosition();
    sf::Vector2f posEnemie = m_Enemie.getPosition();

    sf::Vector2f posDiff = posPlayer - posEnemie;
    posDiff.y += 30;

    float angle = (float)atan2(posDiff.y, posDiff.x) * Mathf::RAD2DEG;
    m_Enemie.setRotation(angle - 90);

    m_Enemie.move(0.4f * cos(angle * Mathf::DEG2RAD), 0.4f * sin(angle * Mathf::DEG2RAD));

    for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
        it->Move();
        Hit(a_Player);
    }
}

void EnemieO::Finish()
{
    m_bAnimOver = true;
    m_iFrameIndex = m_PosFrame.size()-1;
    m_Enemie.setTextureRect(m_PosFrame[m_iFrameIndex]);
}

void EnemieO::Death()
{
    if(!m_bUsable){
        return;
    }

    const unsigned short BULLET = 12;
    for(int i=0; i<BULLET; i++){
        Tir t = Tir(m_Tileset, 11, 4, 1, 1, Mathf::PI * 2/BULLET * i, m_Enemie.getPosition().x + 30, m_Enemie.getPosition().y + 30);
        t.GetSprite().setScale(0.5f, 0.5f);
        m_TirList.push_back(t);
    }

    m_PosFrame.clear();
    for(int i=0; i < 4; i++){
        sf::IntRect pos(i*78, 13*72, 78, 72);
        m_PosFrame.push_back(pos);
    }
    m_Enemie.setTextureRect(m_PosFrame[0]);
    m_bAnimOver = false;
    m_iFrameIndex = 0;
    m_bUsable = false;
}

