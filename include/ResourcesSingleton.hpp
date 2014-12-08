#ifndef RESOURCESSINGLETON
#define RESOURCESSINGLETON

#include <iostream>
#include <map>
#include <SFML/Graphics/Font.hpp>
#include <stdexcept>
#include <memory>
#include "include/Tools/auto_Texture.hpp"

class autoTexture;

class ResourcesSingleton
{
public:
    static ResourcesSingleton& Get();

    // Font cache
    void SetFont(const std::string &a_sName, const sf::Font &a_font);
    sf::Font& GetFont(const std::string &a_sName);

    // Texture cache
    void SetTexture(const std::string &a_sName, const sf::Texture &a_font);
    autoTexture& GetTexture(const std::string &a_sName);
    void RemoveTexture(const std::string &a_sName);
    void RemoveFont(const std::string &a_sName);

private:
    ResourcesSingleton();
    ~ResourcesSingleton();

private:
    std::map<std::string, std::pair<std::shared_ptr<autoTexture>, unsigned int>> m_TextureCache;
    std::map<std::string, std::pair<sf::Font, unsigned int>> m_FontCache;
};

#endif
