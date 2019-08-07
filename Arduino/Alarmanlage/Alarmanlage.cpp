#include "Globals.h"
#include "Blinker.h"
#include "Matrix.h"
#include "Segments.h"
#include "Info.h"
#include "ShiftRegister.h"
#include "RFID.h"
#include "TimerBank.h"

int displayPins[] = { D1, D2, D3, D4 };
int segmentPins[] = { A, B, C, D, E, F, G, DP };

Segments segments (displayPins, segmentPins);
ShiftRegister shiftRegister;
RFID rfid(&segments);

void setup() {
	// Communication
	Serial.begin(9600);
	SPI.begin();
	rfid.init();

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
