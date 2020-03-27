# HW_SW_Interfacing
Layered architecture for AVR Atmega32 and ARM STM32F10x

 <p align="center">
  <img  src="../media/layeredArch.png?raw=true">
</p>

## Horizontal layers:
1) Microcontroller Abstraction Layer "MCAL"
2) Hardware Abstraction Layer "HAL"
3) Service Layer
4) Application Layer 

## Vertical layers:
1) Libraris "LIB"
2) Operating System Stack "OS"
3) Memory Stack "MEM"

--- 
## Component On The Shelf
The COTS holds software modules that are ready to be inserted in any project

Note: COTS still in progress

---
## Drivers setup
driversSetup is a tool to create required files for each module in the COTS, checking for multiplication, including libraries and header files, adding files' headers and header guards.

- Path of COTS needs to be added to environment variables as 'COTS'
- Files' structure must be as follow:

 <p align="center">
  <img  src="../media/filesStructure.PNG ?raw=true">
</p>




