//
// Created by Ivan Kishchenko on 24.04.2022.
//


#pragma once

#include "service/Service.h"
#include "UserMessage.h"
#include <ESP32Servo.h>

LOG_COMPONENT_SETUP(servo)

class ServoMotor : public Service, public TMessageSubscriber<ServoMotor, JoyEvent> {
    Servo _dev;
public:
    explicit ServoMotor(IRegistry *registry);

    [[nodiscard]] ServiceId getServiceId() const override;

    void loop() override;

    void setup() override;

    void onMessage(const JoyEvent &msg);
};
