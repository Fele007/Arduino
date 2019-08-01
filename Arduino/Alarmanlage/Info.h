/*
 * Info.h
 *
 *  Created on: 01.08.2019
 *      Author: felix
 */

#ifndef INFO_H_
#define INFO_H_
#include "ITimer.h"

class Info : public ITimer {
public:
	Info(char* text);
	virtual ~Info();
	void timerEvent();
	char* text;
};

#endif /* INFO_H_ */
