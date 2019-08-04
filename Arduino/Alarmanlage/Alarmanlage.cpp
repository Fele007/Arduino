#include "Globals.h"
#include "Blinker.h"
#include "Matrix.h"
#include "Segments.h"
#include "TimerBank.h"
#include "Info.h"
#include "ShiftRegister.h"
#include "RFID.h"

int displayPins[] = { D1, D2, D3, D4 };
int segmentPins[] = { A, B, C, D, E, F, G, DP };

Segments segments (displayPins, segmentPins);
TimerBank tb(2);
ShiftRegister shiftRegister;
RFID rfid;

void setup() {
	// Communication
	Serial.begin(9600);
	SPI.begin();

	// Shift Register
	shiftRegister.setState(0b00000000);

	// Segmentanzeige++++++++++++++++++++++++++++++++++++++++++
	segments.setCountdown(10);

	// Timer+++++++++++++++++++++++++++++++++++++++++++++++++++
	tb.registerProcess(&segments, 5.0f);
	tb.registerProcess(&rfid, 1000.0f);
}

void loop() {
	tb.run();
}
