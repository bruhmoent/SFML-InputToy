#include "directives.hpp"
#include "action_dict.hpp"
#include "keyboard_manager.hpp"
#include "controller_manager.hpp"

#ifndef INPUT_UNIFIER_HPP
#define INPUT_UNIFIER_HPP

class InputUnifier
{
public:
	InputUnifier(std::unique_ptr<KeyboardManager> keyboard_manager, std::unique_ptr<ControllerManager> controller_manager);

	bool is_action_activated(Action action);
	bool is_action_released(Action action);
private:
	std::unique_ptr<KeyboardManager> m_keyboard_manager;
	std::unique_ptr<ControllerManager> m_controller_manager;
};

#endif // !CONTROLLER_MANAGER_HPP