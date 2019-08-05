#ifndef SEGMENTS_H
#define SEGMENTS_H

#include "TimerBank.h"

class Segments : public ITimer {

public:
	// Constructor
	Segments(int displayPins[4], int segmentPins[8]);
	// Methods
	void renderDisplay();
	void setCountdown(int start);
	void timerEvent();

private:
	// General
	int *displayPins;
	int *segmentPins;
	int digits[4] = { 0 };
	int number = 0, numberLength = 0;
	// Countdown
	bool countdown_running = false;
	int countdownLength = 0;
	unsigned long countdownTimer;
	// Timing
	void updateSources();
	void updateCountdown();
	// Helpers
	void renderDigit(int digit);

};

#endif
