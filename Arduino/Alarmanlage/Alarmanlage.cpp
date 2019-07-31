#include <Arduino.h>
#include "Blinker.h"
#include "Matrix.h"
#include "Globals.h"
#include "Segments.h"

Segments *segments;

void setup() {
	Serial.begin(9600);
	int displayPins[] = { D1, D2, D3, D4 };
	int segmentPins[] = { A, B, C, D, E, F, G, DP };
	segments = new Segments(displayPins, segmentPins);
	segments->setCountdown(10);
}

void loop() {
	segments->renderDisplay();

}

