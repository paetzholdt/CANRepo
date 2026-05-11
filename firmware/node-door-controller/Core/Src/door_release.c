#include "door_release.h"

#include "inputs.h"
#include <stdbool.h>

// TODO: remove include later, when hardware output access is capsuled
#include "main.h"

static DoorReleaseState_t door_release_state = DOOR_RELEASE_INACTIVE;


bool is_door_release_active(void) {
	return door_release_state == DOOR_RELEASE_ACTIVE;
}

void door_release_task(void) {
	switch (door_release_state) {
		case DOOR_RELEASE_INACTIVE:
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				door_release_state = DOOR_RELEASE_ACTIVE;

				// TODO: hardware access will be outsourced
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);

			}
			break;

		case DOOR_RELEASE_ACTIVE:
			if (get_door_release_button_event() == BUTTON_EVENT_PRESSED) {
				door_release_state = DOOR_RELEASE_INACTIVE;

				// TODO: hardware access will be outsourced
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);

			}
			break;
	}
}
