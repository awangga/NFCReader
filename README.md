# NFCReader
Cheap NFCReader with Arduino Uno CH340
## Driver Instalation
### Mac OSX
1. Download and install from folder driver
2. Before click restart please open terminal and run command
  ```sh
  $ sudo nvram boot-args=”kext-dev-mode=1″
  ```
3. restart MAC, after rebooting login to your MAC and open terminal
4. Lookat your serial folder and match it to create softlink to it by run this command
  ```sh
  $ ls /dev/cu.wch*
  $ sudo ln -s /dev/cu.wch\ ch341\ USB\=\>RS232\ 1d10 /dev/cu.wch
  ```
5. You can access your Arduino on /dev/tty.anu

## Requirement
1. Arduino AVR Boards version 1.6.11
 * Open up Arduino Apps, select menu tools> Board: "Arduino/Genuino Uno"> Boards Manager
 * Select Version and Install it
