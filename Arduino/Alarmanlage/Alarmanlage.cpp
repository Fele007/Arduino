#include <Arduino.h>
#include "Blinker.h"
#include "Matrix.h"
#include "Globals.h"
#include "Segments.h"
#include "TimerBank.h"
#include "Info.h"
#include "ShiftRegister.h"

Segments *segments;
TimerBank *tb;
Info *info;
ShiftRegister *shiftRegister;

void setup() {
	//Serial.begin(9600);
	int displayPins[] = { D1, D2, D3, D4 };
	int segmentPins[] = { A, B, C, D, E, F, G, DP };

	//segments = new Segments(displayPins, segmentPins);
	//segments->setCountdown(10);

	//tb = new TimerBank(2);
	//tb->registerProcess(segments, 5.0f);

	shiftRegister = new ShiftRegister();

}

void loop() {
	//tb->run();
	for (int i = 0; i < 100; i++) {
		shiftRegister->setState(0b00100010);
		delay(700);
		shiftRegister->setState(0b00100000);
		delay(700);
		shiftRegister->setState(0);
		delay(700);
		shiftRegister->setState(0b00000010);
		delay(700);
		shiftRegister->setState(0);
		delay(700);
	}
}
