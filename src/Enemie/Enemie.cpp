#include "include/Enemie/Enemie.hpp"

Enemie::Enemie(sf::Texture &a_Tileset) :
    m_bAnimOver(false),
    m_Tileset(a_Tileset),
    m_iFrameIndex(0),
    m_bUsable(true)
{

}

void Enemie::SetPos(float a_X, float a_Y)
{
    m_Enemie.setPosition(a_X, a_Y);
}

void Enemie::MoveBack()
{
    m_Enemie.move(0, -1);
}

sf::Sprite& Enemie::GetSprite()
{
    return m_Enemie;
}

bool Enemie::IsUsable()
{
    return m_bUsable;
}

void Enemie::Hit(sf::Sprite &a_Player)
{
    for(auto it = m_TirList.begin(); it != m_TirList.end(); it++){
        if(Mathf::IsPlayerTouched(a_Player, it->GetSprite())){//it->IsUsable() && it->GetSprite().getGlobalBounds().intersects(a_Player.getGlobalBounds())){
            if(it->IsUsable()){
                PlayerManager::Get().LostPV();
            }
            it->Destroy();
        }
    }
}
