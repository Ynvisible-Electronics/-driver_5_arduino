# Arduino Custom Board for Driver v5.x

## Installation

To install the Driver v5 custom board:

- Open ArduinoIDE
- Open the `File > Preferences` menu
- In the `Additional boards manager URLs:` text box add the link `https://github.com/Ynvisible-Electronics/Driver-v5-Board/raw/refs/heads/main/custom_board/package_driver_v5.json`
- Press the `OK` button
- Open the board manager by pressing `CTRL+SHIFT+B` or opening the `Tools > Board > Boards Manager...` menu
- In the board manager search write `Ynvisible Driver v5`
- Select the latest version
- Click Install
- That's it! You're now ready to use the Driver v5 to test our displays! 🎉

## Change Log

### v0.1.2

* Fix SDA1 and SCL1 pin attribution

### v0.1.1

* Update WIRE and WIRE1 pin attributions

### v0.1.0

* Update references, definitions, files, folders, etc from Driver 5.0 to more generic "Driver_v5"
* Implement all pins for Driver v5.1 PCB pinout

### v0.0.3

- Update external interrupt on PA18 from EXTERNAL_INT_6 to EXTERNAL_INT_2

### v0.0.2

- Bug fix

### v0.0.1

Initial Version
