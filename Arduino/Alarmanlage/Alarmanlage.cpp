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
#include "Gyro.h"

int displayPins[] = { D1, D2, D3, D4 };
int segmentPins[] = { A, B, C, D, E, F, G, DP };

Segments segments(displayPins, segmentPins);
ShiftRegister shiftRegister;
RFID rfid(&segments);
Buzzer buzzer(BUZZER);
Gyro gyro;

static Alarmanlage::state Alarmanlage::currentState = Alarmanlage::state::LOCKED;

void setup() {
	// Initialization
	Serial.begin(9600);
	SPI.begin();
	rfid.init();
	TimerBank.init(4);

	// Shift Register
	shiftRegister.setState(0b00000010);

	// Timer+++++++++++++++++++++++++++++++++++++++++++++++++++
	TimerBank.registerProcess(&segments, 5.0f);
	TimerBank.registerProcess(&rfid, 1000.0f);
	TimerBank.registerProcess(&gyro, 10.0f);
}

void loop() {
	TimerBank.run();
	if (Alarmanlage::currentState == Alarmanlage::state::ALERT) {
		TimerBank.registerProcess(&buzzer, 500.0f);
		shiftRegister.setState(0b00000010);
	} else if (Alarmanlage::currentState == Alarmanlage::state::UNLOCKED) {
		shiftRegister.setState(0b00100000);
		rfid.init();
	} else if (Alarmanlage::currentState == Alarmanlage::state::LOCKED) {
		shiftRegister.setState(0b00000000);
	} else if (Alarmanlage::currentState == Alarmanlage::state::DETECTED) {
		segments.setCountdown(10);
		shiftRegister.setState(0b00000010);
	}

}

