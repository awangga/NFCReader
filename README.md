# NFCReader
Cheap NFCReader with Arduino Uno CH340 and PN532
## Driver Instalation
### Mac OSX
1. Download and install from folder driver
2. Before click restart please open terminal and run command
  ```
  sudo nvram boot-args=”kext-dev-mode=1″
  ```
3. restart MAC, after rebooting login to your MAC and open terminal
4. Lookat your serial folder and match it to create softlink to it by run this command
  ```
  sudo ln -s /dev/cu.wch\ ch341\ USB\=\>RS232\ 1d10 /dev/cu.wch
  ```
5. You can access your Arduino on /dev/cu.wch port

## Requirement
1. [Adafruit NFCShield I2C] Library
2. On Mac OSX : Arduino IDE Version 1.6.7 or other version with support selecting /dev/tty.wch option
3. In PN532,set pin for I2C communication mode,Channel 1 ON and Channel 2 OFF
 

## Sceme
* PN532 - Arduino
* VCC - 5V
* GND - GND
* SDA - A4
* SCL - A5

[Adafruit NFCShield I2C]: <https://github.com/adafruit/Adafruit_NFCShield_I2C>
