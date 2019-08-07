/*
 * TimerBank.cpp
 *
 *  Created on: 31.07.2019
 *      Author: felix
 */

#include "TimerBank.h"

void TimerBankClass::init(int maxProcessCount) {
	processCount = maxProcessCount;
	processes = new ITimer*[maxProcessCount];
}

TimerBankClass::~TimerBankClass() {
	delete[] processes;
}

void TimerBankClass::registerProcess(ITimer *process, float cycle) {
	if (currentProcess+1 <= processCount) {
		process->cycleTime = cycle;
		processes[currentProcess++] = process;
		process->timerEvent();
	}
}



void TimerBankClass::run() {
	unsigned long currentTime = millis();
	for (int i = 0; i < currentProcess; i++) {
		if ((currentTime - processes[i]->lastCycle) > processes[i]->cycleTime) {
			workingProcess = i;
			processes[i]->timerEvent();
			processes[i]->lastCycle = currentTime;
		}
	}
}

void TimerBankClass::offerInterrupt(ITimer *process) {
	unsigned long currentTime = millis();
	for (int i = 0; i < workingProcess; i++) {
		if ((currentTime - processes[i]->lastCycle) > processes[i]->cycleTime) {
			processes[i]->timerEvent();
			processes[i]->lastCycle = currentTime;
		}
	}
}

TimerBankClass TimerBank;
