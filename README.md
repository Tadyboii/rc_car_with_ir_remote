# Arduino Remote Control Car

This project demonstrates how to build a simple remote control car using an Arduino and an IR remote control. The car can be controlled to move forward, backward, left, and right using an IR remote. The car's movements are managed by controlling DC motors connected to the Arduino board via an H-Bridge motor driver circuit.

## Features

- **Forward, Backward, Left, Right Control**: The car can be controlled using specific buttons on an IR remote.
- **IR Communication**: Utilizes an infrared receiver to capture commands from the remote.
- **Real-time Feedback**: Sends debug information to the serial monitor, displaying the IR codes being received.

### Libraries Used:
- `IRremote`: Used to decode IR signals from the remote.
- `StopWatch`: Used to track time between commands.

## How to Use

1. **Install Libraries**: Ensure you have the `IRremote` and `StopWatch` libraries installed via the Arduino IDE's Library Manager.
2. **Upload the Code**: Upload the code to your Arduino board using the Arduino IDE.
3. **Control the Car**: Use the corresponding buttons on the IR remote to control the movement of the car.

## Video Demonstration

Here is a video demonstrating the Arduino remote control car in action:

![InAction](https://github.com/Tadyboii/rc_car_with_ir_remote/blob/main/demovid2.gif)

## Contributions

Feel free to fork this repository, make improvements, and open pull requests. Contributions are always welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### MIT License

