TODO:
Define timeout behaviour and fail-safe state transitions


Nodes
- node-door-controller
- node-drive-controller
- node-trackside-interface (later)


CAN Communication Matrix

| CAN-ID | Sender Node          | Exported State    | Source Logic                                            | Receiver Node         | Transmission    | Timeout |
| ------ | -------------------- | ----------------- | ------------------------------------------------------- | --------------------- | --------------- | ------- |
| 0x100  | node-door-controller | state_door_safety | docs/models/requirements/state_door_safety_interlock.md | node-drive-controller | cyclic (100 ms) | 300 ms  |
|        |                      |                   |                                                         |                       |                 |         |


