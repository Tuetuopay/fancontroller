# FanController

*Creative naming?* What is this?

Rheobus project rooted from a simple problem: all my PC fans are DC only (the
three wire kind), but my motherboard only supports PWM*. And why buy a
commercial one? Let's make my own!

*Even if it does, shhhh! This is a good excuse for a project!

## Hardware

Simple PCB designed with Eagle. It can control up to 8 fans, with an STM32F103
as a brain. On the extra side, there is an LED for each channel, because
blinkenlights are cool. For communications, this is scarce: a USB port and
UART or I2C header.

The PCB is mostly finished, some refinements may be needed. It is well under
10cm x 10cm to be ordered on the cheap from the likes of DirtyPCB or JLCPCB.

All parts are SMD (except for headers and the one quartz), but do not go smaller
than 0603 resistors, easily solderable by hand. They can all be easily sourced
from Ebay.

## Software

This is not written yet. I plan on doing it with ChibiOS, just for kicks. It is
well supported on the STM32 platform, easy to use (once you accepted the fact
that documentation is almost nonexistent).

# Licence

```
THE BEER-WARE LICENSE (Revision 42):
tuetuopay at me dot com wrote this file. As long as you retain this notice you
can do whatever you want with this stuff. If we meet some day, and you think
this stuff is worth it, you can buy me a beer in return. Tuetuopay.
```
