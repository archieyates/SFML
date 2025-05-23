////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2025 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/JoystickManager.hpp>

#include <cassert>


namespace sf::Joystick
{
////////////////////////////////////////////////////////////
bool isConnected(unsigned int joystick)
{
    return priv::JoystickManager::getInstance().getState(joystick).connected;
}


////////////////////////////////////////////////////////////
unsigned int getButtonCount(unsigned int joystick)
{
    return priv::JoystickManager::getInstance().getCapabilities(joystick).buttonCount;
}


////////////////////////////////////////////////////////////
bool hasAxis(unsigned int joystick, Axis axis)
{
    return priv::JoystickManager::getInstance().getCapabilities(joystick).axes[axis];
}


////////////////////////////////////////////////////////////
bool isButtonPressed(unsigned int joystick, unsigned int button)
{
    assert(button < Joystick::ButtonCount && "Button must be less than Joystick::ButtonCount");
    return priv::JoystickManager::getInstance().getState(joystick).buttons[button];
}


////////////////////////////////////////////////////////////
float getAxisPosition(unsigned int joystick, Axis axis)
{
    return priv::JoystickManager::getInstance().getState(joystick).axes[axis];
}


////////////////////////////////////////////////////////////
Identification getIdentification(unsigned int joystick)
{
    return priv::JoystickManager::getInstance().getIdentification(joystick);
}

////////////////////////////////////////////////////////////
JoystickCaps getCapabilities(unsigned int joystick)
{
    return priv::JoystickManager::getInstance().getCapabilities(joystick);
}

////////////////////////////////////////////////////////////
JoystickState getState(unsigned int joystick)
{
    return priv::JoystickManager::getInstance().getState(joystick);
}

////////////////////////////////////////////////////////////
void update()
{
    priv::JoystickManager::getInstance().update();
}

} // namespace sf::Joystick
