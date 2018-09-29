// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#include "TouchpadMacOS.hpp"
#include "InputSystemMacOS.hpp"

namespace ouzel
{
    namespace input
    {
        void TouchpadMacOS::handleTouchBegin(uint64_t touchId, const Vector2& position, float force)
        {
            InputSystem::Event event;
            event.type = InputSystem::Event::Type::TOUCH_BEGIN;
            event.deviceId = deviceId;
            event.touchId = touchId;
            event.position = position;
            event.force = force;
            inputSystemMacOS.addEvent(event);
        }

        void TouchpadMacOS::handleTouchEnd(uint64_t touchId, const Vector2& position, float force)
        {
            InputSystem::Event event;
            event.type = InputSystem::Event::Type::TOUCH_END;
            event.deviceId = deviceId;
            event.touchId = touchId;
            event.position = position;
            event.force = force;
            inputSystemMacOS.addEvent(event);
        }

        void TouchpadMacOS::handleTouchMove(uint64_t touchId, const Vector2& position, float force)
        {
            InputSystem::Event event;
            event.type = InputSystem::Event::Type::TOUCH_MOVE;
            event.deviceId = deviceId;
            event.touchId = touchId;
            event.position = position;
            event.force = force;
            inputSystemMacOS.addEvent(event);
        }

        void TouchpadMacOS::handleTouchCancel(uint64_t touchId, const Vector2& position, float force)
        {
            InputSystem::Event event;
            event.type = InputSystem::Event::Type::TOUCH_CANCEL;
            event.deviceId = deviceId;
            event.touchId = touchId;
            event.position = position;
            event.force = force;
            inputSystemMacOS.addEvent(event);
        }
    } // namespace input
} // namespace ouzel
