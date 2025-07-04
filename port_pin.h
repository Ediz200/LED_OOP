#ifndef PORT_PIN_H
#define PORT_PIN_H

#include <cstdint>
#include "msp430_reg.h"

template <typename AddressType, typename RegisterType>
class Port_pin {
public:

    Port_pin(AddressType port, AddressType pin);
    void set_direction_input();
    void set_direction_output();
    void set_pin_low();
    void set_pin_high();
    void toggle();
    bool get_pin_value() const;

private:
    AddressType base_address;
    AddressType pin_number;
};

//The member function definition has to be included in the header file itself.
extern template class Port_pin<uint16_t, uint8_t>;

#endif
