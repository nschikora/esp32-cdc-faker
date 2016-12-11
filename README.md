# esp32-cdc-faker
### An ESP32 based fake CD changer for various car radios.

## Introduction
For now this is only an idea but will be my side project in 2017. This project will consist of a small piece of hardware and some software. It will be able to wirelessly connect a smartphone or other Bluetooth or WiFi enabled device to various car radios. As for my concerns I will only be able to test this project with the *Dance* radio of my *Skoda*. But since the important interfaces (for this project) are somewhat standardized throughout similar aged radios among different *VAG* brands my guess is that this project will also work for bunch of other radios.

## Boundaries
The main goal of the esp32-cdc-faker clearly lies in bringing wireless connectivity to the car radios. Neither USB ports nor any kind of SD card slots will be provided by this project. If you are looking for such functionality jeez just put dem mp3's on your phone. No seriously there are other products available that already offer a wide range of interfaces. Though none of these only offer Bluetooth and WiFi which makes them bulky and requires them to be placed in the glovebox or somewhere in the center console. They are also mostly all quite expensive if you only need wireless conenctivity like I do. I'll take this as the rationale for this project:

## Rationale
There are no compareable products available that only offer wireless connectivity for a reasonable price. Instead other products feature USB ports and SD card slots an are therefore bulky and dont fit just behind the car radio.

## Planned features


## Hardware
The hardware will be built around the Espressif ESP32. This neat little IC bundles Bluetooth and WiFi connectivity aswell as more than enough computing power and IOs for my purposes. The ESP32 will be accompanied by an i2c DAC for analogue audio output to the car radio. The integrated DACs of the ESP32 do not seem suitable for my purposes due to their lowish (8 bit) resolution and possibly slow sampling rate. Isable i2c DAC are commonly used among audio related projects featuring the Raspberry Pi and are therefore widely available plus they wont set you back much. During the project I'll be using a development board like the [NodeMCU-32S](http://www.shenzhen2u.com/NodeMCU-32S) and some cheap breakout board DAC; there are plenty available. For the finnishing touch I planned to design a PCB for all the components and publish that on [oshpark.com](https://oshpark.com/) so that there will be no need to buy multiple modules but only one PCB, some ICs and passive parts.

**Additional ressources**
* Plenty information on the ESP32 can be found on [esp32.net](http://esp32.net/)
* As an external DAC one could use [this](https://www.aliexpress.com/item/Raspberry-Pi-pHAT-Sound-Card-I2S-interface-PCM5102-DAC-Module-24-bit-Audio-Board-With-Stereo/32742608325.html?spm=2114.01010208.3.11.ddyYMk&ws_ab_test=searchweb0_0,searchweb201602_1_116_10065_117_10068_114_115_113_10084_10083_10080_10082_10081_10060_10061_10062_10056_10055_10054_10059_10099_10078_10079_10073_10100_10096_10070_423_10052_10050_424_10051,searchweb201603_8&btsid=bb11f509-3b4e-4445-ac5f-50921a1462d9) although the audio quallity needs to be evaluated

## Software
Some work of the software development part has already been done by. I'm talking about figuring out the protocol that the radio and CD changer use. Information on that protocol can be found in the additional ressources below. What's left is:
* Port the radio/CD changer protocol for use with NodeMCU
* Contribute to the NodeMCU port for the NodeMCU-32S because it seems that there is no Bluetooth LUA module available yet
* Figure out i2c audio output on NodeMCU platforms
* Develop the main application accoring to the requirement analysis

**Additional ressources**
* Information on the radio/CD changer protocol by Martin S. can be found on [martinsuniverse.net](http://martinsuniverse.de/projekte/cdc_protokoll/cdc_protokoll.html) (german)
* Implementation of the radio/CD changer protocol using a Raspberry Pi on [dev.shyd.de](http://dev.shyd.de/2013/09/avr-raspberry-pi-vw-beta-vag-cdc-faker/)
* ESP32 tree of NodeMCU on [GitHub](https://github.com/nodemcu/nodemcu-firmware/tree/dev-esp32)
* NodeMCU on [Wikipedia](https://en.wikipedia.org/wiki/NodeMCU)

## Requirement analysis

## Legal issues

I think there are four different legal issues regarding this project.

#### 1. Usage of the properitary, reverse engineered protocol used to communicate with the CD changer.

 My guess is that this won't be an issue as long as no binaries of the protocol implementation are distributed and this project is only used non-commercially. But don't nail me down on this.

#### 2. Directly related to the first issue: Figure out what open source license fits this project.

 I really don't even have the slightest clue what license covers soft- and hardware designs aswell as usage of properitary protocols best. Any advice welcome.

#### 3. Voiding the warranty of the radio or even the car when using the hardware designed during this project.

 I suppose that you will at least void the warranty of your radio when you use the hardware of this project and break anything. Thus don't use it if you don't understand what you are doing. For my part I don't care voiding anything since the car is old and out of warranty anyway.

#### 4. Usage of this unregistered hardware in public traffic.

 I assume in some places of the world it is illegal to use hardware in your car that is untested by authorities and not licensed by the car manufacturer. At least while participating in public traffic. For example in Germany the TÜV would probably need to accept the product or at least issue a clearance certificate so that it can be used legally in public traffic.

