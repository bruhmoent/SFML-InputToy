#include "directives.hpp"
#include "action_dict.hpp"

#ifndef CONTROLLER_MANAGER_HPP
#define CONTROLLER_MANAGER_HPP

// NOTE: Example XBOX definition, not sure how to tackle global definitions.
enum Button {
    JOY_KEY_A = 0,  // A button
    JOY_KEY_B = 1,  // B button
    JOY_KEY_X = 2,  // X button
    JOY_KEY_Y = 3,  // Y button
    JOY_KEY_LB = 4,  // Left bumper
    JOY_KEY_RB = 5,  // Right bumper
    JOY_KEY_BACK = 6,  // Back button
    JOY_KEY_START = 7,  // Start button
    JOY_KEY_LEFT_STICK = 8, // Left stick button
    JOY_KEY_RIGHT_STICK = 9 // Right stick button
};

class ControllerManager
{
public:
    ControllerManager();

    void bind_axis_to_action(unsigned int c_index, sf::Joystick::Axis axis, Action negative_action, Action positive_action);
    void bind_button_to_action(unsigned int c_index, Button button, Action action);

    bool is_action_activated(Action action, unsigned int c_index);
    bool is_action_released(Action action, unsigned int c_index);

private:
    std::map<unsigned int, std::map<sf::Joystick::Axis, std::pair<Action, Action>>> m_axis_map;
    std::map<unsigned int, std::map<Button, Action>> m_button_map;
    std::map <Button, bool> m_button_state_map;
};

#endif // !CONTROLLER_MANAGER_HPP
