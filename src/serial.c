#include "serial.h"

unsigned int *serial_port = 0x3F215040;

void putc(int data){
serial_port = data;

}
