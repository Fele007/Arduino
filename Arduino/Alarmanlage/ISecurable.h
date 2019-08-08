/*
 * ISerucable.h
 *
 *  Created on: 07.08.2019
 *      Author: felix
 */

#ifndef ISECURABLE_H_
#define ISECURABLE_H_

class ISecurable {
protected:
	virtual void unlock() = 0;

	friend class RFID;
};



#endif /* ISECURABLE_H_ */
