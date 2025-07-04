/*
 * led_interface.h
 *
 *  Created on: Jun 19, 2023
 *      Author: edizt
 */

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

class Led_interface {
public:
    virtual ~Led_interface() {}
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void toggle() = 0;
};

#endif  // LED_INTERFACE_H
