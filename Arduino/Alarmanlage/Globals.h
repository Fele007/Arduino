#ifndef GLOBALS_H
#define GLOBALS_H
#include <Arduino.h>
#include <SPI.h>
// LEDs


// 7-Segment
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define DP 9
#define D1 10
#define D2 11
#define D3 12
#define D4 13

// Matrix
#define MatrixCLK 0
#define MatrixCS 0
#define MatrixDIN 0

// Buzzer
#define BUZZER 40

// Register
#define SH_CP 37
#define ST_CP 35
#define DS 33

// RFID
#define CS_RFID 49
#define RST_RFID 31
#endif
