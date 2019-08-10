/*
 * Buzzer.h
 *
 *  Created on: 07.08.2019
 *      Author: felix
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "Globals.h"
#include "TimerBank.h"

class Buzzer : public ITimer {
public:
	Buzzer(int pin);
	void buzz();
	virtual ~Buzzer();
private:
	int pin;
	unsigned char songIndex=0;
	int song [4] = {440, 1000, 440 ,700};
	void timerEvent();
	void finalize();
};

#endif /* BUZZER_H_ */
