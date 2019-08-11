/*
 * Alarmanlage.h
 *
 *  Created on: 07.08.2019
 *      Author: felix
 */

#ifndef ALARMANLAGE_H_
#define ALARMANLAGE_H_

class Alarmanlage {
public:
	enum state {LOCKED, UNLOCKED, DETECTED, ALERT};
	static volatile state currentState;
	static void ISR_Motion();
};



#endif /* ALARMANLAGE_H_ */
