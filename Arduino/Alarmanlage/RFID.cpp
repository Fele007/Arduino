/*
 * RFID.cpp
 *
 *  Created on: 04.08.2019
 *      Author: felix
 */

#include "RFID.h"

RFID::RFID() {
	device = MFRC522(CS_RFID, RST_RFID);
}

RFID::~RFID() {
}

void RFID::init() {
	device.PCD_Init(); //Initialization seems to cause problems
}

bool RFID::checkForCard() {
	if (device.PICC_IsNewCardPresent() && device.PICC_ReadCardSerial()) {
		Serial.print("Gelesene UID:");
		for (byte i = 0; i < device.uid.size; i++) {
			// Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
			Serial.print(device.uid.uidByte[i] < 0x10 ? " 0" : " ");
			Serial.print(device.uid.uidByte[i], HEX);
		}
		Serial.println();
		// Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
		device.PICC_HaltA();
		return true;
	}
	return false;
}

void RFID::validateAction() {
	int key = 0b0;
	for (byte i = 0; i < device.uid.size; i++) {
		key |= device.uid.uidByte[i] << 8*(device.uid.size-1-i);
		Serial.println(key, BIN);
	}
	Serial.println(key, BIN);
}

void RFID::timerEvent() {
	if (checkForCard()) {
		validateAction();
	}

}

