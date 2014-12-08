#include "include/Manager/StateManager.hpp"

StateManager::StateManager() :
    m_stateStack()
{

}

StateManager::~StateManager()
{
    Clear();
}

std::shared_ptr<State> StateManager::GetState()
{
    return ((m_stateStack.empty()) ? nullptr : m_stateStack.top());
}

void StateManager::PushState(State *a_state)
{
    std::shared_ptr<State> t_state(a_state);
    t_state->SetManager(this);
    if(!m_stateStack.empty()){
        m_stateStack.top()->Pause();
    }
    t_state->Init();
    m_stateStack.push(t_state);
}

void StateManager::SetState(State *a_state)
{
    PopState();
    PushState(a_state);
}

void StateManager::PopState()
{
    if(!m_stateStack.empty()){
        m_stateStack.top()->Free();
        m_stateStack.pop();
    }
    if(!m_stateStack.empty()){
        m_stateStack.top()->UnPause();
    }
}

void StateManager::Clear()
{
    while(!m_stateStack.empty()){
        PopState();
    }
}

