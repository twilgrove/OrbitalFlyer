#include "main.h"
#include "usart.h"
#include <stdint.h>
/**
 * @brief 串口接收回调,中断接收,DMA传输完成(定长)
 *
 * @param huart
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
}
/**
 * @brief 串口接收回调,DMA传输完成(不定长)
 *
 * @param huart
 * @param Size
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
}
/**
 * @brief 串口错误回调
 *
 * @param huart
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
}