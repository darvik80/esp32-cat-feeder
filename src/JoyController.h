//
// Created by Ivan Kishchenko on 24.04.2022.
//


#pragma once

#include "service/Service.h"

LOG_COMPONENT_SETUP(joy)

#include "esp_adc_cal.h"

class JoyController: public Service {
public:
    explicit JoyController(IRegistry *registry);

    [[nodiscard]] ServiceId getServiceId() const override;

    void setup() override;

    void loop() override;
};
