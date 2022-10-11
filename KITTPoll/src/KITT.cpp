/*
 * KITT.cpp
 *
 *  Created on: 11 Oct 2022
 *      Author: jondurrant
 */

#include "KITT.h"
#include "pico/time.h"
#include <stdio.h>


KITT::KITT(uint8_t firstGp, uint8_t lastGp) {
	xFirstLed = firstGp;
	xLastLed  = lastGp;
	if (lastGp < firstGp){
		xLastLed = firstGp;
	}

	for (int i = xFirstLed; i <= xLastLed; i++){
		gpio_init(i);
		gpio_set_dir(i, GPIO_OUT);
		gpio_put(i, 0);
	}

	xLastStep = to_ms_since_boot (get_absolute_time ());

	xNumLeds = (xLastLed - xFirstLed + 1);
	xNumSteps = xNumLeds * 2 - 1;
}

KITT::~KITT() {
	// TODO Auto-generated destructor stub
}


void KITT::poll(){
	int32_t now = to_ms_since_boot (get_absolute_time ());

	if ((now - xLastStep) > KITT_DELAY){
		xStep++;
		if (xStep > xNumSteps){
			xStep = 0;
		}

		uint8_t led = 0;
		uint8_t pLed = 0;


		if (xStep < xNumLeds){
			led = xStep + xFirstLed;
			pLed = led - 1;
		} else {
			led = (xNumLeds - (xStep - xNumLeds)) + xFirstLed - 1;
			pLed = led + 1;
		}
		gpio_put(led, 1);

		//Turn off prev LED
		if ((pLed >= xFirstLed) && (pLed <= xLastLed)){
			gpio_put(pLed, 0);
		}

		xLastStep = now;
	}

}
