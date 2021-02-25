
#include <stdio.h>
#include <gpio.h>

void kernel_main() {

    while (1) {
	led_on();
	delay();
	led_off();
	delay();
    }

}


