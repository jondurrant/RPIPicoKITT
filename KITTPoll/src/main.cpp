/***
 * KITT LED Animation on GP02 to GP09
 * Pulse LED on GP00
 * Jon Durrant
 * 10-Oct-2022
 */


#include "pico/stdlib.h"
#include <stdio.h>

#include "Blink.h"
#include "KITT.h"

//LED PAD to use
#define LED_PAD					0
#define LED_FIRST_PAD			2
#define LED_LAST_PAD			9


//Blink Delay
#define DELAY				100



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

    Blink blink(LED_PAD);
    KITT kitt(LED_FIRST_PAD, LED_LAST_PAD);

    for (;;){
    	blink.poll();
    	kitt.poll();
    }

}
