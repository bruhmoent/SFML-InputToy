#include "input_manager.hpp"

InputManager::InputManager()
    : m_input_unifier(std::make_unique<InputUnifier>(
        std::make_unique<KeyboardManager>(),
        std::make_unique<ControllerManager>()
        )) {}

bool InputManager::is_action_activated(Action action) {
    return m_input_unifier->is_action_activated(action);
}

bool InputManager::is_action_released(Action action) {
    return m_input_unifier->is_action_released(action);
}