/*
 * TimerBank.cpp
 *
 *  Created on: 31.07.2019
 *      Author: felix
 */

#include "TimerBank.h"

void TimerBankClass::init(unsigned char maxProcessCount) {
	this->maxProcessCount = maxProcessCount;
	processes = new ITimer*[maxProcessCount];
	for (; maxProcessCount > 0; maxProcessCount--) {
		processes[maxProcessCount - 1] = 0;
	}
}

TimerBankClass::~TimerBankClass() {
	delete[] processes;
}

void TimerBankClass::registerProcess(ITimer *process, float cycle) {
	noInterrupts();
	if (currentProcessCount + 1 <= maxProcessCount) {
		for (unsigned char i = 0; i < currentProcessCount; i++) {
			if (processes[i] == process) {
				interrupts();
				return;
			}
		}
		process->cycleTime = cycle;
		processes[currentProcessCount++] = process;
		interrupts();
		process->timerEvent();
	} else {
		interrupts();
		Serial.println("TB full"); // Refactor someday
	}
}

void TimerBankClass::deRegisterProcess(ITimer *process) {
	noInterrupts();
	for (unsigned char i = 0; i < currentProcessCount; i++) {
		if (processes[i] == process) {
			processes[i]->finalize();
			processes[i] = 0;
			currentProcessCount--;
			reorderProcesses();
			break;
		}

	}
	interrupts();
}

void TimerBankClass::registerAction(ITimer *process, unsigned char delay) {
	noInterrupts();
	if (currentProcessCount + 1 <= maxProcessCount) {
		process->cycleTime = 0;
		processes[currentProcessCount++] = process;
	} else {
		Serial.println("TB full"); // Refactor someday
	}
	interrupts();
}

void TimerBankClass::reorderProcesses() {
	for (unsigned char i = 0; i < currentProcessCount + 1; i++) {
		if (processes[i] == 0) {
			processes[i] = processes[i + 1];
			processes[i + 1] = 0;
		}
	}
}

void TimerBankClass::run() {
	unsigned long currentTime = millis();
	for (unsigned char i = 0; i < currentProcessCount; i++) {
		if ((currentTime - processes[i]->lastCycle) > processes[i]->cycleTime) {
			processes[i]->lastCycle = currentTime;
			processes[i]->timerEvent();
			if (processes[i]->cycleTime == 0) {
				deRegisterProcess(processes[i]);
			}
		}
	}
}

void TimerBankClass::offerInterrupt(ITimer *process) {
	unsigned long currentTime = millis();
	noInterrupts();
	for (unsigned char i = 0; i < currentProcessCount; i++) {
		if ((processes[i] == process) & (currentTime - processes[i]->lastCycle) > processes[i]->cycleTime) {
			processes[i]->lastCycle = currentTime;
			interrupts();
			processes[i]->timerEvent();
			break;
		}
	}
	interrupts();
}

TimerBankClass TimerBank;
