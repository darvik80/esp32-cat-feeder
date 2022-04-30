//
// Created by Ivan Kishchenko on 24.04.2022.
//

#include "ServoMotor.h"
#include "UserMessage.h"

ServiceId ServoMotor::getServiceId() const {
    return SERVO_MOTOR;
}

ServoMotor::ServoMotor(IRegistry *registry) : Service(registry) {
}


void ServoMotor::setup() {
    getMessageBus()->subscribe(this);

    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    _dev.attach(12);
}

void ServoMotor::loop() {
}

void ServoMotor::onMessage(const JoyEvent &msg) {
    int y = 1024 - msg.y;
    auto val = map(y, 348, 1024, 0, 180);
    _dev.write(val);

    servo::log::info("route: {}", y);
}

