#ifndef DOOR_H
#define DOOR_H

#include <stdbool.h>

typedef enum {
	DOORS_CLOSED,
	DOORS_OPEN
} DoorState_t;

void door_init(void);

void door_task(void);

bool are_all_doors_closed(void);

#endif
