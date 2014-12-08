#include "include/GUI/Widget/Widget.hpp"

Widget::Widget()
{

}

void Widget::SetRect(float a_fLeft, float a_fTop, float a_fWidth, float a_fHeight)
{
    m_Position = sf::FloatRect(a_fLeft, a_fTop, a_fWidth, a_fHeight);
}

void Widget::AddOnClickUpBehavior(std::function<void(int)> a_Func)
{
    m_OnClicUp.push_back(a_Func);
}

void Widget::AddOnClickDownBehavior(std::function<void(int)> a_Func)
{
    m_OnClicDown.push_back(a_Func);
}

bool Widget::HasUpBehavior()
{
    return m_OnClicUp.size() >= 1;
}

bool Widget::HasDownBehavior()
{
    return m_OnClicDown.size() >= 1;
}

void Widget::UpBehavior(int a_iID)
{
    for(auto &func : m_OnClicUp){
        func(a_iID);
    }
}

void Widget::DownBehavior(int a_iID)
{
    for(auto &func : m_OnClicDown){
        func(a_iID);
    }
}

sf::FloatRect& Widget::GetRect()
{
    return m_Position;
}
