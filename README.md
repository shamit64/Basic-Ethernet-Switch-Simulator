# Basic-Ethernet-Switch-Simulator
A simple Ethernet switch simulator implemented in C that demonstrates MAC address learning, MAC table management, frame forwarding, and broadcast behavior across multiple ports.
# Basic Ethernet Switch Simulator

## Overview
The Basic Ethernet Switch Simulator is a mini-project developed in C that demonstrates the fundamental working of an Ethernet switch. It simulates MAC address learning, frame forwarding, broadcasting, and MAC address table management.

## Features
- MAC address learning and updating.
- MAC address table management.
- Frame forwarding to the destination port.
- Broadcasting frames when the destination MAC address is unknown.
- Broadcast frame handling.
- Dropping frames when the destination is on the same port.
- Interactive command-line interface.

## Technologies Used
- Programming Language: C
- Libraries: `stdio.h`, `string.h`, `time.h`
- Concepts: Computer Networks, Ethernet Switching, MAC Address Learning.

## Project Structure
```text
basic-ethernet-switch-simulator/
├── BASIC ETHERNET SWITCH SIMULATOR.c
├── README.md
├── .gitignore
└── LICENSE
```

## How to Run

### Prerequisites
Install GCC or another C compiler.

### Compile
```bash
gcc "BASIC ETHERNET SWITCH SIMULATOR.c" -o switch_simulator
```

### Execute
On Windows:
```bash
switch_simulator.exe
```

On Linux:
```bash
./switch_simulator
```

## Available Commands
- `s` — Send a frame.
- `m` — Display the MAC address table.
- `q` — Exit the simulator.

## Learning Outcomes
- Understanding Ethernet switch operation.
- Learning how MAC addresses are associated with switch ports.
- Understanding frame forwarding and broadcasting.
- Applying C programming concepts to computer networking.

## Future Enhancements
- Add MAC address validation.
- Implement MAC address aging.
- Add support for configurable switch ports.
- Improve input validation and error handling.
- Display frame forwarding activity in a graphical interface.

## Author
SHAMIT

## License
This project is licensed under the MIT License.
