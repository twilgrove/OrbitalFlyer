#include "led.hpp"

led::led(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    this->GPIOx = GPIOx;
    this->GPIO_Pin = GPIO_Pin;
}

led::~led() {}

void led::on()
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

void led::off()
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
}

void led::toggle()
{
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}
