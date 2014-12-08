#include "include/Enemie/EnemieL.hpp"

EnemieL::EnemieL(sf::Texture &a_tileset) :
    Enemie::Enemie(a_tileset)
{
    for(int i=0; i < 7; i++){
        sf::IntRect pos(i*78, 3*72, 78, 72);
        m_PosFrame.push_back(pos);
    }
    m_Enemie.setTexture(a_tileset);
    m_Enemie.setPosition(320, -36);
    m_Enemie.setTextureRect(m_PosFrame[0]);
}

void EnemieL::Anim()
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

void EnemieL::Fire()
{
    if(!m_bUsable){
        return;
    }
    if(m_ClockFire.getElapsedTime().asMilliseconds() >= 3000){
        bool ok = true;
        for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
            if(it->IsOut()){
                it->SetPos(m_Enemie.getPosition().x, m_Enemie.getPosition().y);
                it->Revive();
                ok = false;
                break;
            }
        }
        if(ok) m_TirList.push_back(Tir(m_Tileset, 7, 3, 3, 0.7f, Mathf::PI * 0.5, m_Enemie.getPosition().x, m_Enemie.getPosition().y));
        m_ClockFire.restart();
    }
}

void EnemieL::Draw(sf::RenderWindow &a_window)
{
    for(Tir &tir : m_TirList){
        tir.Draw(a_window);
    }
    a_window.draw(m_Enemie);
}

void EnemieL::Move(sf::Sprite &a_Player)
{
    m_Enemie.move(0, 0.2f);
    for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
        it->Move();
        Hit(a_Player);
    }
}

void EnemieL::Finish()
{
    m_bAnimOver = true;
    m_iFrameIndex = m_PosFrame.size()-1;
    m_Enemie.setTextureRect(m_PosFrame[m_iFrameIndex]);
}

void EnemieL::Death()
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
