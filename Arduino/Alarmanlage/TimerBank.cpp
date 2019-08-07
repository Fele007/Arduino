/*
 * TimerBank.cpp
 *
 *  Created on: 31.07.2019
 *      Author: felix
 */

#include "TimerBank.h"

TimerBankClass::~TimerBankClass() {
	delete[] processes;
}

void TimerBankClass::registerProcess(ITimer *process, float cycle) {
		process->cycleTime = cycle;
		processes[currentProcesses] = process;
		currentProcesses++;
}

void TimerBankClass::registerProcess(ITimer *process, float cycle, boolean startNow) {
		process->cycleTime = cycle;
		processes[currentProcesses] = process;
		currentProcesses++;
		if (startNow) process->timerEvent();
}


void TimerBankClass::run() {
	unsigned long currentTime = millis();
	for (int i = 0; i < currentProcesses; i++) {
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
