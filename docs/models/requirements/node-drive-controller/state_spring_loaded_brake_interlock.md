
# Requirements
spring loaded brake shall be applied if:
- vehicle_velocity is negative (below v_negative_stop_deadband)
- OR vehicle_velocity is in between v_negative_stop_deadband and v_positive_stop_deadband AND state_traction_controller is not TRACTION
- OR vehicle_velocity is below 7 km/h AND traction_command_input is BRAKE
- OR state_traction_controller is EMERGENCY_BRAKE
- OR state_door_safety is UNSAFE

### Note
Modern trams additionally can make use of standstill torque of e.g. their three-phase induction motors. Yet, spring loaded brakes are still required to be able to hold the tram at standstill at any necessary gradient, since trams must have a brake-system that can hold the tram by itself even in case of loss of all power.


# Boolean Logic

if (
    vehicle_velocity < v_negative_stop_deadband
	|| (vehicle_velocity >= v_negative_stop_deadband && vehicle_velocity <= v_positive_stop_deadband) && state_traction_controller != TRACTION
	|| (vehicle_velocity < 7.0 && state_traction_controller == BRAKE)
	|| state_traction_controller == EMERGENCY_BRAKE
	|| state_door_safety == UNSAFE

) {
    state_slb_application_required = true;
} else {
	state_slb_application_required = false;
}