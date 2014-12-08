#include "include/Manager/PlayerManager.hpp"

PlayerManager::PlayerManager() :
    Over(false),
    CanChange(false),
    Restart(false),
	IsInvincible(false),
    m_PV(PV)
{
    m_Buffer.loadFromFile("Ressources/SFX/hit.wav");
    m_HitSound.setBuffer(m_Buffer);
}

PlayerManager::~PlayerManager()
{

}

PlayerManager& PlayerManager::Get()
{
    static PlayerManager t_Instance;
    return t_Instance;
}

void PlayerManager::LostPV()
{
    if(!IsInvincible)m_PV--;
    if(m_HitSound.getStatus() != sf::Sound::Status::Playing){
        m_HitSound.play();
    }
    if(m_PV == 0){
        Over = true;
        m_PV = PV;
    }
}

void PlayerManager::FullLife()
{
    m_PV = PV;
}
