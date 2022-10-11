/*
 * KITT.h
 *
 * Animate KITT Sensor LED across given GPIO range
 *
 *  Created on: 11 Oct 2022
 *      Author: jondurrant
 */

#ifndef KITTPOLL_SRC_KITT_H_
#define KITTPOLL_SRC_KITT_H_

#define KITT_DELAY 100

#include "pico/stdlib.h"

class KITT {
public:
	KITT(uint8_t firstGp=2, uint8_t lastGp=9);
	virtual ~KITT();

	void poll();

private:
	uint8_t xFirstLed;
	uint8_t xLastLed;

	//Time since boot of the last step in MS
	uint32_t xLastStep = 0;

	uint32_t xStep = 0;
	uint32_t xNumSteps = 0;
	uint32_t xNumLeds = 0;

};

#endif /* KITTPOLL_SRC_KITT_H_ */
