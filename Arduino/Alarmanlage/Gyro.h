/*
 * Gyro.h
 *
 *  Created on: 08.08.2019
 *      Author: felix
 */

#ifndef GYRO_H_
#define GYRO_H_
#include "Globals.h"
#include "ITimer.h"
#include "TinyMPU6050.h"

class Gyro : public ITimer {
public:
	Gyro();
	virtual ~Gyro();
	void initialize();
private:
	MPU6050 device;
	void timerEvent();
	bool checkMovement();
};

#endif /* GYRO_H_ */
