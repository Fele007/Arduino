/*
 * TimerBank.cpp
 *
 *  Created on: 31.07.2019
 *      Author: felix
 */

#include "TimerBank.h"

TimerBank::TimerBank(int maxProcessCount) : processCount(maxProcessCount) {
	processes = new ITimer* [maxProcessCount];
}

TimerBank::~TimerBank() {
	delete [] processes;
}

void TimerBank::registerProcess(ITimer* process, float cycle) {
	process->cycleTime=cycle;
	processes[currentProcess++] = process;
}

void TimerBank::run() {
	for (int i = 0; i<currentProcess; i++) {
		if ((millis()-processes[i]->lastCycle)>processes[i]->cycleTime) {
			processes[i]->timerEvent();
			processes[i]->lastCycle=millis();
		}
	}
}
