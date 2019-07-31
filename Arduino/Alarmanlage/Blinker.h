#ifndef BLINKER_H
#define BLINKER_H

#include <Arduino.h>

class Blinker {
public:
	int frequenz;
	Blinker(int frequenz);
	void setFrequenz (int frequenz);
	void blinken();
};

#endif
