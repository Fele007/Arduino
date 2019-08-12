/*
 * Gyro.h
 *
 *  Created on: 08.08.2019
 *      Author: felix
 */

#ifndef GYRO_H_
#define GYRO_H_
#include "Globals.h"
#include "TinyMPU6050.h"

class Gyro {
public:
	Gyro();
	virtual ~Gyro();
	void initialize();
private:
	MPU6050 device;
};

#endif /* GYRO_H_ */
