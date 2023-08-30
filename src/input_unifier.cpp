#include "input_unifier.hpp"

InputUnifier::InputUnifier(std::unique_ptr<KeyboardManager> keyboard_manager, std::unique_ptr<ControllerManager> controller_manager)
	: m_keyboard_manager(std::move(keyboard_manager)), m_controller_manager(std::move(controller_manager))
{}

bool InputUnifier::is_action_activated(Action action)
{
    if (m_keyboard_manager->is_action_activated(action) || m_controller_manager->is_action_activated(action, 1))
        return true;
    return false;
}

bool InputUnifier::is_action_released(Action action)
{
    if (m_keyboard_manager->is_action_released(action) || m_controller_manager->is_action_released(action, 1))
        return true;
    return false;
}


/*
bool InputUnifier::is_action_activated(Action action)
{
    if (m_keyboard_manager->is_action_activated(action))
        return true;
    return false;
}

bool InputUnifier::is_action_released(Action action)
{
    if (m_keyboard_manager->is_action_released(action))
        return true;
    return false;
}
*/
/*
bool InputUnifier::is_action_activated(Action action)
{
    if (m_controller_manager->is_action_activated(action, 1))
        return true;
    return false;
}

bool InputUnifier::is_action_released(Action action)
{
    if (m_controller_manager->is_action_released(action, 1))
        return true;
    return false;
}
*/