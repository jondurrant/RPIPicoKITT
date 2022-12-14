/*
 * Blink.h
 *
 * Pulse an LED on and off with 500ms interval
 *
 *  Created on: 11 Oct 2022
 *      Author: jondurrant
 */

#ifndef KITTPOLL_SRC_BLINK_H_
#define KITTPOLL_SRC_BLINK_H_

#include "pico/stdlib.h"

#define BLINK_DELAY 500

class Blink {
public:
	/***
	 * Constructor
	 * @param gp - GPIO Pad number that LED is connected to
	 */
	Blink(uint8_t gp=0);
	virtual ~Blink();

	/***
	 * Poll, call repeatably to get blink to occur
	 */
	void poll();
private:
	// GPIO Pad number
	uint8_t xLed;

	//Time since boot of the last step in MS
	uint32_t xLastStep = 0;

	// Current step
	uint32_t xStep = 0;

};

#endif /* KITTPOLL_SRC_BLINK_H_ */
