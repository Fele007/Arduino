#ifndef SEGMENTS_H
#define SEGMENTS_H

#include "ISecurable.h"
#include "TimerBank.h"

class Segments : public ITimer, public ISecurable {

public:
	// Constructor
	Segments(int displayPins[4], int segmentPins[8]);
	// Methods
	void renderDisplay();
	void setCountdown(int start);
	void timerEvent();
	void unlock();

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
	void stopCountdown();
	// Timing
	void updateSources();
	void updateCountdown();
	// Helpers
	void renderDigit(int digit);

};

#endif
