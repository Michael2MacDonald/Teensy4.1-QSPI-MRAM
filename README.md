# Modified Teensy 4 Core For External Memory Mapped QSPI MRAM

**Compatibility:**
This modification works with AS*xxx*204-0108X MRAM chips (AS3008204, AS3004204, AS3001204, AS3016204). The MRAM chips must be SOIC-8 to fit on the Teensy 4.1 solder pads. This modification only works with Teensy 4.1 boards.

## Usage

**Hardware:**
This code is configured for one PSRAM chip soldered to the small pads of the Teensy 4.1 and one MRAM soldered to the large pads. The PSRAM chip must be installed for the MRAM chip to be detected.

**Software:**
The MRAM works very similarly to the standard compatible external PSRAM sold by [PJRC.com](https://www.pjrc.com/store/psram.html). Use the `EXTMEM` keyword to access the PSRAM and `EXTMEM2` keyword to use the MRAM.

***NOTE:** MRAM does not support the `malloc()` or related functions!*

**Teensy Core Files That Are Modified:**
```
/cores/teensy (Removed - Unneeded)
/cores/teensy3 (Removed - Unneeded)
/cores/teensy4/avr/pgmspace.h (Added EXTMEM2 Keyword)
/cores/teensy4/startup.c
/cores/teensy4/imxrt1062_t41.ld (Decreased ERAM Section From 16MB To 8MB, Added 512K ERAM2 Section For MRAM)
```

**Sketches:**
`teensy41_mram_memtest.cpp` is the teensy memory test sketch but modified to test the MRAM.
`Counter_Test.cpp` Counts up and saves the value of the counter in MRAM. On startup it prints the counter value that is saved in MRAM and then resets it to 1 before counting again.

**Compiling And Uploading:** You can use the included makefile to build, clean, and upload this project or you can copy the modified files into your project to use your own upload/compile method (ex. Arduino IDE).