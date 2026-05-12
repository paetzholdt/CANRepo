#include "hardware/leds.h"

#include "main.h"

#include <stdbool.h>


Led_t door_release_led = {
		.port = DOOR_RELEASE_LED_GPIO_Port,
		.pin = DOOR_RELEASE_LED_Pin,
		.current_state = false
};

Led_t stop_request_led = {
		.port = STOP_REQUEST_LED_GPIO_Port,
		.pin = STOP_REQUEST_LED_Pin,
		.current_state = false
};

Led_t green_loop_led = {
		.port = GREEN_LOOP_LED_GPIO_Port,
		.pin = GREEN_LOOP_LED_Pin,
		.current_state = false
};


void set_led(Led_t* led, bool shall_be_on) {
	if (led->current_state == shall_be_on) {
		return;
	}

	if (shall_be_on) {
		HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
	}

	led->current_state = shall_be_on;
}

void set_door_release_led(bool shall_be_on) {
	set_led(&door_release_led, shall_be_on);
}


void set_stop_request_led(bool shall_be_on) {
	set_led(&stop_request_led, shall_be_on);
}


void set_green_loop_led(bool shall_be_on) {
	set_led(&green_loop_led, shall_be_on);
}


