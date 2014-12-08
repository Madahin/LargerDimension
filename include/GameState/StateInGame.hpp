#ifndef STATEINGAME_HPP
#define STATEINGAME_HPP

#include "include/GameState/State.hpp"
#include "include/Manager/InputManager.hpp"
#include "include/Tir/Tir.hpp"
#include "include/Enemie/EnemieAll.hpp"
#include "include/Tools/Mathf.hpp"

#include <SFML/Audio.hpp>

#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

#define BUP 0
#define BDOWN 1
#define BLEFT 2
#define BRIGHT 3

struct EnemiesData{
    float waveTime;
    char type;
    int posX;
};

class StateInGame : public State
{
public:
    StateInGame();

    void Init() override;
    void Free() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Event() override;
    void Update() override;
    void Pause() override;
    void UnPause() override;
    void GenerateEnemies();
    bool AllDeadOrFleeing();

private:
    std::vector<EnemiesData> m_WaveData;
    int m_IndexData;
    sf::Clock m_Time;
    std::array<bool, 4> m_bMovement;
    bool m_PlayerShot;
    sf::Clock m_Clock;
    sf::Texture m_TileSet;
    sf::Sprite m_Player;
    std::vector<Tir> m_Tir;
    sf::Clock m_clockShot;
    std::vector<std::shared_ptr<Enemie>> m_EnemieList;
    sf::SoundBuffer m_boomBuffer;
    sf::Sound m_BoomSound;
    sf::Clock m_AnimDeath;
    unsigned short m_iIndexDeath;
};

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

#endif // STATEINGAME_HPP
