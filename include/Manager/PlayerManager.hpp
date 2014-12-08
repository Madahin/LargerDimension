#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#define PV 7

class PlayerManager
{
public:
    static PlayerManager& Get();
    void LostPV();
    void FullLife();
    bool Over;
    bool CanChange;
    bool Restart;
	bool IsInvincible;

private:
    PlayerManager();
    ~PlayerManager();
	
    unsigned short m_PV;
    sf::SoundBuffer m_Buffer;
    sf::Sound m_HitSound;

};

#endif
