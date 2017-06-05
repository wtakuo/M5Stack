// Copyright (c) M5Stack. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef _M5STACK_H_
#define _M5STACK_H_

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiMulti.h>
#include <Wire.h>
#include "FS.h"
#include "SD.h"
#include "utility/display.h"
#include "utility/bmp_map.h"
#include "utility/bootmenu.h"
#include "utility/config.h"
// #include "utility/Buttons.h"
#include "utility/Button.h"
#include "esp32-hal-dac.h"

#ifdef ENABLE_DEBUG
#define M5PUTLOG(X)     Serial.printf(X)
#else
#define M5PUTLOG(X)
#endif

class M5Stack {
public:
    void begin();
    uint8_t bootSetup();
    void loop();

    //LED
    void ledOn();
    void ledOff();
    void ledTrig();

    // button API
    bool pressed(uint8_t button);
    bool released(uint8_t button);
    bool held(uint8_t button, uint8_t time);
    bool repeat(uint8_t button, uint8_t period);
    uint8_t timeHeld(uint8_t button);

    // Tone
    void tone(double freq);
    void noTone();
    #define TONE_PIN_CHANNEL   0

    M5STACK_TFTLCD lcd;
    #define DEBOUNCE_MS 20
    #define PULLUP true
    #define INVERT true
    Button buttonA = Button(BUTTON_A_PIN, PULLUP, INVERT, DEBOUNCE_MS);    //Declare the button
    Button buttonB = Button(BUTTON_B_PIN, PULLUP, INVERT, DEBOUNCE_MS);
    Button buttonC = Button(BUTTON_C_PIN, PULLUP, INVERT, DEBOUNCE_MS);

private:
    uint8_t btn_pins[NUM_BTN];
    uint8_t btn_states[NUM_BTN];
};

extern M5Stack m5stack;
#define m5  m5stack
#define M5  m5stack

#endif
