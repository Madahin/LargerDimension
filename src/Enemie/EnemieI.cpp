#include "include/Enemie/EnemieI.hpp"

EnemieI::EnemieI(sf::Texture &a_tileset) :
    Enemie::Enemie(a_tileset)
{
    for(int i=0; i < 10; i++){
        sf::IntRect pos(i*78, 5*72, 78, 72);
        m_PosFrame.push_back(pos);
    }
    m_Enemie.setTexture(a_tileset);
    m_Enemie.setPosition(320, -36);
    m_Enemie.setTextureRect(m_PosFrame[0]);
}

void EnemieI::Anim()
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

void EnemieI::Fire()
{
    if(!m_bUsable){
        return;
    }
    if(m_ClockFire.getElapsedTime().asMilliseconds() >= 1000){
        bool ok = true;
        for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
            if(it->IsOut()){
                it->SetPos(m_Enemie.getPosition().x, m_Enemie.getPosition().y);
                it->Revive();
                ok = false;
                break;
            }
        }
        if(ok) m_TirList.push_back(Tir(m_Tileset, 10, 5, 1, 1, Mathf::PI * 0.5, m_Enemie.getPosition().x, m_Enemie.getPosition().y));
        m_ClockFire.restart();
    }
}

void EnemieI::Draw(sf::RenderWindow &a_window)
{
    for(Tir &tir : m_TirList){
        tir.Draw(a_window);
    }
    a_window.draw(m_Enemie);
}

void EnemieI::Move(sf::Sprite &a_Player)
{
    m_Enemie.move(0, 0.2f);
    for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
        it->Move();
        Hit(a_Player);
    }
}

void EnemieI::Finish()
{
    m_bAnimOver = true;
    m_iFrameIndex = m_PosFrame.size()-1;
    m_Enemie.setTextureRect(m_PosFrame[m_iFrameIndex]);
}

void EnemieI::Death()
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


