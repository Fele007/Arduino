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

Gyro::~Gyro() {}

