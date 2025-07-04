/*
 * RGB_led.h
 *
 *  Created on: Jun 23, 2023
 *      Author: edizt
 */

#ifndef RGB_LED_H
#define RGB_LED_H

#include "led.h"
#include "led_interface.h"

class RGB_led : public Led_interface {
public:
    enum Color { Blue = 1, Green, Cyan, Red, Magenta, Yellow, White };

    RGB_led(uint16_t red_port, uint16_t red_pin,
            uint16_t green_port, uint16_t green_pin,
            uint16_t blue_port, uint16_t blue_pin);

    void on() override;
    void off() override;
    void toggle() override;
    void set_color (Color c);

private:
    Led red_led;
    Led green_led;
    Led blue_led;
    Color last_color;
};

#endif  // RGB_LED_H


