#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "include/GameState/State.hpp"
#include "include/Star.hpp"

#include <iostream>
#include <vector>
#include <random>

#define STARS_NUMBER 300

class Background : public State
{
public:
    Background();

    void Init() override;
    void Free() override;
    void Draw(sf::RenderWindow &a_window) override;
    void Event() override;
    void Update() override;
    void Pause() override;
    void UnPause() override;

private:
    float Rand();
    void InitStar(Star& a_star);

private:
    sf::Texture m_StarTexture;
    std::vector<Star> m_Stars;

    std::random_device m_RandDevice;
    std::mt19937 m_Generator;
    std::uniform_real_distribution<> m_Distributor;
};

#endif // STATEINGAME_HPP
