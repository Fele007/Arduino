/*
 * Buzzer.cpp
 *
 *  Created on: 07.08.2019
 *      Author: felix
 */

#include "Buzzer.h"

Buzzer::Buzzer(int pin) :
		pin(pin) {
	pinMode(pin, OUTPUT);
}

Buzzer::~Buzzer() {
}

void Buzzer::buzz() {
	if (songIndex > 3) {
		songIndex = 0;
	}
	tone(pin, song[songIndex++]);
}

void Buzzer::timerEvent() {
	buzz();
}
