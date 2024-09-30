# Arduino Custom Board for Driver 5.0

## Installation

To install the Driver 5.0 custom board:

- Open ArduinoIDE
- Go to File > Preferences
- Add the following url to the "Additional boards manager URLs:" text box: https://raw.githubusercontent.com/Ynvisible-Electronics/driver_5_arduino/refs/heads/main/custom_board/package_driver5_0.json
- Press the "OK" button
- Open the board manager: CTRL+SHIFT+B or Tools > Board > Boards Manager...
- In the search tab write: "Ynvisible Driver 5.0"
- Select the latest version
- Click Install


## Change Log

### v0.0.3

- Update external interrupt on PA18 from EXTERNAL_INT_6 to EXTERNAL_INT_2

### v0.0.2

- Bug fix

### v0.0.1

Initial Version
