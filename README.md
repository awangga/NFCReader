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
4. run this command
```sh
$ sudo ln -s /dev/tty.wch\ ch341\ USB\=\>RS232\ 1410 /dev/tty.anu
```
5. You can access your Arduino on /dev/tty.anu

