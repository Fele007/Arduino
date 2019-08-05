/*
 * TimerBank.h
 *
 *  Created on: 31.07.2019
 *      Author: felix
 */

#ifndef TIMERBANK_H_
#define TIMERBANK_H_
#include "ITimer.h"


class TimerBank {
public:
	TimerBank(int maxProcessCount);
	virtual ~TimerBank();
	void registerProcess(ITimer* process, float cycle);
	void run();
	void offerInterrupt(ITimer* process);
private:
	ITimer** processes;
	int processCount;
	int currentProcess = 0;
};



#endif /* TIMERBANK_H_ */
