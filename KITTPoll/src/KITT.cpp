/*
 * KITT.cpp
 * Animate KITT Sensor LED across given GPIO range
 *  Created on: 11 Oct 2022
 *      Author: jondurrant
 */

#include "KITT.h"
#include "pico/time.h"
#include <stdio.h>

/***
 * Constructor
 * Assumes use of consecutive GPIO PADs
 * @param firstGp - GPIO Pad number for the first pad used for LEDs
 * @param lastGp - GPIO Pad number for the last pad used for LEDs
 */
KITT::KITT(uint8_t firstGp, uint8_t lastGp) {
	xFirstLed = firstGp;
	xLastLed  = lastGp;
	if (lastGp < firstGp){
		xLastLed = firstGp;
	}

	// Initialise the GPIO Pads
	for (int i = xFirstLed; i <= xLastLed; i++){
		gpio_init(i);
		gpio_set_dir(i, GPIO_OUT);
		gpio_put(i, 0);
	}

	// Store the current time
	xLastStep = to_ms_since_boot (get_absolute_time ());

	xNumLeds = (xLastLed - xFirstLed + 1);
	xNumSteps = xNumLeds * 2 - 1;
}


KITT::~KITT() {
	// NOP
}

/***
 * Poll the animation
 * Do a step if needed
 */
void KITT::poll(){
	int32_t now = to_ms_since_boot (get_absolute_time ());

	if ((now - xLastStep) > KITT_DELAY){

		//Step sequence management
		xStep++;
		if (xStep > xNumSteps){
			xStep = 0;
		}

		uint8_t led = 0;
		uint8_t pLed = 0;

		//Calculate the LED to turn on and off
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
