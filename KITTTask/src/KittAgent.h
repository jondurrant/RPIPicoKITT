/*
 * KittAgent.h
 *
 *  Created on: 9 Oct 2022
 *      Author: jondurrant
 */

#ifndef SRC_KITTAGENT_H_
#define SRC_KITTAGENT_H_

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "Agent.h"

#define KITT_DELAY 100

class KittAgent: public Agent  {
public:
	/***
	 * Constructor
	 * @param gpFirst - GPIO Pad of the first LED
	 * @param gpLast  - GPIO Pad of the last LED
	 */
	KittAgent(uint8_t gpFirst=2, uint8_t gpLast=9);
	virtual ~KittAgent();

protected:

	/***
	 * Run loop for the agent.
	 */
	virtual void run();


	/***
	 * Get the static depth required in words
	 * @return - words
	 */
	virtual configSTACK_DEPTH_TYPE getMaxStackSize();

	//GPIO PAD for LEDs
	uint8_t xLedFirst;
	uint8_t xLedLast;
};

#endif /* SRC_KITTAGENT_H_ */
