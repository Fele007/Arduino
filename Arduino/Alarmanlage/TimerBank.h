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
	void registerAction(ITimer *process, unsigned char delay); // to fill with life
	void deRegisterProcess(ITimer* process);
	void run();
	void offerInterrupt(ITimer* process);
	void init (unsigned char maxProcessCount);
private:
	ITimer** processes;
	unsigned char maxProcessCount;
	unsigned char currentProcessCount = 0;
	void reorderProcesses();
};

extern TimerBankClass TimerBank;

#endif /* TIMERBANK_H_ */
