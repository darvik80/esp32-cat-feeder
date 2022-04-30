#include "service/Application.h"
#include "ServoMotor.h"
#include "JoyController.h"
#include <Arduino.h>

class CatFeederApp : public Application {
public:
    CatFeederApp()
            : Application(logging::level::info, new TMessageBus<10>()) {

    }

    void setup() override {
        getRegistry()->create<ServoMotor>();
        getRegistry()->create<JoyController>();
        Application::setup();
    }
};

CatFeederApp app;

void setup() {
    // put your setup code here, to run once:
    app.setup();
}

void loop() {
    // put your main code here, to run repeatedly:
    app.loop();
    delay(100);
}