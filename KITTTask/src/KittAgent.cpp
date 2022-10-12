/*
 * KittAgent.cpp
 *
 *  Created on: 9 Oct 2022
 *      Author: jondurrant
 */

#include "KittAgent.h"
#include <stdio.h>


/***
 * Constructor
 * @param gpFirst - GPIO Pad of the first LED
 * @param gpLast  - GPIO Pad of the last LED
 */
KittAgent::KittAgent(uint8_t gpFirst, uint8_t gpLast) {
	xLedFirst = gpFirst;
	xLedLast = gpLast;
}

KittAgent::~KittAgent() {
	stop();
}


/***
 * Run loop for the agent.
 */
void KittAgent::run(){
	uint i = 0;

	// Init Pads
	for (i= xLedFirst;  i <= xLedLast; i++){
		gpio_init(i);
		gpio_set_dir(i, GPIO_OUT);
		gpio_put(i, 0);
	}

	// Loop forever
	for(;;){

		//Up Loop
		for (i= xLedFirst; i <= xLedLast; i++){
			gpio_put(i, 1);
			vTaskDelay(KITT_DELAY);
			gpio_put(i, 0);
		}

		//Down Loop
		for (i= xLedLast; i >= xLedFirst; i--){
			gpio_put(i, 1);
			vTaskDelay(KITT_DELAY);
			gpio_put(i, 0);
		}
	}
}

/***
 * Get the static depth required in words
 * @return - words
 */
configSTACK_DEPTH_TYPE KittAgent::getMaxStackSize(){
	return 250;
}
