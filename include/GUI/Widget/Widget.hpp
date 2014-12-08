#ifndef WIDGET
#define WIDGET

#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>

class Widget
{
public:
    Widget();

    virtual void Draw(sf::RenderWindow &a_Window)=0;
    virtual bool Control(sf::Event &a_Event)=0;
    virtual bool Clicked(sf::Vector2i a_MousePos)=0;
    void SetRect(float a_fLeft, float a_fTop, float a_fWidth, float a_fHeight);
    void AddOnClickUpBehavior(std::function<void(int)> a_Func);
    void AddOnClickDownBehavior(std::function<void(int)> a_Func);
    bool HasUpBehavior();
    bool HasDownBehavior();
    void UpBehavior(int a_iID);
    void DownBehavior(int a_iID);
    sf::FloatRect& GetRect();

protected:
    sf::FloatRect m_Position;
    std::vector<std::function<void(int)>> m_OnClicUp;
    std::vector<std::function<void(int)>> m_OnClicDown;
};

#endif
