# RPIPicoKITT
RPI Pico KITT Scanner using LEDs. Celebrating Knight Rider's 40th Birthday.

This is the source code to a video blog looking at different approaches to multi-tasking on the Raspberry PI Pico or RP2040 in C++. Repo contains three projects.

[Video blog](https://drjonea.co.uk/2022/10/12/rpi-pico-kitt-scanner/)


## KITT Simple
Simple KITT Scanner display. 8 LED moving left to right as they did on the front of KITT.

## KITT Poll
Cooperative Multitasking approach using a simple poll loop to device time between the KITT Scanner display and a blinking LED.

## KITT Task
Preemptive Multitasking approach using FreeRTOS Kernel Tasks to run the KITT Scanner display and a Blinking LED.

# Dependencies
Projects using the [pico-sdk](https://github.com/raspberrypi/pico-sdk) and [tool chain](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

*KITT Task* Example uses [FreeRTOS Kernel](https://github.com/FreeRTOS/FreeRTOS-Kernel) 

# Schematic and Equipment

Schematic can be found in the Schematic folder. 

Equipment:
+ Raspberry PI Pico or Pico W
+ Breadboard and some jumper wires
+ 9x LEDs
+ 9x 75Ohm Resistors
+ Micro USB cable for power


# Clone and build

## Clone
```
git clone --recurse-submodules https://github.com/jondurrant/RPIPicoKITT
```

## Build
In each of the three project folders

```
mkdir build
cd build
cmake ..
make
```
The "build/src" folder will contain KITT.elf and KITT.uf2 for SWD or Bootsel flashing of the Pico.

# Plug
For more on cooperative multitasking and driving LEDs with the Raspberry PI Pico, check out my course 
[Raspberry PI PICO Micro Projects (C++)](https://www.udemy.com/course/rpi-pico-microprojects-c1/?referralCode=2F48111FD8290C72D4C7).

For more on using FreeRTOS Kernel on the Raspberry PI Pico, check out my course [FreeRTOS on Raspberry PI PICO](https://www.udemy.com/course/freertos-on-rpi-pico/?referralCode=C5A9A19C93919A9DA294).