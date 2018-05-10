# Connect to OpenOCD
target ext :3333
mon endian little
mon halt

define split
	lay split
	lay asm
	lay regs
	focus cmd
end
split

define rs
	mon reset
	load
end
