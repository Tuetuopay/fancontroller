/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

#include <hal.h>

#include "led.h"

static const uint32_t leds[] = {
	LINE_LED1,
	LINE_LED2,
	LINE_LED3,
	LINE_LED4,
	LINE_LED5,
	LINE_LED6,
	LINE_LED7,
	LINE_LED8
};

void ledInit(void) {
	for (unsigned i = 0; i < 8; i++) {
		palSetLineMode(leds[i], PAL_MODE_OUTPUT_PUSHPULL);
		ledOff(i);
	}
}

void ledOn(unsigned led) {
	if (led < 8)
		palClearLine(leds[led]);
}
void ledOff(unsigned led) {
	if (led < 8)
		palSetLine(leds[led]);
}
void ledToggle(unsigned led) {
	if (led < 8)
		palToggleLine(leds[led]);
}
