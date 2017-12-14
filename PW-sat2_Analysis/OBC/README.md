# PW-sat2|On Board Computer

## Payload

The  main  task  of  the  PW-Sat2  satellite  is  to  test  the  deorbitation  system and the second  task  is  to  test  Sun  sensor  which  consists  of  4  small  solar  panels

## On Board Computer
Everything  is  controlled  by  on-board  computer.  It  processes  commands  received  from  Earth, monitors  power  budget,  automatically  does  tasks  based  on  built-in  schedule  and  receives  data from  cameras. 

### Tasks of OBC
#### General
1. Communication  with  other  satellite subsystems  via I2C  and  SPI interface. System  and payload(experiment)  bus  are separated. 
2. Be   the  timer of the  mission  from  the moment  of ejection  from  the  P-POD and  turning  on power. 
3. Performing scheduled  tasks  -  built-in  tasks  list  to perform  during  mission. 
4. Enabling performing  any  task  based on  command  from  Earth, before time provided within  task  list. 
5. Performing simple scripts  sent  from  Earth. 
6. Monitoring  of the  power  budget and  issuing  commands  to EPS  which turns  on/off  power switches.
#### Payload Specfic
1. Handling parallel  NOR  Flash  memory  for  images  data, Static  RAM  memory  (minimum 1MB  operating  memory),  serial Flash memory  (measurements  of the currents, voltages and  temperatures  onboard  satellite)  and  small block  of FRAM memory  (ferrite-core memory, for storage of essential configurations  and  the  map  of damaged  memory  cells)

### OBC Architecture
In PW-sat2 2 different redundant microcontrollers were used of which first microcontroller iss the main one which provides completer functionality of the satellite nd second one is reserve microcontroller is reserve one which provides partial functionality of satellite. It has the advantage that as both the microcontrollers have different rate of degradation probability of both getting degraded at same time is less.

![alt text](https://github.com/singhalanirudh18/advitaya/blob/master/images/2_microcontroller.png)

### Memory Blocks
#### Images for camera
For this purpose **NOR flash memory** was used because in NOR Flash we have direct access to every memory cell and it also consumes less energy.

#### System settings
System settings will be stored in **FRAM memory** because they provide higher resistance from ionizing radiation. In order to boost the reliability two identical memory blocks can be used for settings data
saving. Both blocks would have the same data, just like in RAID 1 hard disks array.
![alt text](https://github.com/singhalanirudh18/advitaya/blob/master/images/RAID_1.png)

#### Memory for holding results of current tasks
SRAM will be used for this task

#### Measurement data
Measurement data Voltages and currents of various components. During each communication session measurements data was sent to Earth. **NAND Ram** was used for this purpose
.
### General Block Diagram of OBC Architecture
![alt text](https://github.com/singhalanirudh18/advitaya/blob/master/images/Block_diagram.png)


#### Microcontroller 0 – OBC0

Main microcontroller which will have enough computing power to compress and send images. It
will receive photos from CAM2.

#### Static RAM memory OBC0

Memory for storing currently ongoing calculations, e.g. image buffering
transmitted from the camera to Flash memory, variable storage, etc.
#### NOR Flash data memory

It holds photos, films and payload data collected during the mission. Works like hard disk in PC.

#### Microcontroller 1 – OBC1
Its task is to partially substitute OBC0 in case when it malfunctions. It is much less advanced
than OBC0. Its level of integration is much smaller than OBC0's, which will allow to prolong
functioning even with increased ionizing radiation.

#### OBC1 Flash memory

Serial Flash memory for holding OBC1's data. It isn't necessary for OBC01 to work but it does
allow holding experiments results after OBC0's failure.

#### The arbitrage between OBC0 and OBC1

Microcontroller 0 and 1 should be powered independently and should be turned on by the EPS.
Just after OBC's start EPS questions OBC0 and if it doesn't respond EPS turns it off and turns on
OBC1. Even though EPS turned off OBC0's power, OBC1 can turn OBC0 on. This was OBC0 can be
reconfigured from Earth using OBC1.

#### Oversee and restart system with watchdog

In case of the situation when OBC0 or OBC1 becomes frozen up, e.g. because of stack-overflow,
watchdog system will restart it. Oversee and restart system is making sure that resetting is
working correct. Cyclical restarts of OBC (only in OBC0), e.g. every few hours, can reduce the
chance of stack-overflow etc.

#### Measurements data memory – Serial Flash 0

On-board computer will measure every now and then current, voltage, temperatures etc. Serial
Flash memory, connected with SPI interface, will hold these data which will be sent to Earth
during the next communication session. It can replace NOR Flash memory as a payload's data
memory. If OBC0 malfunctions it is disconnected from the power. Measurement's data memory
needs to be power either from OBC0 or OBC1, so that we can access these data even when OBC0
malfunctions. FRAM memory's powering is handled in a similar manner.

#### Settings data – FRAM

It holds system's configuration data and deteriorated memory cells maps. It is powered in
similar way to Serial Flash 0 and it works in RAID 1 configuration.

#### Internal I2C and SPI buses
They transfer data within the OBC subsystem.

#### CAM2 camera’s interface

8-bit parallel data buses which connect camera with OBC. It transfers image's data from camera.
With payload's data bus (I2C or SPI) camera receives commands.

#### OBC0 and OBC1 diagnostics

Two independent UART interfaces from which one connects with OBC0 and the second one
connects with OBC1. With them we can connect PC to OBC and change its settings, without
programming it. We can use it for tests before the launch.

#### External I2C and SPI buses

I2C and SPI buses are lead out of OBC. Additionally they were divided into system bus and
payload bus. I2C bus is used for controlling satellite's subsystems and transferring small
amounts of data, and SPI bus is used for transferring large amounts of data.

### Microcontroller used
Primary microcontroller : STM32F103ZGT6  
Reserve microntroller : ATXMega192A1 

