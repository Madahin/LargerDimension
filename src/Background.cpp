#include "include/Background.hpp"

Background::Background() :
    m_RandDevice(),
    m_Generator(m_RandDevice()),
    m_Distributor(0, 1)
{
    sf::Image t_StarImage;
    t_StarImage.create(2, 2, sf::Color::White);
    m_StarTexture.loadFromImage(t_StarImage);

    for(int i=0; i < STARS_NUMBER; i++){
        sf::Sprite t_StarSprite;
        t_StarSprite.setTexture(m_StarTexture);
        t_StarSprite.setPosition(Rand()*1024, Rand()*768);
        Star t_Star;
        t_Star.sprite = t_StarSprite;
        InitStar(t_Star);
        m_Stars.push_back(t_Star);
    }
}

void Background::Init()
{
}

void Background::Free()
{
}

void Background::Draw(sf::RenderWindow &a_window)
{
    for(Star &t_Star : m_Stars){
        //std::cout << t_Star.sprite.getPosition().x << std::endl;
        a_window.draw(t_Star.sprite);
    }
}

void Background::Event()
{
}

void Background::Update()
{
    for(Star &t_Star : m_Stars){
        t_Star.sprite.move(0, t_Star.speed);
        if(t_Star.sprite.getPosition().y > 768){
            t_Star.sprite.setPosition(Rand() * 1024, 0);
        }
    }
}

void Background::Pause()
{
}

void Background::UnPause()
{
}

float Background::Rand()
{
    return m_Distributor(m_Generator);
}

void Background::InitStar(Star &a_star)
{
    float scale = Rand() * 0.40f;
    a_star.sprite.setScale(1 + scale, 1 + scale);
    a_star.speed += a_star.speed * scale;
    sf::Color t_Color;
    t_Color.r = 255 - (Rand() * 55);
    t_Color.g = 255 - (Rand() * 55);
    t_Color.b = 255 - (Rand() * 55);
    a_star.sprite.setColor(t_Color);
}
