#include "my_pwm.h"
void my_pwm::init(TIM_HandleTypeDef *tim, uint32_t channel, float min_duty, float max_duty)
{
    this->tim = tim;
    this->channel = channel;
    this->min_pulse = (uint32_t)(min_duty * (tim->Init.Period + 1));
    this->max_pulse = (uint32_t)(max_duty * (tim->Init.Period + 1));
    HAL_TIM_PWM_Start(tim, channel);
}
/**
 * @brief 设置占空比
 *
 * @param duty 占空比
 */
void my_pwm::set_duty(float duty)
{
    uint32_t pulse = (uint32_t)(duty * (tim->Init.Period + 1));
    pulse = pulse < min_pulse ? min_pulse : pulse;
    pulse = pulse > max_pulse ? max_pulse : pulse;
    __HAL_TIM_SetCompare(tim, channel, pulse);
}
/**
 * @brief 设置脉冲宽度
 *
 * @param pulse 脉冲宽度
 */
void my_pwm::set_pulse(uint32_t pulse)
{
    pulse = pulse < min_pulse ? min_pulse : pulse;
    pulse = pulse > max_pulse ? max_pulse : pulse;
    __HAL_TIM_SetCompare(tim, channel, pulse);
}
