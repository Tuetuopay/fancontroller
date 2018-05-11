/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

#include <ch.h>
#include <hal.h>

#include <shell.h>
#include <chprintf.h>

#include "usbcfg.h"
#include "cli.h"

// Available commands
static const ShellCommand commands[] = {
	{NULL, NULL}
};

// Shell module configs
static const ShellConfig
	shellCfgUSB = {(BaseSequentialStream*)&SDU1, commands},
	shellCfgSerial = {(BaseSequentialStream*)&SD3, commands};

// Shell threads
static thread_t *cliThreadUSB = NULL, cliThreadSerial;

// Shell exit event
static void shellDisconnectedHandler(eventid_t id) {
	(void)id;

	// Is our shell thread terminated?
	if (chThdTerminatedX(cliThreadUSB)) {
		// Return dynamic thread memory to heap
		chThdWait(cliThreadUSB);
		cliThreadUSB = NULL;
	}
}

static const evhandler_t eHandlers[] = {shellDisconnectedHandler};
static event_listener_t el0;

/**
 * USB watcher thread.
 * When the USB bus becomes active without a running shell, creates a shell
 * on that USB
 */
static THD_WORKING_AREA(waUsbWatcherThd, 256);
static THD_FUNCTION(usbWatcherThd, arg) {
	(void)arg;

	// Name the thread
	chRegSetThreadName("USB watcher");

	// Disconnect from the USB
	usbDisconnectBus(serusbcfg.usbp);
	// Give host time to notice the disconnect
	chThdSleep(MS2ST(1500));
	// Start USB driver
	usbStart(serusbcfg.usbp, &usbcfg);
	// Re-enable pull-up on D+ (full speed) to tell the host we are back
	usbConnectBus(serusbcfg.usbp);

	while (true) {
		if (!cliThreadUSB && (SDU1.config->usbp->state == USB_ACTIVE))
			cliThreadUSB = chThdCreateFromHeap(
				NULL,                        // Default heap
				THD_WORKING_AREA_SIZE(2048), // Thread WA
				"USB cli",                   // Name
				NORMALPRIO + 1,              // Tad higher than normal
				shellThread,                 // Run this
				(void*)&shellCfgUSB          // With that config
			);

		// Poll events
		chEvtDispatch(eHandlers, chEvtWaitOneTimeout(ALL_EVENTS, MS2ST(500)));
		// Be nice :)
		chThdSleep(MS2ST(100));
	}
}

static THD_WORKING_AREA(waShellSerial, 2048);

// Serial config
SerialConfig serialCfg = {.speed = 115200, .cr1 = 0, .cr2 = 0, .cr3 = 0};

void cliInit(void) {
	// Setup USB pins
	palSetLineMode(LINE_USB_DM, PAL_MODE_STM32_ALTERNATE_OPENDRAIN);
	palSetLineMode(LINE_USB_DP, PAL_MODE_STM32_ALTERNATE_OPENDRAIN);

	// Initialize serial-usb driver
	sduObjectInit(&SDU1);
	sduStart(&SDU1, &serusbcfg);

	// Activates the shell system
	shellInit();

	// Run USB watcher thread
	chThdCreateStatic(
		waUsbWatcherThd, sizeof(waUsbWatcherThd), // Working area
		NORMALPRIO - 1,
		usbWatcherThd, NULL
	);

	// Listen for the shell exited event
	chEvtRegister(&shell_terminated, &el0, 0);

	// Setup serial pins
	sdStart(&SD3, &serialCfg);
	palSetLineMode(LINE_SCL_TXD, PAL_MODE_STM32_ALTERNATE_PUSHPULL);
	palSetLineMode(LINE_SDA_RXD, PAL_MODE_INPUT_PULLUP);

	// Run shell on serial port
	chThdCreateStatic(
		waShellSerial, sizeof(waShellSerial),
		NORMALPRIO + 1,
		shellThread, (void*)&shellCfgSerial
	);
}
