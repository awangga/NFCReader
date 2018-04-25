# NFCReader
Cheap NFCReader with Arduino Uno CH340 and PN532
## Driver Instalation
### Mac OSX
Compatible with MacOs High Sierra.
1. Download CH341SER_MAC.zip from driver folder.
2. remove old driver, please open terminal and run command
  ```
  rm -rf /System/Library/Extensions/usbserial.kext
  rm -rf /Library/Extensions/usbserial.kext
  ```
3. Unzip CH341SER_MAC and install CH34x_Install_V1.4.pkg then restart MAC, after rebooting login to your MAC and open terminal
4. Conect arduino into your Mac and Look at your serial folder 
  ```
  ls /dev/
  ```
5. You can access your Arduino on /dev/cu.wchusbserialfa130 or /dev/tty.wchusbserialfa130 using 11500 Baudrate.

## Requirement
1. [Adafruit NFCShield I2C] Library
2. On Mac OSX : Arduino IDE Version 1.6.7 or higher.
3. In PN532,set pin for I2C communication mode,Channel 1 ON and Channel 2 OFF
 

## Sceme
* PN532 - Arduino
* VCC - 5V
* GND - GND
* SDA - A4
* SCL - A5

[Adafruit NFCShield I2C]: <https://github.com/adafruit/Adafruit_NFCShield_I2C>
