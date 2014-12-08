#ifndef STATE
#define STATE

#include <SFML/Graphics.hpp>
#include "include/Manager/StateManager.hpp"

class StateManager;

class State
{
public:
    State();
    ~State();

    virtual void Init() = 0;
    virtual void Free() = 0;
    virtual void Draw(sf::RenderWindow &a_window) = 0;
    virtual void Event() = 0;
    virtual void Update() = 0;
    virtual void Pause() = 0;
    virtual void UnPause() = 0;

    void SetManager(StateManager* a_manager);

protected:
    StateManager* m_manager;
};

#endif
