#include "include/GUI/Widget/WGTexture.hpp"

WGTexture::WGTexture(const sf::FloatRect &a_Pos, const std::string &a_sTextureName)
{
    m_sTextureName = a_sTextureName;
    m_Texture = ResourcesSingleton::Get().GetTexture(m_sTextureName);
    m_Sprite.setTexture(m_Texture);
    SetRect(a_Pos.left, a_Pos.top, a_Pos.width, a_Pos.height);
}

WGTexture::~WGTexture()
{
    ResourcesSingleton::Get().RemoveTexture(m_sTextureName);
}

void WGTexture::Draw(sf::RenderWindow &a_Window)
{
    a_Window.draw(m_Sprite);
}

bool WGTexture::Control(sf::Event &a_Event __attribute__((unused)))
{
    return false;
}

bool WGTexture::Clicked(sf::Vector2i a_MousePos __attribute__((unused)))
{
    return false;
}

void WGTexture::SetRect(float a_fLeft, float a_fTop, float a_fWidth, float a_fHeight)
{
    Widget::SetRect(a_fLeft, a_fTop, a_fWidth, a_fHeight);
    m_Sprite.setPosition(m_Position.left, m_Position.top);
    m_Sprite.setScale(m_Position.width / m_Sprite.getLocalBounds().width, m_Position.height / m_Sprite.getLocalBounds().height);
}
