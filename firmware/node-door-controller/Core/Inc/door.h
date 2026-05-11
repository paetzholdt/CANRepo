#ifndef DOOR_H
#define DOOR_H

typedef enum {
	DOORS_CLOSED,
	DOORS_OPEN
} DoorState_t;


void door_task(void);

#endif
