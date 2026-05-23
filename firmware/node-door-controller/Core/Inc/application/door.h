#ifndef DOOR_H
#define DOOR_H

#include <stdbool.h>

typedef enum {
	STATE_DOORS_CLOSED,
	STATE_DOORS_OPEN
} StateDoors_t;


void doors_init(void);

void doors_task(void);


void cmd_doors_open(void);

void cmd_doors_close(void);


#endif
