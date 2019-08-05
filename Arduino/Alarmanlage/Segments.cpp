#include "Segments.h"
#include "Globals.h"

Segments::Segments(int displayPins[4], int segmentPins[8]) :
		displayPins(displayPins), segmentPins(segmentPins) {
	for (int i = 0; i < 4; i++) {
		pinMode(displayPins[i], OUTPUT);
		digitalWrite(displayPins[i], HIGH);
	}
	for (int i = 0; i < 8; i++) {
		pinMode(segmentPins[i], OUTPUT);
		digitalWrite(segmentPins[i], LOW);
	}
}

void Segments::renderDisplay() {
	updateSources();
	for (int i = numberLength; i > 0; i--) {
		for (int j = 0; j < 8; j++) {
			digitalWrite(segmentPins[j], LOW);
		}
		digitalWrite(displayPins[i - 1], LOW);
		renderDigit(digits[i - 1]);
		delay(1);
		digitalWrite(displayPins[i - 1], HIGH);
	}
}

void Segments::setCountdown(int start) {
	countdown_running = true;
	countdownLength = number = start;
	countdownTimer = millis();
	while (start > 0) {
		numberLength++;
		start = start / 10;
	}
}

void Segments::updateSources() {
	if (countdown_running && millis() - countdownTimer > 1000) {
		updateCountdown();
		countdownTimer = millis();
	}
}

void Segments::updateCountdown() {
	if (number > 0 & number <= 9999) {
		int temp = number;
		numberLength = 0;
		while (0 < temp) {
			digits[numberLength] = temp % 10;
			temp /= 10;
			numberLength++;
		}
		number--;
	}
}

void Segments::timerEvent() {
	renderDisplay();
}

void Segments::renderDigit(int digit) {
	switch (digit) {
	case 0:
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		break;
	case 1:
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		break;
	case 2:
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		break;
	case 3:
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		break;
	case 4:
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		break;
	case 5:
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		break;
	case 6:
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		break;
	case 7:
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[0], HIGH);
		break;
	case 8:
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		break;
	case 9:
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[1], HIGH);
	}
}

