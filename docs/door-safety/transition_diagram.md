## DrivingState

| Current State | Event                      | Condition                                                                 | Next State | Action                 |
| ------------- | -------------------------- | ------------------------------------------------------------------------- | ---------- | ---------------------- |
| Stopped       | traction_command_applied   | doors_closed<br>&& !valid_door_release<br>&& !valid_fallback_door_release | Moving     | apply_traction_command |
| Moving        | vehicle_speed_reaches_zero |                                                                           | Stopped    | hold_vehicle_at_stop   |


## StopRequestState

| Current State     | Event                             | Condition | Next State        | Action                                                       |
| ----------------- | --------------------------------- | --------- | ----------------- | ------------------------------------------------------------ |
| StopRequest_Reset | passenger_stop_button_pressed     |           | StopRequest_Set   | activate_acoustic_signal_once;<br>turn_on_stop_request_light |
| StopRequest_Set   | passenger_stop_button_pressed     |           | StopRequest_Set   | ignore_duplicate_stop_request                                |
| StopRequest_Set   | stop_request_reset_conditions_met |           | StopRequest_Reset | turn_off_stop_request_light                                  |


## DoorReleaseState

| Current State        | Event                       | Condition                                  | Next State           | Action                                           |
| -------------------- | --------------------------- | ------------------------------------------ | -------------------- | ------------------------------------------------ |
| DoorRelease_Inactive | door_release_button_pressed | vehicle_stopped<br>&& station_detected     | DoorRelease_Active   | turn_on_door_release_light                       |
| DoorRelease_Inactive | door_release_button_pressed | !vehicle_stopped<br>\|\| !station_detected | DoorRelease_Inactive | block_door_release;<br>warn_driver_three_seconds |
| DoorRelease_Active   | door_release_button_pressed |                                            | DoorRelease_Inactive | turn_off_door_release_light                      |
| DoorRelease_Active   | validity_lost               | !vehicle_stopped<br>\|\| !station_detected | DoorRelease_Inactive | alert_driver;<br>turn_off_door_release_light     |


## FallbackDoorReleaseState

| Current State                | Event                                | Condition        | Next State                   | Action                                                    |
| ---------------------------- | ------------------------------------ | ---------------- | ---------------------------- | --------------------------------------------------------- |
| FallbackDoorRelease_Inactive | fallback_door_release_button_pressed | vehicle_stopped  | FallbackDoorRelease_Active   | turn_on_fallback_door_release_light                       |
| FallbackDoorRelease_Inactive | fallback_door_release_button_pressed | !vehicle_stopped | FallbackDoorRelease_Inactive | block_fallback_door_release;<br>warn_driver_three_seconds |
| FallbackDoorRelease_Active   | fallback_door_release_button_pressed |                  | FallbackDoorRelease_Inactive | turn_off_fallback_door_release_light                      |
| FallbackDoorRelease_Active   | validity_lost                        | !vehicle_stopped | FallbackDoorRelease_Inactive | alert_driver;<br>turn_off_fallback_door_release_light     |


## StationDetectionState

| Current State       | Event                         | Condition | Next State          | Action |
| ------------------- | ----------------------------- | --------- | ------------------- | ------ |
| Station_NotDetected | station_begin_signal_detected |           | Station_Detected    |        |
| Station_Detected    | station_end_signal_detected   |           | Station_NotDetected |        |


## DoorState

| Current State | Event                  | Condition                                                                       | Next State   | Action                     |
| ------------- | ---------------------- | ------------------------------------------------------------------------------- | ------------ | -------------------------- |
| Doors_Closed  | open_door_request      | (valid_door_release<br>\|\| valid_fallback_door_release)<br>&& stop_request_set | Doors_Open   | open_doors;<br>start_timer |
| Doors_Open    | open_door_request      | (valid_door_release<br>\|\| valid_fallback_door_release) && stop_request_set    | Doors_Open   | restart_timer              |
| Doors_Open    | internal_timer_run_out |                                                                                 | Doors_Closed | close_doors                |
