# STM32 5x5 LED Matrix
This project was made in Altium Designer and the firmware was written in STM32CubeIDE on my MacBook. The goal of this project was to get a working LED Matrix to allow for writing of any character or patter I could think of. 

For the hardware I wanted USB-C Connectivity and I used an STLINK-V2 for flashing the MCU. The MCU I chose was a STM32F030F4P6TR this was due to its cost and its pins count. Since this project was fairly simple I wanted to maximize my pin usage. I also used a SN74HC595DR shift register for outputting the serial data to the 5 LED columns. 

This was also my first 4-Layer PCB and the stack up for this board was SIGNAL-GND-GND-SIGNAL with a ground pour on the top layer as well.

### Hardware:

MIC5317-3.3YM5-TR

STM32F030F4P6TR

SN74HC595DR

## Schematic:
![image](https://github.com/Cgrubick/5x5LEDMatrix/assets/75959508/106c7703-e692-4120-851d-92cb68421037)

## PCB:
![image](https://github.com/Cgrubick/5x5LEDMatrix/assets/75959508/61112d7c-a2d6-4ba6-a727-f25793d2fde7)
![image](https://github.com/Cgrubick/5x5LEDMatrix/assets/75959508/1065ca79-31a5-4a52-a9c0-b85284bd4084)
![image](https://github.com/Cgrubick/5x5LEDMatrix/assets/75959508/e1a4dfe4-285a-4864-bff7-ee80176123e0)

# Assembled Board
![image](https://github.com/Cgrubick/5x5LEDMatrix/assets/75959508/47bd7556-94bb-42e9-af8c-5806845394d7)

# Demo
https://youtu.be/myra7309sJY



