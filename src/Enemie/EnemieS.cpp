#include "include/Enemie/EnemieS.hpp"

EnemieS::EnemieS(sf::Texture &a_tileset) :
    Enemie::Enemie(a_tileset)
{
    for(int i=0; i < 1; i++){
        sf::IntRect pos(i*78, 10*72, 78, 72);
        m_PosFrame.push_back(pos);
    }
    m_Enemie.setTexture(a_tileset);
    m_Enemie.setPosition(320, -36);
    m_Enemie.setTextureRect(m_PosFrame[0]);
    m_cmpt=0;
}

void EnemieS::Anim()
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

void EnemieS::Fire()
{
}

void EnemieS::Draw(sf::RenderWindow &a_window)
{
    for(Tir &tir : m_TirList){
        tir.Draw(a_window);
    }
    a_window.draw(m_Enemie);
}

void EnemieS::Move(sf::Sprite &a_Player)
{
    sf::Vector2f posPlayer = a_Player.getPosition();
    sf::Vector2f posEnemie = m_Enemie.getPosition();

    sf::Vector2f posDiff = posPlayer - posEnemie;
    posDiff.y += 30;

    float angle = (float)atan2(posDiff.y, posDiff.x) * Mathf::RAD2DEG;

    m_Enemie.move(0.4f * cos(angle * Mathf::DEG2RAD), 0.4f * sin(angle * Mathf::DEG2RAD));

    m_Enemie.rotate(0.2f);
    m_cmpt++;
    for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
        it->Move();
        Hit(a_Player);
    }
}

void EnemieS::Finish()
{
    m_bAnimOver = true;
    m_iFrameIndex = m_PosFrame.size()-1;
    m_Enemie.setTextureRect(m_PosFrame[m_iFrameIndex]);
}

void EnemieS::Death()
{
    if(!m_bUsable){
        return;
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
