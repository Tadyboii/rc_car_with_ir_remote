# Arduino Remote Control Car

This project demonstrates how to build a simple remote control car using an Arduino and an IR remote control. The car can be controlled to move forward, backward, left, and right using an IR remote. The car's movements are managed by controlling DC motors connected to the Arduino board via an H-Bridge motor driver circuit.

## Features

- **Forward, Backward, Left, Right Control**: The car can be controlled using specific buttons on an IR remote.
- **IR Communication**: Utilizes an infrared receiver to capture commands from the remote.
- **Real-time Feedback**: Sends debug information to the serial monitor, displaying the IR codes being received.

## Components Required

- Arduino board (e.g., Arduino Uno)
- IR Receiver (e.g., TSOP4838)
- H-Bridge Motor Driver (e.g., L298N)
- 2 DC Motors
- 1 IR Remote Control (with programmable buttons)
- Jumper wires
- Power source (e.g., battery pack)

## Wiring Diagram

1. **IR Receiver** connected to pin `8` on Arduino.
2. **Left Motor** connected to pins `3` (Motor A) and `5` (Motor B).
3. **Right Motor** connected to pins `6` (Motor A) and `9` (Motor B).
4. **Motor Driver Pins (ENA, ENB)** connected to pins `10` and `11`.
5. Connect the motor driver and Arduino to a suitable power supply.

## Code Overview

This code utilizes the `IRremote` library to receive IR signals from the remote. It also uses a `StopWatch` to keep track of the time elapsed between commands, automatically stopping the car if no commands are received for a while.

### Key Functions:
- **forward()**: Moves the car forward.
- **backward()**: Moves the car backward.
- **left()**: Turns the car left.
- **right()**: Turns the car right.
- **stop()**: Stops the car.

### Custom Button Codes
The following IR codes are configured for movement:

- **Move Forward**: `"e718ff00"`
- **Move Backward**: `"ad52ff00"`
- **Move Right**: `"a55aff00"`
- **Move Left**: `"f708ff00"`

### Libraries Used:
- `IRremote`: Used to decode IR signals from the remote.
- `StopWatch`: Used to track time between commands.

## How to Use

1. **Install Libraries**: Ensure you have the `IRremote` and `StopWatch` libraries installed via the Arduino IDE's Library Manager.
2. **Upload the Code**: Upload the code to your Arduino board using the Arduino IDE.
3. **Control the Car**: Use the corresponding buttons on the IR remote to control the movement of the car.

## Video Demonstration

Here is a video demonstrating the Arduino remote control car in action:

![InAction](https://github.com/Tadyboii/rc_car_with_ir_remote/blob/main/demo.gif)

## Contributions

Feel free to fork this repository, make improvements, and open pull requests. Contributions are always welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### MIT License

