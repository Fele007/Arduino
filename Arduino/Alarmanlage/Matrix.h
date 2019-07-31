#ifndef MATRIX_H
#define MATRIX_H

#include <Arduino.h>

class Matrix {
public:
	static unsigned char disp1;
	static unsigned char Lollo;

	Matrix();

	void initialize();
	void writeByte (unsigned char data);
	void write (unsigned char address, unsigned char data);
};

#endif
