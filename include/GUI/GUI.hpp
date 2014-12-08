#ifndef GUI_SYSTEM
#define GUI_SYSTEM

#include <vector>
#include <memory>
#include <utility>
#include <functional>
#include <exception>
#include <SFML/Graphics.hpp>

#include "include/GUI/Widget/Widget.hpp"
#include "include/Manager/InputManager.hpp"

class InputManager;

class GUI
{
public:
    GUI();
    virtual ~GUI();

    unsigned int AddWidget(std::shared_ptr<Widget> &a_Widget);
    void DelWidget(unsigned int a_WidgetID);
    std::shared_ptr<Widget> getWidget(unsigned int a_WidgetID);

    void DrawGUI(sf::RenderWindow &a_Window);
    bool ControlGUI(sf::Vector2i a_MousePos);

    void Toggle(bool a_bActive);

    void SetID(const unsigned int& a_iNewID);
    unsigned int GetID();

private:
    unsigned int ComputeNextID();


private:
    std::vector<std::pair<unsigned int,std::shared_ptr<Widget>>> m_WidgetList;
    bool m_bActivated;
    unsigned int m_ID;
};

bool operator ==(GUI& a_GUI_A, GUI& a_GUI_B);

#endif
