#include "diagnostics/diagnostics_uart.h"

#include "main.h"


// TODO refine current output to serious logging-module

extern UART_HandleTypeDef huart2;

int __io_putchar(int character) {
	uint8_t char_byte = (uint8_t) character;
	HAL_UART_Transmit(&huart2, (uint8_t*)&char_byte, 1, 100);
	return character;
}
