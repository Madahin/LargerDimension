#include "include/Enemie/EnemieE.hpp"

EnemieE::EnemieE(sf::Texture &a_tileset) :
    Enemie::Enemie(a_tileset)
{
    for(int i=0; i < 7; i++){
        sf::IntRect pos(i*78, 6*72, 78, 72);
        m_PosFrame.push_back(pos);
    }
    m_Enemie.setTexture(a_tileset);
    m_Enemie.setPosition(320, -36);
    m_Enemie.setTextureRect(m_PosFrame[0]);
}

void EnemieE::Anim()
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

void EnemieE::Fire()
{
    if(!m_bUsable){
        return;
    }
    if(m_ClockFire.getElapsedTime().asMilliseconds() >= 1000){
        m_TirList.push_back(Tir(m_Tileset, 11, 4, 1, 1, Mathf::PI * 0.5, m_Enemie.getPosition().x, m_Enemie.getPosition().y));
        m_TirList.push_back(Tir(m_Tileset, 11, 4, 1, 1, 2*Mathf::PI /3, m_Enemie.getPosition().x, m_Enemie.getPosition().y));
        m_TirList.push_back(Tir(m_Tileset, 11, 4, 1, 1, Mathf::PI /3, m_Enemie.getPosition().x, m_Enemie.getPosition().y));
        m_ClockFire.restart();
    }
}

void EnemieE::Draw(sf::RenderWindow &a_window)
{
    for(Tir &tir : m_TirList){
        tir.Draw(a_window);
    }
    a_window.draw(m_Enemie);
}

void EnemieE::Move(sf::Sprite &a_Player)
{
    m_Enemie.move(0, 0.2f);
    for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
        it->Move();
        Hit(a_Player);
    }
}

void EnemieE::Finish()
{
    m_bAnimOver = true;
    m_iFrameIndex = m_PosFrame.size()-1;
    m_Enemie.setTextureRect(m_PosFrame[m_iFrameIndex]);
}

void EnemieE::Death()
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

