# Master Esp32 Web Servers

## Course Information

| Field | Details |
| --- | --- |
| **Instructor** | Ashraf S A AlMadhoun |
| **Platform** | ESP32 |
| **Course Link** | https://www.udemy.com/course/master-esp32-web-servers/ |
| **Repository** | https://github.com/engasm89/master-esp32-web-servers |
| **Last Updated** | 2025-11-18 |

## Overview

Master Esp32 Web Servers is a comprehensive course that teaches practical embedded systems development using ESP32. This repository contains the course materials, code examples, circuit diagrams, and additional resources to help you master the concepts covered in the video lessons.

## Learning Objectives

By the end of this course, you will be able to:

- Understand the core concepts and principles of ESP32 development
- Implement practical projects using the provided code examples
- Design and build circuits as shown in the course
- Debug and troubleshoot common issues
- Extend the examples to create your own projects

## Hardware & Components

The following components are typically required for this course:

- ESP32 development board
- Various sensors and actuators (see CIRCUIT.md for details)
- Jumper wires and breadboard
- USB cable for programming
- Power supply (if needed)

For detailed component lists and specifications, please refer to the course videos and `CIRCUIT.md`.

## Setup Instructions

1. **Install Development Tools**
   - Install Arduino IDE, PlatformIO, or your preferred development environment
   - Install necessary board support packages and libraries

2. **Clone Repository**
   ```bash
   git clone https://github.com/engasm89/master-esp32-web-servers.git
   cd master-esp32-web-servers
   ```

3. **Hardware Setup**
   - Review `CIRCUIT.md` for wiring diagrams
   - Connect components according to the circuit diagram
   - Double-check all connections before powering on

4. **Upload Code**
   - Open the `*.c` or `*.ino` file in your IDE
   - Select the correct board and port
   - Upload the code to your development board

5. **Monitor Output**
   - Open the serial monitor to view program output
   - Set baud rate as specified in the code (typically 9600 or 115200)

## Code Structure

The repository contains the following files:

- `*.c` or `*.ino` - Main source code with comprehensive comments
- `README.md` - This file, containing course overview and setup instructions
- `CIRCUIT.md` - Circuit diagrams and wiring instructions (if applicable)
- `LICENSE` - MIT License for the code

## Usage Examples

### Basic Usage

```bash
# Compile and run (for desktop testing)
gcc -Wall -Wextra -std=c11 *.c -o demo && ./demo

# Or upload via Arduino IDE for hardware execution
```

### Customization

- Modify pin assignments in the code to match your hardware setup
- Adjust sensor thresholds and timing parameters as needed
- Extend functionality by adding new features

## Troubleshooting

**Code won't upload:**
- Check USB cable connection
- Verify correct board and port selection
- Ensure drivers are installed

**No serial output:**
- Verify baud rate matches code settings
- Check serial monitor is open
- Ensure code is running (check onboard LED if available)

**Hardware not responding:**
- Double-check wiring against CIRCUIT.md
- Verify power supply is adequate
- Test components individually

## Additional Resources

- [Course on Udemy](https://www.udemy.com/course/master-esp32-web-servers/)
- [GitHub Repository](https://github.com/engasm89/master-esp32-web-servers)
- [Author's Profile](https://github.com/engasm89)

## Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/engasm89/master-esp32-web-servers/issues).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Course created by Ashraf S A AlMadhoun
- Special thanks to all students who provided feedback and suggestions

---

**Happy Learning!** 🚀

