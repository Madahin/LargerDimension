#ifndef CONVERTER
#define CONVERTER

#include <SFML/System.hpp>

namespace Converter
{
    sf::Vector2f From2DToISO(float a_PosX, float a_PosY);

    sf::Vector2f From2DToISO(const sf::Vector2f &a_Pos);

    sf::Vector2f FromISOTo2D(float a_PosX, float a_PosY);

    sf::Vector2f FromISOTo2D(const sf::Vector2f &a_Pos);
}

#endif
