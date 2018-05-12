/* THE BEER-WARE LICENSE (Revision 42):
 * tuetuopay at me dot com wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Tuetuopay.
 */

#include <hal.h>

#include "pwm.h"

static struct PwmLine {
	const uint32_t line;
	unsigned duty;
} lines[] = {
	{LINE_PWM0, 0},
	{LINE_PWM1, 0},
	{LINE_PWM2, 0},
	{LINE_PWM3, 0},
	{LINE_PWM4, 0},
	{LINE_PWM5, 0},
	{LINE_PWM6, 0},
	{LINE_PWM7, 0}
};

void timerTick(GPTDriver *gptp);

// Timer config
GPTConfig gptConfig = {
	// PWM should run at >> 20kHz or << 20Hz not to make noise
	// 100 steps would give a timer frequency of 2MHz, which is madness on a
	// 72MHz CPU
	// However, 40Hz is low enough of a frequency not to be noticeable
	.frequency = 40 * 1024, // = 4kHz timer
	.callback = timerTick,
	// In our case, we don't need those config registers
	.cr2 = 0, .dier = 0
};

void pwmInit(void) {
	for (unsigned i = 0; i < 8; i++) {
		palSetLineMode(lines[i].line, PAL_MODE_OUTPUT_PUSHPULL);
		palClearLine(lines[i].line);
	}

	// Start timer
	gptObjectInit(&GPTD4);
	gptStart(&GPTD4, &gptConfig);
	gptStartContinuous(&GPTD4, 1);
}

void pwmWrite(unsigned n, unsigned duty) {
	if (n < 8)
		lines[n].duty = duty;
}

void timerTick(GPTDriver *gptp) {
	(void)gptp;

	static unsigned ticks = 0;

	for (unsigned i = 0; i < 8; i++)
		if (ticks < lines[i].duty) palSetLine(lines[i].line);
		else                       palClearLine(lines[i].line);

	if (ticks++ >= 1024)
		ticks = 0;
}
