/*
 * Delay.h
 *
 *  Created on: Jun 2, 2024
 *      Author: c.ys
 *本体参考：https://blog.csdn.net/qq153471503/article/details/102930097
 */
#ifndef __DELAY_H_
#define __DELAY_H_
#include "main.h"

/*需要按实际更改的部分*/
#define CPU_FREQUENCY_MHZ 480 // STM32时钟主频

#ifdef __cplusplus
extern "C"
{
#endif

    void Delay_us(uint32_t us); // us级延时函数

#ifdef __cplusplus
}
#endif

#endif
