/*
 * Gyro.cpp
 *
 *  Created on: 08.08.2019
 *      Author: felix
 */

#include "Gyro.h"
#include "Alarmanlage.h"

Gyro::Gyro() :
		device(MPU6050(Wire)) {
}

void Gyro::initialize() {
	device.Initialize();
}

Gyro::~Gyro() {
	// TODO Auto-generated destructor stub
}

void Gyro::timerEvent() {
	if (Alarmanlage::currentState == Alarmanlage::state::LOCKED) {
		if (checkMovement()) {
			Alarmanlage::currentState = Alarmanlage::state::DETECTED;
		}
	}
}

bool Gyro::checkMovement() {
	device.Execute();
	float accX = device.GetAccX();
	float accY = device.GetAccY();
	if (accX > 0.04 | accX < -0.04 | accY > 0.04 | accY < -0.04) {
		return true;
	}
	return false;
}

