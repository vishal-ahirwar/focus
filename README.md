# Focus - Kiosk Mode App with Timer

Focus is a C++ application built using the Saucer framework that runs in kiosk mode, helping users stay focused by preventing app switching until a timer expires. Ideal for productivity, study, or work sessions, it ensures minimal distractions during focused work periods.

## Features
- **Kiosk Mode**: The app runs in a full-screen mode, preventing switching to other applications until the timer completes.
- **Timer**: Set a timer to control the duration of focused work sessions.
- **C++ with Saucer Framework**: Built with C++ for performance and reliability, leveraging the Saucer framework for GUI and application management.

## Installation

### Prerequisites
```
-Latest C++ clang compiler
-cmake
-ninja
-MSbuild tools
```
### Or
```
simply install aura cli which will setup everything for you(windows/mac/linux)
```
### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/vishal-ahirwar/focus.git
   cd focus
   ```
2. Build the project using your preferred build system:
   ```bash
   cd focus
   aura build
   ```

3. Run the application:
   ```bash
   aura run
   ```

## Usage
- Set the desired timer duration.
- Once the timer starts, you will be locked into the app, unable to switch to other applications until the timer finishes.
- (you can't)Close the app but wait for the timer to expire to regain access to other apps.

## Contributing
Feel free to fork the project, open issues, and submit pull requests. Contributions are always welcome!

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Thanks to the creators of the Saucer framework for providing a solid base for building the application.
```
