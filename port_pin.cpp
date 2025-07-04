#include "port_pin.h"
#include "msp430_reg.h"

template class Port_pin<uint16_t, uint8_t>;

template <typename AddressType, typename RegisterType>
Port_pin<AddressType, RegisterType>::Port_pin(AddressType port, AddressType pin)
    : base_address(port), pin_number(pin) {}

template <typename AddressType, typename RegisterType>
void Port_pin<AddressType, RegisterType>::set_direction_input() {
    *reinterpret_cast<volatile RegisterType*>(base_address + offsetDIR) &= ~(1 << pin_number);
}

template <typename AddressType, typename RegisterType>
void Port_pin<AddressType, RegisterType>::set_direction_output() {
    *reinterpret_cast<volatile RegisterType*>(base_address + offsetDIR) |= (1 << pin_number);
}

template <typename AddressType, typename RegisterType>
bool Port_pin<AddressType, RegisterType>::get_pin_value() const {
    return (*reinterpret_cast<volatile RegisterType*>(base_address + offsetIN) >> pin_number) & 0x01;
}

template <typename AddressType, typename RegisterType>
void Port_pin<AddressType, RegisterType>::toggle() {
    *reinterpret_cast<volatile RegisterType*>(base_address + offsetOUT) ^= (1 << pin_number);
}

template <typename AddressType, typename RegisterType>
void Port_pin<AddressType, RegisterType>::set_pin_low() {
    *reinterpret_cast<volatile RegisterType*>(base_address + offsetOUT) &= ~(1 << pin_number);
}

template <typename AddressType, typename RegisterType>
void Port_pin<AddressType, RegisterType>::set_pin_high() {
    *reinterpret_cast<volatile RegisterType*>(base_address + offsetOUT) |= (1 << pin_number);
}
