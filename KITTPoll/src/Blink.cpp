/*
 * Blink.cpp
 *
 *  Created on: 11 Oct 2022
 *      Author: jondurrant
 */

#include "Blink.h"
#include "pico/time.h"



Blink::Blink(uint8_t gp) {
	xLed = gp;
	gpio_init(xLed);
	gpio_set_dir(xLed, GPIO_OUT);
	gpio_put(xLed, 0);

	xLastStep = to_ms_since_boot (get_absolute_time ());
}

Blink::~Blink() {
	// NOP
}

void Blink::poll(){
	int32_t now = to_ms_since_boot (get_absolute_time ());

	if ((now - xLastStep) > BLINK_DELAY){
		xStep++;
		if (xStep > 1){
			xStep = 0;
		}
		gpio_put(xLed, xStep);
		xLastStep = now;
	}
}

