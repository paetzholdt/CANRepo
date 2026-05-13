#ifndef STOP_REQUEST_H
#define STOP_REQUEST_H

#include <stdbool.h>

typedef enum {
	STOP_REQUEST_RESET,
	STOP_REQUEST_SET
} StopRequestState_t;


void stop_request_init(void);

bool is_stop_request_set(void);

void reset_stop_request(void);

void stop_request_task(void);


#endif
