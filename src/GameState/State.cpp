#include "include/GameState/State.hpp"

State::State() :
    m_manager(nullptr)
{

}

State::~State()
{
    if(m_manager != nullptr){
        m_manager = nullptr;
    }
}

void State::SetManager(StateManager *a_manager)
{
    m_manager = a_manager;
}
