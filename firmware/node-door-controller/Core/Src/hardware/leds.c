#include "hardware/leds.h"

#include "main.h"

#include <stdbool.h>

// TODO: write generic set_led(*led)

void set_door_release_led(bool shall_be_on) {

	static bool current_led_state = false;

	if (current_led_state == shall_be_on) {
		return;
	}

	if (shall_be_on) {
		HAL_GPIO_WritePin(DOOR_RELEASE_LED_GPIO_Port, DOOR_RELEASE_LED_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(DOOR_RELEASE_LED_GPIO_Port, DOOR_RELEASE_LED_Pin, GPIO_PIN_RESET);
	}

	current_led_state = shall_be_on;
}


void set_stop_request_led(bool shall_be_on) {

	static bool current_led_state = false;

	if (current_led_state == shall_be_on) {
		return;
	}

	if (shall_be_on) {
		HAL_GPIO_WritePin(STOP_REQUEST_LED_GPIO_Port, STOP_REQUEST_LED_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(STOP_REQUEST_LED_GPIO_Port, STOP_REQUEST_LED_Pin, GPIO_PIN_RESET);
	}

	current_led_state = shall_be_on;
}


void set_green_loop_led(bool shall_be_on) {

	static bool current_led_state = false;

	if (current_led_state == shall_be_on) {
		return;
	}



	if (shall_be_on) {
		HAL_GPIO_WritePin(GREEN_LOOP_LED_GPIO_Port, GREEN_LOOP_LED_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(GREEN_LOOP_LED_GPIO_Port, GREEN_LOOP_LED_Pin, GPIO_PIN_RESET);
	}

	current_led_state = shall_be_on;
}

