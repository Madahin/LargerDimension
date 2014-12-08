#include "include/Tools/auto_Texture.hpp"

autoTexture::autoTexture() :
    sf::Texture(),
    m_TexName("error")
{

}

autoTexture::~autoTexture()
{
    ResourcesSingleton::Get().RemoveTexture(m_TexName);
}

bool autoTexture::loadFromFile(const std::string &filename, const sf::IntRect &area)
{
    bool ok = sf::Texture::loadFromFile(filename, area);
    if(ok){
        m_TexName = filename;
    }
    return ok;
}

bool autoTexture::loadFromImage(const sf::Image &image, const sf::IntRect &area)
{
    bool ok = sf::Texture::loadFromImage(image, area);
    if(ok){
        m_TexName = "error";
    }
    return ok;
}
