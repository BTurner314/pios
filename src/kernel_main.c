
#include <stdio.h>

void kernel_main() {

    char *begin_bss = &__bss_start;
    char *end_bss = &__bss_end;

    size_t i;
    for (i = 0; i < begin_bss; ++i){
	begin_bss[i] = 0;
	}
return 0;

}


