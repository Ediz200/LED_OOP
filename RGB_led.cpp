#include "RGB_led.h"

RGB_led::RGB_led(std::uint16_t red_port, std::uint16_t red_pin,
                 std::uint16_t green_port, std::uint16_t green_pin,
                 std::uint16_t blue_port, std::uint16_t blue_pin)
    : red_led(red_port, red_pin), green_led(green_port, green_pin), blue_led(blue_port, blue_pin),
      last_color(White) {}

void RGB_led::on() {
    red_led.on();
    green_led.on();
    blue_led.on();
}

void RGB_led::off() {
    red_led.off();
    green_led.off();
    blue_led.off();
}

void RGB_led::toggle() {
    if (red_led.is_on() || green_led.is_on() || blue_led.is_on()) {
        off();
    } else {
        set_color(last_color);
    }
}

void RGB_led::set_color(Color c) {
    last_color = c;

    switch (c) {
        case Blue:
            red_led.off();
            green_led.off();
            blue_led.on();
            break;
        case Green:
            red_led.off();
            green_led.on();
            blue_led.off();
            break;
        case Cyan:
            red_led.off();
            green_led.on();
            blue_led.on();
            break;
        case Red:
            red_led.on();
            green_led.off();
            blue_led.off();
            break;
        case Magenta:
            red_led.on();
            green_led.off();
            blue_led.on();
            break;
        case Yellow:
            red_led.on();
            green_led.on();
            blue_led.off();
            break;
        case White:
            red_led.on();
            green_led.on();
            blue_led.on();
            break;
        default:
            off();
            break;
    }
}
