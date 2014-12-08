#ifndef AUTO_TEXTURE
#define AUTO_TEXTURE

#include <SFML/Graphics/Texture.hpp>
#include "include/ResourcesSingleton.hpp"

class ResourcesSingleton;

class autoTexture : public sf::Texture
{
public:
    autoTexture();
    ~autoTexture();

    bool loadFromFile(const std::string &filename, const sf::IntRect &area=sf::IntRect());
    bool loadFromImage(const sf::Image &image, const sf::IntRect &area=sf::IntRect());

private:
    std::string m_TexName;
};

#endif
