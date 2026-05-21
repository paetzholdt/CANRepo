#ifndef STOP_REQUEST_H
#define STOP_REQUEST_H

#include <stdbool.h>

typedef enum {
	STOP_REQUEST_RESET,
	STOP_REQUEST_SET
} StateStopRequest_t;

StateStopRequest_t get_state_stop_request(void);


void stop_request_init(void);

void cmd_stop_request_set(void);

void cmd_stop_request_reset(void);

void stop_request_task(void);


#endif
