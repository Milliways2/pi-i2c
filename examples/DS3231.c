#include "pi-i2c.h"
#include <stdio.h>
#include <stdlib.h>

// display status of DS3231 RTC - assumes time in UTC 24 hour mode
// 2022-07-06

const int i2cBus = 1;
const int i2cAddr = 0x68;

int bcdToDec(char b) { return (b/16)*10 + (b%16); }

// The time and calendar registers are BCD
#define SECONDS 0x00
#define MINUTES 0x01
#define HOURS 0x02
#define DAY 0x03
#define DATE 0x04
#define MONTH 0x05
#define YEAR 0x06
#define A1M1 0x07
#define A1M2 0x08
#define A1M3 0x09
#define A1M4 0x0A
#define A2M2 0x0B
#define A2M3 0x0C
#define A2M4 0x0D
#define CONTROL 0x0E
#define TEMP 0x11
#define TEMPFRAC 0x12

int main(){
   int handle = i2cOpen(i2cBus, i2cAddr);
   if(handle < 0) exit(handle);
   int secs   = bcdToDec(i2cReadByte(handle, SECONDS));
   int mins   = bcdToDec(i2cReadByte(handle, MINUTES));
   int hours  = bcdToDec(i2cReadByte(handle, HOURS));
   int days   = bcdToDec(i2cReadByte(handle, DATE));
   int months = bcdToDec(i2cReadByte(handle, MONTH));
   int years  = bcdToDec(i2cReadByte(handle, YEAR));

   printf("The RTC time is %2d:%02d:%02d\n", hours, mins, secs);
   printf("The RTC date is %2d-%02d-%02d\n", years, months, days);

   float temperature = i2cReadByte(handle, TEMP) + ((i2cReadByte(handle, TEMPFRAC) >>6) *0.25);
   printf("The temperature is %.2f°C\n", temperature);

   return 0;
}
