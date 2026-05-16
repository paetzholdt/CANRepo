
# Requirements
door opening permission shall ony be granted if:
- vehicle movement state is STOPPED
- at least one door release state is ACTIVE

# Boolean Logic
if ((STATE_DOOR_RELEASE == ACTIVE || STATE_FALLBACK_DOOR_RELEASE == ACTIVE) && STATE_VEHICLE_MOVEMENT == STOPPED) {
	STATE_DOOR_OPENING_PERMISSION = GRANTED;
} else {
	STATE_DOOR_OPENING_PERMISSION = REVOKED;
}

# Decision Table

| STATE_DOOR_RELEASE | STATE_FALLBACK_DOOR_RELEASE | STATE_VEHICLE_MOVEMENT | DOOR_OPENING_PERMISSION |
| ------------------ | --------------------------- | ---------------------- | ----------------------- |
| INACTIVE           | INACTIVE                    | STOPPED                | REVOKED                 |
| INACTIVE           | INACTIVE                    | MOVING                 | REVOKED                 |
| INACTIVE           | ACTIVE                      | STOPPED                | GRANTED                 |
| INACTIVE           | ACTIVE                      | MOVING                 | REVOKED                 |
| ACTIVE             | INACTIVE                    | STOPPED                | GRANTED                 |
| ACTIVE             | INACTIVE                    | MOVING                 | REVOKED                 |
| ACTIVE             | ACTIVE                      | STOPPED                | GRANTED                 |
| ACTIVE             | ACTIVE                      | MOVING                 | REVOKED                 |


