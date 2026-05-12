#ifndef LEDS_H
#define LEDS_H


#include <stdbool.h>

void set_door_release_led(bool shall_be_on);

void set_stop_request_led(bool shall_be_on);

void set_green_loop_led(bool shall_be_on);

#endif
