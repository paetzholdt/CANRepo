#include "stop_request.h"

#include "inputs.h"

// TODO: remove include later, when hardware output access is capsuled
#include "main.h"


static StopRequestState_t stop_request_state = STOP_REQUEST_RESET;

void stop_request_task(void) {
	switch (stop_request_state) {
		case STOP_REQUEST_RESET:
			if (get_stop_request_button_event() == BUTTON_EVENT_PRESSED) {
				stop_request_state = STOP_REQUEST_SET;

				// TODO: hardware access will be outsourced
				HAL_GPIO_WritePin(STOP_REQUEST_BUTTON_GPIO_Port, STOP_REQUEST_BUTTON_Pin, GPIO_PIN_SET);
			}
			break;

		case STOP_REQUEST_SET:
			// TODO: implement state change
			break;
	}

}
