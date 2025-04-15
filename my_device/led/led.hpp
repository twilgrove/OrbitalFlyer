#ifndef LED_HPP
#define LED_HPP

#include "main.h"
#include "iostream"

class led
{
public:
    led(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
    ~led();
    void on();
    void off();
    void toggle();

private:
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
};

#endif // LED_HPP
