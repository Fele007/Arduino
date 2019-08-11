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

static volatile Alarmanlage::state Alarmanlage::currentState = Alarmanlage::state::LOCKED;

void setup() {
	// Initialization
	Serial.begin(9600);
	SPI.begin();
	rfid.init();
	gyro.initialize();
	TimerBank.init(10);

	// Shift Register
	shiftRegister.setState(0b00000010);

	// Timer+++++++++++++++++++++++++++++++++++++++++++++++++++
	TimerBank.registerProcess(&segments, 3.0f);
	TimerBank.registerProcess(&rfid, 400.0f);
}

void loop() {
	TimerBank.run();
	if (Alarmanlage::currentState == Alarmanlage::state::ALERT) {
		detachInterrupt(digitalPinToInterrupt(INT_RFID));
		TimerBank.registerProcess(&buzzer, 500.0f);
		shiftRegister.setState(0b00000010);
	} else if (Alarmanlage::currentState == Alarmanlage::state::UNLOCKED) {
		detachInterrupt(digitalPinToInterrupt(INT_RFID));
		shiftRegister.setState(0b00100000);
		rfid.reset();
		TimerBank.deRegisterProcess(&buzzer);
	} else if (Alarmanlage::currentState == Alarmanlage::state::LOCKED) {
		shiftRegister.setState(0b00000000);
		attachInterrupt(digitalPinToInterrupt(INT_RFID), Alarmanlage::ISR_Motion, RISING);
	} else if (Alarmanlage::currentState == Alarmanlage::state::DETECTED) {
		detachInterrupt(digitalPinToInterrupt(INT_RFID));
		segments.setCountdown(10);
		shiftRegister.setState(0b00000010);
	}
}

static void Alarmanlage::ISR_Motion() {
	if (Alarmanlage::currentState == Alarmanlage::state::LOCKED)
		Alarmanlage::currentState = Alarmanlage::state::DETECTED;
}

