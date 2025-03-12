# pi-i2c

pi-i2c is an I²C C library for Raspberry Pi using the I²C kernel driver.

It includes GPIO access routines for MCP23017 16-Bit I/O Expander.  
Allows access by individual *pin*, *port* (8 bit) or *device* (16 bit)

Overlays
========
Includes python overlay.
This is available with `include pi_i2c`.

Documentation
=============
To read documentation:-  
	C:	`man pi-i2c` & `man MCP23017`  
	Python:	`python3 -m pydoc pi_i2c`  

Extensions
==========
GPIO access routines for MCP23017 16-Bit I/O Expander (requires MCP23017.h)

*I initially developed this as part of a larger project, but realised it could form a stand alone library.  
This should work on any Linux system which includes the I²C kernel driver.*
