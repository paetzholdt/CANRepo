
# Requirements
possible outputs of the state_spring_loaded_brake_interlock are:
state_spring_loaded_brake_force_required = FULL_BRAKE | REGULAR_BRAKE | NO_BRAKE;

spring loaded brake shall be fully applied if:
- the vehicle is rolling backwards
- the state of the vehicle movement is unknown
- the driver applies an emergency brake with the traction controller
- the state of traction controller is unknown or unreliable
- the doors are not in safe condition - state received via CAN
- the state of the door safety is unknown (e.g. timeout was reached on messages of door safety from the door controller node)
- the vehicle is stopped while traction is not applied by the driver or traction is not permitted

spring loaded brake shall be applied according to the exact request of the traction controller
- vehicle is at low speed and the driver is applying normal braking force with the traction controller


### Notes
I am aware that applying full brake force with the spring loaded brakes probably would cause the wheels to lock up even when the tram is moving at cruising speed and that this would cause damage to the wheels. Furthermore it would not achieve the lowest possible braking distance as well as it might not be the safest action for the passengers. Yet, it is the safest state this model will be able to provide, since this project does not focus on wheel-slide protection systems, but on a simplified door safety logic.

Modern trams additionally can make use of standstill torque of e.g. their three-phase induction motors. Yet, spring loaded brakes are still required to be able to hold the tram at standstill at any necessary gradient, since trams must have a brake-system that can hold the tram by itself even in case of loss of all power.


# Boolean Logic

if (state_vehicle_movement == ROLLING_BACKWARDS
	|| state_vehicle_movement_info == INVALID
	|| state_traction_controller == EMERGENCY_BRAKE
	|| state_traction_controller_info == INVALID
	|| state_door_safety == UNSAFE
	|| state_door_safety_info == INVALID
	|| (state_vehicle_movement == STOPPED && (state_traction_controller != TRACTION || state_traction_lock == ACTIVE))
) {
	state_spring_loaded_brake_force_required = FULL_BRAKE;

} else if (state_vehicle_movement == LOW_SPEED
			&& state_traction_controller == BRAKE) {
	state_spring_loaded_brake_force_required = REGULAR_BRAKE;
} else {
	state_spring_loaded_brake_force_required = NO_BRAKE;
}