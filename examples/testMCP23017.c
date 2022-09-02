#include <pi-i2c.h>
#include <MCP23017.h>
#include <stdio.h>
#include <stdlib.h>
// MCP23017
// 2022-07-11

const int i2cBus = 1;
const int i2cAddr = 0x20;

#define IODIRA	0x00
#define IPOLA	0x02
#define GPINTENA	0x04
#define DEFVALA	0x06
#define INTCONA	0x08
#define IOCON	0x0A
#define GPPUA	0x0C
#define INTFA	0x0E
#define INTCAPA	0x10
#define GPIOA	0x12
#define OLATA	0x14

#define IODIRB	0x01
#define IPOLB	0x03
#define GPINTENB	0x05
#define DEFVALB	0x07
#define INTCONB	0x09
// #define IOCON	0x0B
#define GPPUB	0x0D
#define INTFB	0x0F
#define INTCAPB	0x11
#define GPIOB	0x13
#define OLATB1	0x15


int main(){
   int handle = i2cOpen(i2cBus, i2cAddr);
//    int handle = SMBusOpen(i2cBus, i2cAddr);
   if(handle < 0) exit(handle);

// set all of port B to outputs
   i2cWriteByte(handle, IODIRB, 0x00);	 // IODIRB register
//  0x12 tells the device that we are writing to the pins in directory A
   i2cWriteByte(handle, GPIOB, 0xAA);	 // GPIOB register

   return 0;
}
