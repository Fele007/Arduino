/*
 * RFID.cpp
 *
 *  Created on: 04.08.2019
 *      Author: felix
 */

#include "RFID.h"
#include "Globals.h"

RFID::RFID() {
	device = MFRC522(CS_RFID, RST_RFID);
	//device.PCD_Init(); Initialization seems to cause problems
}

RFID::~RFID() {
}

void RFID::timerEvent() {
		  if (device.PICC_IsNewCardPresent() && device.PICC_ReadCardSerial() ) {
		    Serial.print("Gelesene UID:");
		    for (byte i = 0; i < device.uid.size; i++) {
		      // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
		      Serial.print(device.uid.uidByte[i] < 0x10 ? " 0" : " ");
		      Serial.print(device.uid.uidByte[i], HEX);
		      tb.offerInterrupt(this);
		    }
		    Serial.println();
		    // Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
		    device.PICC_HaltA();
		  }
}

