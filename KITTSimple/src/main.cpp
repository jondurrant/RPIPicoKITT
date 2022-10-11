/***
 * KITT LED Sensor display on 8 LEDs
 * GP02 to GP09
 * Jon Durrant
 * 11-Oct-2022
 */


#include "pico/stdlib.h"
#include <stdio.h>


//LED PAD to use
#define LED_PAD					0
#define LED_FIRST_PAD			2
#define LED_LAST_PAD			9


//Blink Delay
#define DELAY				100





/***
 * Run KITT demo as a function
 * @param params
 */
void mainKITT(){
	uint i = 0;

	// Init Pads
	for (i= LED_FIRST_PAD; i <= LED_LAST_PAD; i++){
		gpio_init(i);
		gpio_set_dir(i, GPIO_OUT);
		gpio_put(i, 0);
	}

	// Loop forever
	for(;;){

		//Up Loop
		for (i= LED_FIRST_PAD; i <= LED_LAST_PAD; i++){
			gpio_put(i, 1);
			sleep_ms(DELAY);
			gpio_put(i, 0);
		}

		//Down Loop
		for (i= LED_LAST_PAD;i >= LED_FIRST_PAD; i--){
			gpio_put(i, 1);
			sleep_ms(DELAY);
			gpio_put(i, 0);
		}
	}

}




/***
 * Main
 * @return
 */
int main( void )
{
	//Setup serial over USB and give a few seconds to settle before we start
    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    mainKITT();

}
