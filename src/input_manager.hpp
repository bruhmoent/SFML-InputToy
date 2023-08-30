#include "directives.hpp"
#include "input_unifier.hpp"

#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

class InputUnifier;
class KeyboardManager;

class InputManager
{
public:
    InputManager();
    std::unique_ptr<InputUnifier> m_input_unifier;

    bool is_action_activated(Action action);
    bool is_action_released(Action action);
};

#endif // !INPUT_MANAGER_HPP
