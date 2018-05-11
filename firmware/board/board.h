/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

#ifndef _BOARD_BOARD_H_
#define _BOARD_BOARD_H_

/*
 * Setup for the FanController board.
 */

/*
 * Board identifier.
 */
#define BOARD_FAN_CONTROLLER
#define BOARD_NAME              "FanController"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F103xB

/*
 * IO pins assignments
 */

#define GPIOA_PWM0              0
#define GPIOA_TAC0              1
#define GPIOA_PWM1              2
#define GPIOA_TAC1              3
#define GPIOA_LED1              4
#define GPIOA_LED2              5
#define GPIOA_PWM2              6
#define GPIOA_TAC2              7
#define GPIOA_LED4              8
#define GPIOA_LED5              9
#define GPIOA_LED6              10
#define GPIOA_USB_DM            11
#define GPIOA_USB_DP            12
#define GPIOA_LED7              15

#define GPIOB_PWM3              0
#define GPIOB_TAC3              1
#define GPIOB_LED3              2
#define GPIOB_LED8              4
#define GPIOB_USB_PU            5
#define GPIOB_PWM6              6
#define GPIOB_TAC6              7
#define GPIOB_PWM7              8
#define GPIOB_TAC7              9
#define GPIOB_SCL_TXD           10
#define GPIOB_SDA_RXD           11
#define GPIOB_PWM4              12
#define GPIOB_TAC4              13
#define GPIOB_PWM5              14
#define GPIOB_TAC5              15

// Port C is not used

#define GPIOD_OSC_IN            0
#define GPIOD_OSC_OUT           1

/*
 * IO lines assignments.
 */
#define LINE_PWM0              PAL_LINE(GPIOA, 0)
#define LINE_TAC0              PAL_LINE(GPIOA, 1)
#define LINE_PWM1              PAL_LINE(GPIOA, 2)
#define LINE_TAC1              PAL_LINE(GPIOA, 3)
#define LINE_LED1              PAL_LINE(GPIOA, 4)
#define LINE_LED2              PAL_LINE(GPIOA, 5)
#define LINE_PWM2              PAL_LINE(GPIOA, 6)
#define LINE_TAC2              PAL_LINE(GPIOA, 7)
#define LINE_LED4              PAL_LINE(GPIOA, 8)
#define LINE_LED5              PAL_LINE(GPIOA, 9)
#define LINE_LED6              PAL_LINE(GPIOA, 10)
#define LINE_USB_DM            PAL_LINE(GPIOA, 11)
#define LINE_USB_DP            PAL_LINE(GPIOA, 12)
#define LINE_LED7              PAL_LINE(GPIOA, 15)

#define LINE_PWM3              PAL_LINE(GPIOB, 0)
#define LINE_TAC3              PAL_LINE(GPIOB, 1)
#define LINE_LED3              PAL_LINE(GPIOB, 2)
#define LINE_LED8              PAL_LINE(GPIOB, 4)
#define LINE_USB_PU            PAL_LINE(GPIOB, 5)
#define LINE_PWM6              PAL_LINE(GPIOB, 6)
#define LINE_TAC6              PAL_LINE(GPIOB, 7)
#define LINE_PWM7              PAL_LINE(GPIOB, 8)
#define LINE_TAC7              PAL_LINE(GPIOB, 9)
#define LINE_SCL_TXD           PAL_LINE(GPIOB, 10)
#define LINE_SDA_RXD           PAL_LINE(GPIOB, 11)
#define LINE_PWM4              PAL_LINE(GPIOB, 12)
#define LINE_TAC4              PAL_LINE(GPIOB, 13)
#define LINE_PWM5              PAL_LINE(GPIOB, 14)
#define LINE_TAC5              PAL_LINE(GPIOB, 15)

// Port C is not used

#define LINE_OSC_IN            PAL_LINE(GPIOD, 0)
#define LINE_OSC_OUT           PAL_LINE(GPIOD, 1)

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up.
 */
#define VAL_GPIOACRL            0x00000000      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x00000000      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFF

/*
 * Port B setup.
 * Everything input floating
 */
#define VAL_GPIOBCRL            0x00000000      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x00000000      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input floating:
 */
#define VAL_GPIOCCRL            0x00000000      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x00000000      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input floating except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 */
#define VAL_GPIODCRL            0x00000044      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x00000000      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input floating:
 */
#define VAL_GPIOECRL            0x00000000      /*  PE7...PE0 */
#define VAL_GPIOECRH            0x00000000      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

/*
 * USB bus activation macro, required by the USB driver.
 */
#define usb_lld_connect_bus(usbp)

/*
 * USB bus de-activation macro, required by the USB driver.
 */
#define usb_lld_disconnect_bus(usbp)

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
