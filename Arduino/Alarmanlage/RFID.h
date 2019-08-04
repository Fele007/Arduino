/*
 * RFID.h
 *
 *  Created on: 04.08.2019
 *      Author: felix
 */

#ifndef RFID_H_
#define RFID_H_
#include <mfrc522.h>
#include "Globals.h"
#include "ITimer.h"

class RFID : public ITimer {
public:
	RFID();
	virtual ~RFID();
	void timerEvent();

private:
	MFRC522 device;
	MFRC522::Uid currentUid;
};

#endif /* RFID_H_ */
