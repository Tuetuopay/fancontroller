/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

#include "hal.h"

/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
#if HAL_USE_PAL || defined(__DOXYGEN__)
const PALConfig pal_default_config = {
	{VAL_GPIOAODR, VAL_GPIOACRL, VAL_GPIOACRH},
	{VAL_GPIOBODR, VAL_GPIOBCRL, VAL_GPIOBCRH},
	{VAL_GPIOCODR, VAL_GPIOCCRL, VAL_GPIOCCRH},
	{VAL_GPIODODR, VAL_GPIODCRL, VAL_GPIODCRH},
	{VAL_GPIOEODR, VAL_GPIOECRL, VAL_GPIOECRH},
};
#endif

/*
 * Early initialization code.
 * This initialization must be performed just after stack setup and before
 * any other initialization.
 */
void __early_init(void) { stm32_clock_init(); }

/*
 * Board-specific initialization code.
 */
void boardInit(void) {
	// We do not use full-blown JTAG, but simpler SWD, thus repurpose JNTRST
	// (PB4) and JTDI (PA15) as GPIOs.
	// That's especially useful since they are used for LED8 and LED7.
	AFIO->MAPR &= ~AFIO_MAPR_SWJ_CFG;
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;
}
