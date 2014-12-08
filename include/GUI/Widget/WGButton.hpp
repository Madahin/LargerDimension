#ifndef WGBUTTON
#define WGBUTTON

#include <SFML/Graphics.hpp>
#include "include/Tools/auto_Texture.hpp"

#include "include/GUI/Widget/Widget.hpp"
#include "include/ResourcesSingleton.hpp"

class WGButton : public Widget
{
public:
    WGButton(const sf::FloatRect &a_Pos, const std::string &a_sName, const std::string &a_sTextureName);
    ~WGButton();

    void Draw(sf::RenderWindow &a_Window) override;
    bool Control(sf::Event &a_Event) override;
    bool Clicked(sf::Vector2i a_MousePos) override;

    void SetRect(float a_fLeft, float a_fTop, float a_fWidth, float a_fHeight);
    void SetName(const std::string& a_sName);

private:
    void CenterName();

private:
    sf::Sprite m_Button;
    autoTexture m_Texture;
    sf::Text m_ButtonName;
};

#endif
