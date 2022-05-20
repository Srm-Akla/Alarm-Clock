#ifndef CONST_H
#define CONST_H

// Make adresses on EEPROM for time and alarm
const int addr_alarm_hr = 1;
const int addr_alarm_min = 2;
const int addr_alarm_sec = 3;

//pin settup the LCD pins
const int rs = 9, en = 10, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
//pin settup sw, LED and piezo
//1 for output 0 for input, this is done by inverting when setting port in main
#define OK (1<<2) //digital pin 2
#define UP (1<<4)  //digital pin 12
#define DOWN (1<<3) //digital pin 11
#define GREEN (1<<5) //digital pin 13
#define RED (1<<7)  //digital pin 7
#define PIEZO (1<<0) //digital pin 8

#endif
