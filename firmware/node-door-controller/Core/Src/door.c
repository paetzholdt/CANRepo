#include "door.h"

#include "door_release.h"
#include "stop_request.h"


/* TODO: do not insert door control logic into door.c
 * - the doors shall not know, which dependencies they have
 * - the door shall only know, if there is a valid door opening request
 * - the door will return an answer, when the doors have been successfully opened AND another, when they are closed
 */
static DoorState_t door_state = DOORS_CLOSED;


void door_task(void) {
	switch (door_state) {
		case DOORS_CLOSED:
			break;
		case DOORS_OPEN:
			break;
	}
}
