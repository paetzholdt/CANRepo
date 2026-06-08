# Requirements
The traction lock only inhibits positive traction. Braking shall remain possible.

Traction lock shall only be inactive, if:
- the state of the door safety, originally received via CAN-Bus, is SAFE
- AND the information of the door safety state is still VALID and no timeout has occurred

In reality there are more reasons, e.g. a specific number of engines need to be working without errors, but for now this model refrains from those requirements for simplicity.

If the traction lock is active, no traction is allowed.

# Boolean Logic
if (
    state_door_safety == SAFE
    && state_door_safety_info == VALID
) {
    state_traction_lock = INACTIVE;
} else {
    state_traction_lock = ACTIVE;
}