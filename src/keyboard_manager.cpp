#include "keyboard_manager.hpp"

KeyboardManager::KeyboardManager() : m_keymap()
{
	// Default mappings.
	m_keymap[sf::Keyboard::Left] = Action::LEFT;
	m_keymap[sf::Keyboard::Right] = Action::RIGHT;
	m_keymap[sf::Keyboard::Up] = Action::UP;
	m_keymap[sf::Keyboard::Down] = Action::DOWN;
   	m_keymap[sf::Keyboard::Space] = Action::JUMP;
}

bool KeyboardManager::is_action_activated(Action& action)
{
    for (const auto& pair : m_keymap)
    {
        if (pair.second == action && sf::Keyboard::isKeyPressed(pair.first) && !m_key_state_map[pair.first])
        {
            m_key_state_map[pair.first] = true;
            return true;
        }
        else if (!sf::Keyboard::isKeyPressed(pair.first))
        {
            m_key_state_map[pair.first] = false;
        }
    }
    return false;
}

bool KeyboardManager::is_action_released(Action& action)
{
    for (const auto& pair : m_keymap)
    {
        if (pair.second == action && !sf::Keyboard::isKeyPressed(pair.first) && m_key_state_map[pair.first])
        {
            m_key_state_map[pair.first] = false;
            return true;
        }
        else if (sf::Keyboard::isKeyPressed(pair.first))
        {
            m_key_state_map[pair.first] = true;
        }
    }
    return false;
}

void KeyboardManager::bind_key(sf::Keyboard::Key key, Action action)
{
	// Cleanse previous mappings.
	auto k = m_keymap.find(key);
	if (k != m_keymap.end())
		m_keymap.erase(k);

	m_keymap[key] = action;
}
