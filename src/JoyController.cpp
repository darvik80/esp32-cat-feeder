//
// Created by Ivan Kishchenko on 24.04.2022.
//

#include "JoyController.h"
#include "UserMessage.h"

JoyController::JoyController(IRegistry *registry) : Service(registry) {}

ServiceId JoyController::getServiceId() const {
    return JOY_CTL;
}

void JoyController::setup() {
    adc1_config_width(ADC_WIDTH_BIT_12);
    Service::setup();
}

void JoyController::loop() {
    static int oldX{0}, oldY{0};
    int x = 0;
    if (adc2_get_raw(ADC2_CHANNEL_0, ADC_WIDTH_BIT_10, &x) == ESP_OK) {
        if (std::abs(x - oldX) > 16) {
            oldX = x;
            //joy::log::info("handle1: {}", x);
        }
    }
    int y = 0;
    if (adc2_get_raw(ADC2_CHANNEL_2, ADC_WIDTH_BIT_10, &y) == ESP_OK) {
        if (std::abs(y - oldY) > 16) {
            oldY = y;
            joy::log::info("handle1: {}", y);
        }
    }

    if (std::abs(x - oldX) > 16 || std::abs(y - oldY) > 16) {
        sendMessage(Service::getMessageBus(), JoyEvent{x, y});
    }
}
