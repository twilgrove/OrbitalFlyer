#include "bluebooth.h"

uint8_t bluetooth_buffer[8];
/**
 * @brief 蓝牙初始化
 *
 * @return 无
 */
void bluebooth_init(void)
{
    HAL_UART_Receive_DMA(&BLUEBOOTH_UART, &bluetooth_buffer, 1);
}

/**
 * @brief 蓝牙接收回调函数
 *
 * @param huart 串口句柄
 * @return 无
 */
void bluebooth_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == BLUEBOOTH_UART.Instance)
    {
        bluebooth_check_data();
    }
}

/**
 * @brief 蓝牙帧数据校验
 *
 * @param void
 * @return 无
 */
void bluebooth_check_data(void)
{
}
