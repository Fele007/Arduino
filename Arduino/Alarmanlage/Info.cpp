/*
 * Info.cpp
 *
 *  Created on: 01.08.2019
 *      Author: felix
 */

#include "Info.h"
#include <Arduino.h>

Info::Info(char* t) {
	text = t;
}

Info::~Info() {
	// TODO Auto-generated destructor stub
}

void Info::timerEvent() {
	Serial.println(text);
}
