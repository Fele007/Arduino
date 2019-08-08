/*
 * RFID.cpp
 *
 *  Created on: 04.08.2019
 *      Author: felix
 */

#include "RFID.h"

RFID::RFID(ISecurable *pISecurable...) : pISecurable(pISecurable) {
	device = MFRC522(CS_RFID, RST_RFID);
}

RFID::~RFID() {
}

void RFID::init() {
	device.PCD_Init(); //Initialization seems to cause problems
	manipulation = false;
}

bool RFID::checkForCard() {
	if (device.PICC_IsNewCardPresent() && device.PICC_ReadCardSerial()) {
		// Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
		device.PICC_HaltA();
		return true;
	}
	return false;
}

void RFID::validateAction() {
	unsigned long key = 0b100000000000000000000000000000000L;
	for (byte i = 0; i < device.uid.size; i++) {
		key |= ((unsigned long) device.uid.uidByte[i])
				<< 8 * (device.uid.size - 1 - i);
	}
	switch (key) {
	case 0xCD49DAD9:
		if (!manipulation & (Alarmanlage::currentState==Alarmanlage::state::DETECTED  | Alarmanlage::currentState==Alarmanlage::state::LOCKED | Alarmanlage::currentState == Alarmanlage::state::ALERT)) {
			pISecurable->unlock();
			Alarmanlage::currentState = Alarmanlage::state::UNLOCKED;
		}
		else if (Alarmanlage::currentState==Alarmanlage::state::UNLOCKED) {
			Alarmanlage::currentState=Alarmanlage::state::LOCKED;
		}
		break;
	default:
		manipulation = true;
		Alarmanlage::currentState = Alarmanlage::state::ALERT;
	}
}

void RFID::timerEvent() {
	if (checkForCard()) {
		validateAction();
	}

}
