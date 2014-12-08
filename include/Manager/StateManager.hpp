#ifndef STATEMANAGER
#define STATEMANAGER

#include <memory>
#include <stack>
#include "include/GameState/State.hpp"

class State;

class StateManager
{
public:
    StateManager();
    ~StateManager();

    std::shared_ptr<State> GetState();
    void PushState(State* a_state);
    void SetState(State* a_state);
    void PopState();
    void Clear();

private:
    std::stack<std::shared_ptr<State>> m_stateStack;
};

#endif
