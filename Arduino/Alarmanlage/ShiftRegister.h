/*
 * ShiftRegister.h
 *
 *  Created on: 01.08.2019
 *      Author: felix
 */

#ifndef SHIFTREGISTER_H_
#define SHIFTREGISTER_H_

#include "Globals.h"

class ShiftRegister {
public:
	ShiftRegister();
	virtual ~ShiftRegister();
	void setState (unsigned char state);
};

#endif /* SHIFTREGISTER_H_ */
