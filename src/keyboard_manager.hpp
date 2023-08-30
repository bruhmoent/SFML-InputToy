#include "directives.hpp"
#include "action_dict.hpp"

#ifndef KEYBOARD_MANAGER_HPP
#define KEYBOARD_MANAGER_HPP

class KeyboardManager
{
public:
	KeyboardManager();

	bool is_action_activated(Action& action);
	bool is_action_released(Action& action);

	void bind_key(sf::Keyboard::Key key, Action action);
private:
	std::map <sf::Keyboard::Key, Action> m_keymap;
	std::map <sf::Keyboard::Key, bool> m_key_state_map;
};

#endif // !KEYBOARD_MANAGER_HPP