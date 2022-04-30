//
// Created by Ivan Kishchenko on 12.03.2022.
//

#ifndef SMART_HOME_ESP32_USERMESSAGE_H
#define SMART_HOME_ESP32_USERMESSAGE_H

#include <service/ServiceMessage.h>
#include "service/LibServiceId.h"

enum UserMessageId {
    JOY = USER_EVENT
};

enum UserServiceId {
    SERVO_MOTOR = USER_SERVICES,
    JOY_CTL,
};

struct JoyEvent : TMessage<JOY> {
    JoyEvent(int x, int y) : x(x), y(y) {}

    int x;
    int y;
};

#endif //SMART_HOME_ESP32_USERMESSAGE_H
