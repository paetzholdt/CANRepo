#include "door.h"

#include "stm32g0xx_hal.h"
#include "stm32g0xx_hal_gpio.h"
#include "door_control.h"


/* TODO: do not insert door control logic into door.c
 * - the doors shall not know, which dependencies they have
 * - the door shall only know, if there is a valid door opening request
 * - the door will return an answer, when the doors have been successfully opened AND another, when they are closed
 */


// TODO: remove include later, when hardware output access is capsuled
#include "main.h"




static DoorState_t door_state = DOORS_CLOSED;

static const uint32_t duration_of_open_doors_ms = 5000U;

static uint32_t timestamp_begin_of_doors_open = 0;


void door_task(void) {
	switch (door_state) {
		case DOORS_CLOSED:
			if (is_valid_open_door_request()) {

				// command opening of doors
				// TODO: is there a chance of representing hardware or more software as doors?

				timestamp_begin_of_doors_open = HAL_GetTick();

				// TODO: hardware access will be outsourced
				// maybe to door_control.c? -> taking care of all LEDs?
				HAL_GPIO_WritePin(GREEN_LOOP_LED_GPIO_Port, GREEN_LOOP_LED_Pin, GPIO_PIN_RESET);
				door_state = DOORS_OPEN;


			}
			break;
		case DOORS_OPEN:
			if ((HAL_GetTick() - timestamp_begin_of_doors_open) >= duration_of_open_doors_ms) {

				// TODO: hardware access will be outsourced
				HAL_GPIO_WritePin(GREEN_LOOP_LED_GPIO_Port, GREEN_LOOP_LED_Pin, GPIO_PIN_SET);

				door_state = DOORS_CLOSED;
			}
			break;
	}
}
