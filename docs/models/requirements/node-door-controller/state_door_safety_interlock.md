
# Requirements
state_door_safety shall only be SAFE, if
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

## Note
If at a later stage this project will achieve a stage above beginner level, this interlock could model more differentiating states next to the ones currently given, e.g. UNKNOWN or SAFETY_SYSTEM_OVERRIDDEN