/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

/**
 * PWM
 *
 * Software PWM driver, since all timers are already used.
 */

#ifndef _DRIVER_PWM_H
#define _DRIVER_PWM_H

/**
 * Setups PWM driver
 */
void pwmInit(void);

/**
 * Sets duty cycle for a specific channel
 * @param n     Channel to set, <8
 * @param duty  Value to write, <1024
 */
void pwmWrite(unsigned n, unsigned duty);

#endif
