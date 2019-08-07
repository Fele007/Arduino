#include "Globals.h"
#include "Blinker.h"
#include "Matrix.h"
#include "Segments.h"
#include "Info.h"
#include "ShiftRegister.h"
#include "RFID.h"
#include "TimerBank.h"
#include "Buzzer.h"
#include "Alarmanlage.h"

int displayPins[] = { D1, D2, D3, D4 };
int segmentPins[] = { A, B, C, D, E, F, G, DP };

Segments segments (displayPins, segmentPins);
ShiftRegister shiftRegister;
RFID rfid(&segments);
Buzzer buzzer(BUZZER);

static Alarmanlage::state Alarmanlage::currentState = Alarmanlage::state::LOCKED;

void setup() {
	// Initialization
	Serial.begin(9600);
	SPI.begin();
	rfid.init();

	// Shift Register
	shiftRegister.setState(0b00000000);

	// Segmentanzeige++++++++++++++++++++++++++++++++++++++++++
	segments.setCountdown(10);

	// Timer+++++++++++++++++++++++++++++++++++++++++++++++++++
	TimerBank.registerProcess(&segments, 5.0f);
	TimerBank.registerProcess(&rfid, 1000.0f);
}

void loop() {
	//TimerBank.run();
	if (Alarmanlage::currentState == Alarmanlage::state::ALERT) {
		TimerBank.registerProcess(&buzzer, 500.0f, true);
	}

}


