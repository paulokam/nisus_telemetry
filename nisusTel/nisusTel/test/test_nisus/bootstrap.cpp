#include <Arduino.h>
#include <gtest/gtest.h>

void setup() {
    Serial.begin(115200);
    delay(2000);

    testing::InitGoogleTest();
    if (!RUN_ALL_TESTS()){
        Serial.println("Tests Failures Ignored :PASS");
    } else {
        Serial.println("Tests Failures Ignored :FAIL");
    }
}

void loop() {

}
