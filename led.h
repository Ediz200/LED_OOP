#ifndef LED_H
#define LED_H

#include "led_interface.h"
#include "port_pin.h"

class Led : public Led_interface {
public:
    Led(uint16_t port, uint16_t pin);
    void on() override;
    void off() override;
    void toggle() override;
    bool is_on() const;

private:
    Port_pin <uint16_t, uint8_t> led_pin;
};

#endif  // LED_H

