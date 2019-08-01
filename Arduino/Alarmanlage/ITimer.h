/*
 * ITimer.h
 *
 *  Created on: 31.07.2019
 *      Author: felix
 */

#ifndef ITIMER_H_
#define ITIMER_H_
#include <Arduino.h>

class ITimer {
public:
	ITimer(){};
	virtual ~ITimer(){};
	float cycleTime=0.0f, lastCycle=0.0f;
	virtual void timerEvent() = 0;
};

#endif /* ITIMER_H_ */
