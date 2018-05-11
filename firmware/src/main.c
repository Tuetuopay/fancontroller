/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

#include <ch.h>
#include <hal.h>

#define ever (;;)

#include "lib/cli.h"

int main(void) {
	// Init HAL and kernel
	halInit();
	chSysInit();

	cliInit();

	// Setup blinkies
	palSetLineMode(LINE_LED1, PAL_MODE_OUTPUT_PUSHPULL);

	for ever {
		palToggleLine(LINE_LED1);
		chThdSleep(MS2ST(200));
	}
}
