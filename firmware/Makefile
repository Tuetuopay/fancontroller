# Allow local overrides
-include local.mk

# Use ChibiOS
include chibios.mk

# Starts OpenOCD
openocd:
	openocd -f interface/stlink-v2-1.cfg -f target/stm32f1x.cfg

# Lauches GDB and flashes the target
debug: $(BUILDDIR)/$(PROJECT).elf
	$(TRGT)gdb $(BUILDDIR)/$(PROJECT).elf

.PHONY: openocd debug
