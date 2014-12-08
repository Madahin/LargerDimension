#include "include/Tools/Converter.hpp"

sf::Vector2f Converter::From2DToISO(float a_PosX, float a_PosY)
{
    sf::Vector2f t_posTmp(0,0);

    t_posTmp.x = a_PosX - a_PosY;
    t_posTmp.y = (a_PosX + a_PosY) * 0.5f;

    return t_posTmp;
}

sf::Vector2f Converter::From2DToISO(const sf::Vector2f &a_Pos)
{
    return From2DToISO(a_Pos.x, a_Pos.y);
}

sf::Vector2f Converter::FromISOTo2D(float a_PosX, float a_PosY)
{
    sf::Vector2f t_posTmp(0,0);

    t_posTmp.x = (2 * a_PosY + a_PosX) * 0.5f;
    t_posTmp.y = (2 * a_PosY - a_PosX) * 0.5f;

    return t_posTmp;
}

sf::Vector2f Converter::FromISOTo2D(const sf::Vector2f &a_Pos)
{
    return From2DToISO(a_Pos.x, a_Pos.y);
}
