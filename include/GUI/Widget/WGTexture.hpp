#ifndef WGTEXTURE
#define WGTEXTURE

#include "include/GUI/Widget/Widget.hpp"
#include "include/ResourcesSingleton.hpp"

class WGTexture : public Widget
{
public:
    WGTexture(const sf::FloatRect &a_Pos, const std::string &a_sTextureName);
    ~WGTexture();

    void Draw(sf::RenderWindow &a_Window) override;
    bool Control(sf::Event &a_Event ) override;
    bool Clicked(sf::Vector2i a_MousePos) override;
    void SetRect(float a_fLeft, float a_fTop, float a_fWidth, float a_fHeight);

private:
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
    std::string m_sTextureName;
};

#endif
