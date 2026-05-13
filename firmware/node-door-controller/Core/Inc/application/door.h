#ifndef DOOR_H
#define DOOR_H

#include <stdbool.h>

typedef enum {
	DOORS_CLOSED,
	DOORS_OPEN
} DoorState_t;


void door_init(void);

bool are_all_doors_closed(void);

void command_open_doors(void);

void door_task(void);


#endif
