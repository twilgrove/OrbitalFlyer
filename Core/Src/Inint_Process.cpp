/*
 * Inint_Process.cpp
 *
 *  Created on: Oct 4, 2024
 *      Author: T.Grove
 *      注：此文件包含初始化及过程运行函数
 */
#include "main.h"
#include "usart.h"
#include "I2C.h"
#include "Inint_Process.h"
#include "tim.h"
#include "adc.h"
#include "../my_sys/delay_us/Delay.h"
#include "../my_device/led/led.hpp"
#include "../my_device/bluebooth/bluebooth.h"
#include "../my_sys/PWM/my_pwm.h"

led led_blue(GPIOE, GPIO_PIN_4);
led led_green(GPIOE, GPIO_PIN_3);
my_pwm s1;
my_pwm s2;
my_pwm s3;
my_pwm s4;
uint16_t t1000 = 0;
uint8_t t100 = 0, v_index = 0;
uint16_t V_bat[10] = {0};
float V_bat_f = 0;
/*定时器中断回调函数*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (t1000++ >= 1000)
    {
        t1000 = 0;
        led_green.toggle();
        printf("V_bat_f: %.2f\n", V_bat_f);
    }
    if (t100++ >= 100)
    {
        t100 = 0;
        HAL_ADC_Start_IT(&hadc1);
    }
}
/*ADC转换完成回调函数*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    V_bat[v_index++] = HAL_ADC_GetValue(&hadc1);
    if (v_index >= 9)
    {
        v_index = 0;
        uint32_t sum = 0;
        for (uint8_t i = 0; i < 10; i++)
        {
            sum += V_bat[i];
        }
        sum = sum / 10.0;
        V_bat_f = (float)(sum * 3.3 * 21) / 65535;
        if (V_bat_f < V_S * 3.7)
        {
            led_blue.on();
        }
        else
        {
            led_blue.off();
        }
    }
}
/*使用初始化*/
void Use_Init()
{
    HAL_TIM_Base_Start_IT(&htim7);

    HAL_ADC_Start_IT(&hadc1);
    /*频率:50hz,占空比:0-10000,电调占空比:5%-10%*/
    s1.init(&htim2, TIM_CHANNEL_1, 0.05, 0.1);
    s2.init(&htim2, TIM_CHANNEL_2, 0.05, 0.1);
    s3.init(&htim2, TIM_CHANNEL_3, 0.05, 0.1);
    s4.init(&htim2, TIM_CHANNEL_4, 0.05, 0.1);

    s1.set_duty(0.05);
    s2.set_duty(0.05);
    s3.set_duty(0.05);
    s4.set_duty(0.05);
    HAL_Delay(2000);
    s1.set_duty(0.06);
    s2.set_duty(0.06);
    s3.set_duty(0.06);
    s4.set_duty(0.06);
}

/*while里调用函数*/
void While_Process()
{
}