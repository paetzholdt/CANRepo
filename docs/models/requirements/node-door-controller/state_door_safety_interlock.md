
# Requirements
door_safety_state shall only be SAFE, if
- doors are CLOSED
- AND door release is NOT active
- AND fallback door release is NOT active

# Boolean Logic

if (
	state_doors == CLOSED
	&& state_door_release == INACTIVE
	&& state_fallback_door_release == INACTIVE
) {
	state_door_safety = SAFE
} else {
	state_door_safety = UNSAFE
}