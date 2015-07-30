# ESP8266Arduino

This repo documents my first tests with the ESP8266. Assumes the ESP8266 is already running nodeMCU. 

**WARNING: ESP8266 requires 3.3V (anything higher than 3.6v might be dangerous for the board)**

### Contents
1. ESP8266 pins and connections
2. Connect and program ESP8266 with a UartSBEE v4.0
3. Connect and program ESP8266 with an Arduino UNO (I used a Sainsmart UNO which is slightly easier since it has the option of running on 3.3v
4. Connect ESP8266 to local network and print its IP
5. Read/Edit the boot script on the ESP8266
6. Documentation of code in this repo

___

### 1. ESP8266 pins and connections

3.3V source -- VCC
VCC -- 3.3k ohm resistor -- CH_PD
GND -- GND
TX -- RX on arduino / uart
RX -- TX on arduino / uart (running at 3.3v)

___

### 2. Connect and program ESP8266 with a UartSBEE v4.0

The UartSBEE v4.0 has a switch to choose between 5v and 3.3v. This should be set to 3.3v.
Once you plug it in, open up the arduino serial monitor (or a screen session on the terminal) connected to tty.usbserial-AJV9000W (or soemthing that looks similar).
You're in!

Type in node.restart() to reboot the ESP8266. It runs the init.lua file that's in it on startup. 
```lua
node.restart()
```
Type in your lua code here. Refer [this page](http://nodemcu.com/index_en.html) for help. 

___

### 3. Connect and program ESP8266 with an Arduino UNO

This method is similar to the previous one with a few differences. Arduino typically runs 5v. This needs to be brought down to 3.3v. I cheated and used a Sainsmart UNO that has a handy switch that does that for me.  
Once you plug it in, upload the code in [this page](http://www.martyncurrey.com/arduino-to-esp8266-serial-commincation/) (it's also in the repo) and open up the arduino serial monitor connected to your arduino.
You're in!

Type in node.restart() to reboot the ESP8266. It runs the init.lua file that's in it on startup. 
Type in your lua code here. Refer [this page](http://nodemcu.com/index_en.html) for help.

___

### 4. Connect ESP8266 to local network and print its IP

Use these lines of code to connect to your network:
```lua
wifi.setmode(wifi.STATION)
wifi.sta.config("SSID","password")
```
Once connected, run this line to get the IP. 
```lua
print(wifi.sta.getip())
```
It returns null if the connection was not made, so try the above step again and recheck your SSID and password.

___

### 5. Read/Edit the boot script on the ESP8266

This method I used is likely not the most efficient method, but it was ok since I needed to write only three lines of code. 
Follow section 2 or 3 all the way to the end. Once the ESP8266 restarts, you may type in the following to open the init.lua file, write a print statement that says "Hello I have booted", and reboot the board to view your print statement being executed on boot.
```lua
file.open("init.lua","w+")
file.writeline([[print("Hello I have booted")]])
file.close()

node.reboot()
```

Similarly you can write more lines with file.writeline([[**code line goes here**]]) .

I'll update this when I find a better way.

___

### 6. Documentation of code in this repo

udp_send.pde is a processing file that continuously sends UDP messages to a specified IP (sends numbers between 0 and 255 based on cursor's x position)

init.lua file listens for messages via UDP and sends via serial (TX/RX) regardless of what the message is. This can be uploaded to the ESP8266 using section 5.

ControlLED-example.ino receives messages via software serial, assumes that message is a number between 0 and 255, and sets the brightness of an LED according to that value.

Serial_Receive.ino is the code that is used in Section 3.
