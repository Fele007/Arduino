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
	static state currentState;
};



#endif /* ALARMANLAGE_H_ */
