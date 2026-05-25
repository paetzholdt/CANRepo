#include "system/door_requests.h"

#include <stdbool.h>

static bool is_rqst_doors_open = false;

void rqst_doors_open(void) {
	is_rqst_doors_open = true;
}

bool consume_rqst_doors_open(void) {
	if (!is_rqst_doors_open) {
		return is_rqst_doors_open;
	}

	// consume request
	is_rqst_doors_open = false;
	return true;
}
