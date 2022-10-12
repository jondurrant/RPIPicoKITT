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
	/***
	 * Constructor
	 * Assumes use of consecutive GPIO PADs
	 * @param firstGp - GPIO Pad number for the first pad used for LEDs
	 * @param lastGp - GPIO Pad number for the last pad used for LEDs
	 */
	KITT(uint8_t firstGp=2, uint8_t lastGp=9);
	virtual ~KITT();

	/***
	 * Poll the animation
	 * Do a step if needed
	 */
	void poll();

private:
	// GPIO Pad numbers
	uint8_t xFirstLed;
	uint8_t xLastLed;

	//Time since boot of the last step in MS
	uint32_t xLastStep = 0;

	uint32_t xStep = 0;
	uint32_t xNumSteps = 0;
	uint32_t xNumLeds = 0;

};

#endif /* KITTPOLL_SRC_KITT_H_ */
