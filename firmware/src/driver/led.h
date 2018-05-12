/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

/**
 * LED
 *
 * Shorthand functions to control the LEDs
 */

#ifndef _DRIVER_LED_H
#define _DRIVER_LED_H

/**
 * Initializes the LEDs
 */
void ledInit(void);

/**
 * Turn on LED
 */
void ledOn(unsigned led);
/**
 * Turn LED off
 */
void ledOff(unsigned led);
/**
 * Toggle LED
 */
void ledToggle(unsigned led);

#endif
