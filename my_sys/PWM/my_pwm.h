#ifndef __MY_PWM_H
#define __MY_PWM_H

#include "../../Core/Inc/main.h"
#include "../../Core/Inc/tim.h"

class my_pwm
{
public:
    void init(TIM_HandleTypeDef *tim, uint32_t channel, float min_duty, float max_duty);
    void set_pulse(uint32_t pulse);
    void set_duty(float duty);

private:
    TIM_HandleTypeDef *tim;
    uint32_t channel;
    uint32_t max_pulse;
    uint32_t min_pulse;
};

#endif
