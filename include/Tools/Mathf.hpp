#ifndef MATHF
#define MATHF

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace Mathf
{
    const float PI = 3.14159265359f;
    const float DEG2RAD = PI / 180.f;
    const float RAD2DEG = 180 / PI;

    bool Approx(float a_First, float a_Second);
    float PingPong(float a_Value, float a_Length);
    float Lerp(float a_First, float a_Second, float a_Delta);

    template<typename T>
    float Angle(const sf::Vector2<T> &a_Left, const sf::Vector2<T> &a_Right)
    {
        float t_fScalaire = a_Left.x * a_Right.x + a_Left.y * a_Right.y;
        float t_fLeftNorm = sqrt(a_Left.x * a_Left.x + a_Left.y * a_Left.y);
        float t_fRightNorm = sqrt(a_Right.x * a_Right.x + a_Right.y * a_Right.y);

        return acos(t_fScalaire / (t_fLeftNorm * t_fRightNorm));
    }

    bool IsPlayerTouched(const sf::Sprite &a_Player, const sf::Sprite &Thing);
}

#endif
