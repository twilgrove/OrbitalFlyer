#ifndef __BLUEBOOTH_H__
#define __BLUEBOOTH_H__

#ifdef __cplusplus
extern "C"
{

#endif
#include "../../Core/Inc/main.h"
#include "../../Core/Inc/usart.h"

#define BLUEBOOTH_UART huart6 // bluetooth:115200
#define BLUEBOOTH_BUFFER_HEAD 0x55
#define BLUEBOOTH_BUFFER_SECOND 0xCC

    void bluebooth_init(void);
    void bluebooth_UART_RxCpltCallback(UART_HandleTypeDef *huart);
    void bluebooth_check_data(void);

#ifdef __cplusplus
}
#endif

#endif
