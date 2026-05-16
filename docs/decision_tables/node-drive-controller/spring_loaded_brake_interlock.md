
# Requirements
spring loaded brake shall be applied if:
- vehicle_velocity is negative
- OR vehicle_velocity below 0.5 km/h
- OR vehicle_velocity is below 7 km/h AND traction_command_input is BRAKE
- OR state_door_release is ACTIVE
- OR state_fallback_door_release is ACTIVE
- OR state_doors is OPEN


# Boolean Logic

if (
    vehicle_velocity < 0.5
	|| (vehicle_velocity < 7.0 && state_traction_command == BRAKE)
	|| state_door_release == ACTIVE
	|| state_fallback_door_release == ACTIVE
	|| state_doors == OPEN
) {
    state_slb_application_required = true;
}