#include "door_release.h"

#include "inputs.h"

// TODO: remove include later, when hardware output access is capsuled
#include "main.h"



static char message_door_release_set[] = "Door release set\r\n";
static char message_door_release_reset[] = "Door release reset\r\n";



static DoorReleaseState_t door_release_state = DOOR_RELEASE_INACTIVE;

void door_release_task(void) {
	switch (door_release_state) {
		case DOOR_RELEASE_INACTIVE:
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				door_release_state = DOOR_RELEASE_ACTIVE;

				// TODO: hardware access will be outsourced
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

				// only for debugging and better understanding
				// TODO: to be deleted
				// TODO: remove extern UART_HandleTypeDef huart2; from main.h
				HAL_UART_Transmit(&huart2, (uint8_t*) message_door_release_set, sizeof(message_door_release_set) - 1, 5);
			}
			break;

		case DOOR_RELEASE_ACTIVE:
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				door_release_state = DOOR_RELEASE_INACTIVE;

				// TODO: hardware access will be outsourced
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);

				// only for debugging and better understanding
				// TODO: to be deleted
				HAL_UART_Transmit(&huart2, (uint8_t*) message_door_release_reset, sizeof(message_door_release_reset) - 1, 5);
			}
			break;
	}
}
