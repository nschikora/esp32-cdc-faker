# esp32-cdc-faker
### An ESP32 based fake CD changer for various car radios.

## Introduction
For now this is only an idea but will be my side project in 2017. This project will consist of a small piece of hardware and some software. It will be able to wirelessly connect a smartphone or other Bluetooth or WiFi enabled device to various car radios. As for my concerns I will only be able to test this project with the *Dance* radio of my *Skoda*. But since the important interfaces (for this project) are somewhat standardized throughout similar aged radios among different *VAG* brands my guess is that this project will also work for bunch of other radios.

## Boundaries
The main goal of the esp32-cdc-faker clearly lies in bringing wireless connectivity to the car radios. Neither USB ports nor any kind of SD card slots will be provided by this project. If you are looking for such functionality jeez just put dem mp3's on your phone. No seriously there are other products available that already offer a wide range of interfaces. Though none of these only offers Bluetooth and WiFi which makes them bulky and requires them to be placed in the glovebox or somewhere in the center console. They are also mostly all quite expensive if you only need wireless conenctivity like I do. I'll take this as the rationale for this project:

## Rationale
There are no compareable products available that only offer wireless connectivity for a reasonable price. Instead other products feature USB ports and SD card slots an are therefore bulky and dont fit just behind the car radio.

## Hardware
The hardware will be built around the ESP32 IC by Espressif. This neat little IC bundles Bluetooth and WiFi connectivity aswell as more than enough computing power and IOs for my purposes. The ESP32 will be accompanied by an i2c DAC for analogue audio output to the car radio. The integrated DACs of the ESP32 do not seem suitable for my purposes due to their lowish (8 bit) resolution and possibly slow sampling rate. These i2c DAC are commonly used among audio related projects featuring the Raspberry Pi and are therefore widely available and wont set you back too much. During the project I'll be using a development board like the NodeMCU-32S and some cheap breakout board DAC intended for the Raspberry Pi; there are plenty available. For the finnishing touch I planned to publish a custom PCB for all the components on [oshpark.com](https://oshpark.com/) so that there will be no need to buy multiple modules but only one PCB and some ICs and other parts.

**Additional ressources**
* Plenty information on the ESP32 can be found on [esp32.net](http://esp32.net/)
* As an external DAC one could use [this](https://www.aliexpress.com/item/Raspberry-Pi-pHAT-Sound-Card-I2S-interface-PCM5102-DAC-Module-24-bit-Audio-Board-With-Stereo/32742608325.html?spm=2114.01010208.3.11.ddyYMk&ws_ab_test=searchweb0_0,searchweb201602_1_116_10065_117_10068_114_115_113_10084_10083_10080_10082_10081_10060_10061_10062_10056_10055_10054_10059_10099_10078_10079_10073_10100_10096_10070_423_10052_10050_424_10051,searchweb201603_8&btsid=bb11f509-3b4e-4445-ac5f-50921a1462d9) although the audio quallity needs to be evaluated

## Software
