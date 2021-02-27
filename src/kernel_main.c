
#include "rprintf.h"
#include "serial.h"


void kernel_main() {

esp_printf((void*)putc, "Hello World!");


/*
    while (1) {
	led_on();
	delay();
	led_off();
	delay();
    }
*/
}


