/*
 * ShiftRegister.cpp
 *
 *  Created on: 01.08.2019
 *      Author: felix
 */

#include "ShiftRegister.h"


ShiftRegister::ShiftRegister() {
	pinMode(DS, OUTPUT);
	pinMode(SH_CP, OUTPUT);
	pinMode(ST_CP, OUTPUT);
}

ShiftRegister::~ShiftRegister() {}

void ShiftRegister::setState(unsigned char state) {
	digitalWrite(SH_CP, LOW);
	digitalWrite(ST_CP, LOW);
	for (int i = 0; i<8; i++) {
		digitalWrite(SH_CP, LOW);
		digitalWrite(DS, state & 0x80);
		state = state << 1;
		digitalWrite(SH_CP, HIGH);
	}
	digitalWrite(ST_CP, HIGH);

}
