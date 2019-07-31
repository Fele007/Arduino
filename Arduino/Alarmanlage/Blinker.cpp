#include "Blinker.h"

Blinker::Blinker(int frequenz) : frequenz(frequenz) {
	Serial.write("Frequenz gesetzt auf" + frequenz);
}

void Blinker::blinken() {
	digitalWrite(2, LOW);
	for(;;) {
		digitalWrite(2, HIGH);
		delay(1000/frequenz);
		digitalWrite(2, LOW);
		delay(1000/frequenz);
	}
}
