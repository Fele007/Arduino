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
#include "ISecurable.h"
#include "TimerBank.h"
#include "Alarmanlage.h"

class RFID : public ITimer {
public:
	RFID(ISecurable* pISecurable...);
	virtual ~RFID();
	void init();
	void reset();

private:
	MFRC522 device;
	bool checkForCard();
	void validateAction();
	ISecurable* pISecurable;
	bool manipulation = false;
	void timerEvent();
};

#endif /* RFID_H_ */
