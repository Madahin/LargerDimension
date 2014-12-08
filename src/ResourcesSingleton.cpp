#include "include/ResourcesSingleton.hpp"

ResourcesSingleton::ResourcesSingleton() :
    m_TextureCache(),
    m_FontCache()
{

}

ResourcesSingleton::~ResourcesSingleton()
{

}

ResourcesSingleton& ResourcesSingleton::Get()
{
    static ResourcesSingleton t_Instance;
    return t_Instance;
}

sf::Font& ResourcesSingleton::GetFont(const std::string &a_sName)
{
    if(m_FontCache.find(a_sName) == m_FontCache.end()){
        sf::Font t_TmpFont;
        if(!t_TmpFont.loadFromFile(a_sName)){
            throw std::invalid_argument(a_sName);
        }
        unsigned int t_iUsed = 0;
        m_FontCache[a_sName] = std::make_pair(t_TmpFont, t_iUsed);
    }
    m_FontCache.at(a_sName).second += 1;
    return m_FontCache.at(a_sName).first;
}

autoTexture& ResourcesSingleton::GetTexture(const std::string &a_sName)
{
    if(m_TextureCache.find(a_sName) == m_TextureCache.end()){
        std::shared_ptr<autoTexture> t_TmpTexture;
        if(!t_TmpTexture->loadFromFile(a_sName)){
            sf::Image t_ErrorImg;
            t_ErrorImg.create(50, 50, sf::Color::Magenta);
            t_TmpTexture->loadFromImage(t_ErrorImg);
            std::cerr << "Error : Unable to load " << a_sName << std::endl;
        }
        unsigned int t_iUsed = 0;
        m_TextureCache[a_sName] = std::make_pair(t_TmpTexture, t_iUsed);
    }
    m_TextureCache.at(a_sName).second += 1;
    return (*m_TextureCache.at(a_sName).first);
}

void ResourcesSingleton::RemoveTexture(const std::string &a_sName)
{
    auto it = m_TextureCache.find(a_sName);
    if(it != m_TextureCache.end()){
        m_TextureCache.at(a_sName).second -= 1;
        if(m_TextureCache.at(a_sName).second == 0){
            m_TextureCache.erase(it);
        }
    }
}

void ResourcesSingleton::RemoveFont(const std::string &a_sName)
{
    auto it = m_FontCache.find(a_sName);
    if(it != m_FontCache.end()){
        m_FontCache.at(a_sName).second -= 1;
        if(m_FontCache.at(a_sName).second == 0){
            m_FontCache.erase(it);
        }
    }
}
