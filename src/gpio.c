
#include <stdio.h>
#include "gpio.h"

unsigned int *gpset1 = 0xFE200020;
unsigned int *gpsel4 = 0xFE200010;
unsigned int *gpclr1 = 0xFE20002C;

void led_init(){
	unsigned int mask = 0xFFFFFEE3F;
	*gpsel4 = *gpsel4 & mask;
	*gpsel4 = *gpsel4 | (1 << 6);
	return;
}

void led_on(){
	*gpset1 = (1 << 10);
}

void led_off(){
	*gpclr1 = (1 << 10);
}
 void delay(){
	int c, d;
	for (c = 1; c <= 32767; c++)
		for (d = 1; d <= 32767; d++)
		{}
 }
