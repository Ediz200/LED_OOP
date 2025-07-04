#include "led.h"

Led::Led(uint16_t port, uint16_t pin)
    : led_pin(port, pin) {
    led_pin.set_direction_output();
    off();
}

void Led::on() {
    led_pin.set_pin_high();  // Active-low, turn on the pin to turn the LED on
}

void Led::off() {
    led_pin.set_pin_low();  // Active-low, turn off the pin to turn the LED off
}

void Led::toggle() {
    led_pin.toggle();  // Toggle the pin to change the LED state
}

bool Led::is_on() const {
    return led_pin.get_pin_value();
}
