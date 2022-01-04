// #define EXTMEM2 __attribute__((section(".externalram2")))

#include <Arduino.h>

EXTMEM2 unsigned int Counter1;

#include "imxrt.h"

void setup() {
	delay(1000); // Start delay

	Serial.begin(115200);
	Serial.println("SERIAL STARTED");

	Serial.print("Previously the counter got to: "); Serial.println(Counter1);

	Serial.println("Resetting Counter...");
	Counter1 = 1;

	// Flush & Delete to ensure that the ram is working and the values we see are not just in the cache
	arm_dcache_flush_delete((void *)0x70800000, (uint32_t)0x80000);
	Serial.print("Starting Value: "); Serial.println(Counter1);
	Serial.println(); // Spacing

	Serial.println("Start: ");
	Serial.println(Counter1);
	delay(1000); // Delay for 1 second

	while (1) { // loop
		Counter1++; // Increment value
		arm_dcache_flush_delete((void *)0x70800000, (uint32_t)0x80000); // Flush & Delete 
		Serial.println(Counter1); // Print
		delay(1000); // Delay for 1 second
	}

	Serial.println("Counter1 Reached 10!!!");

}

void loop() {


}	// End loop
