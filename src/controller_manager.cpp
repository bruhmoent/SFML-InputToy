#include "controller_manager.hpp"

const float S_AXIS_THRESHOLD = 30.0f;

ControllerManager::ControllerManager() : m_axis_map(), m_button_map() {
    bind_axis_to_action(1, sf::Joystick::X, Action::LEFT, Action::RIGHT);
    bind_axis_to_action(1, sf::Joystick::Y, Action::UP, Action::DOWN);
    bind_button_to_action(1, Button::JOY_KEY_A, Action::JUMP);
}

void ControllerManager::bind_axis_to_action(unsigned int c_index, sf::Joystick::Axis axis, Action negative_action, Action positive_action) {
    m_axis_map[c_index][axis] = std::make_pair(negative_action, positive_action);
}

void ControllerManager::bind_button_to_action(unsigned int c_index, Button button, Action action) {
    m_button_map[c_index][button] = action;
}

bool ControllerManager::is_action_activated(Action action, unsigned int c_index) {
    if (sf::Joystick::isConnected(c_index)) {
        sf::Joystick::update();

        for (const auto& button_pair : m_button_map[c_index]) {
            if (button_pair.second == action && sf::Joystick::isButtonPressed(c_index, button_pair.first) && !m_button_state_map[button_pair.first]) {
                m_button_state_map[button_pair.first] = true;
                return true;
            }
            else if (!sf::Joystick::isButtonPressed(c_index, button_pair.first)) {
                m_button_state_map[button_pair.first] = false;
            }
        }

        if (m_axis_map.find(c_index) != m_axis_map.end()) {
            for (const auto& axisPair : m_axis_map[c_index]) {
                const auto& actions = axisPair.second;
                float axisPosition = sf::Joystick::getAxisPosition(c_index, axisPair.first);
                if (actions.first == action && axisPosition < -S_AXIS_THRESHOLD) {
                    return true;
                }
                if (actions.second == action && axisPosition > S_AXIS_THRESHOLD) {
                    return true;
                }
            }
        }
    }
    else {
        std::cerr << "Controller not detected.\n";
    }

    return false;
}

bool ControllerManager::is_action_released(Action action, unsigned int c_index) {
    if (sf::Joystick::isConnected(c_index)) {
        sf::Joystick::update();

        for (const auto& button_pair : m_button_map[c_index]) {
            if (button_pair.second == action && !sf::Joystick::isButtonPressed(c_index, button_pair.first) && m_button_state_map[button_pair.first]) {
                m_button_state_map[button_pair.first] = false;
                return true;
            }
            else if (sf::Joystick::isButtonPressed(c_index, button_pair.first)) {
                m_button_state_map[button_pair.first] = true;
            }
        }

        if (m_axis_map.find(c_index) != m_axis_map.end()) {
            for (const auto& axisPair : m_axis_map[c_index]) {
                const auto& actions = axisPair.second;
                float axisPosition = sf::Joystick::getAxisPosition(c_index, axisPair.first);
                if (actions.first == action && axisPosition >= -S_AXIS_THRESHOLD) {
                    return false;
                }
                if (actions.second == action && axisPosition <= S_AXIS_THRESHOLD) {
                    return false;
                }
            }
        }
    }
    else {
        std::cerr << "Controller not detected.\n";
    }

    return false;
}