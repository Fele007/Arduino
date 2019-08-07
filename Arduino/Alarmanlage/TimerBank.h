/*
 * TimerBank.h
 *
 *  Created on: 31.07.2019
 *      Author: felix
 */

#ifndef TIMERBANK_H_
#define TIMERBANK_H_
#include "Globals.h"
#include "ITimer.h"


class TimerBankClass {
public:
	virtual ~TimerBankClass();
	void registerProcess(ITimer* process, float cycle);
	void registerProcess(ITimer* process, float cycle, boolean startNow);
	void run();
	void offerInterrupt(ITimer* process);
private:
	ITimer* processes[];
	unsigned char workingProcess=0;
	unsigned char currentProcesses = 0;
};

extern TimerBankClass TimerBank;

#endif /* TIMERBANK_H_ */
