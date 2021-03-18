
#include "list.h"
#include "page.h"
#include "rprintf.h"
#include "serial.h"

extern struct ppage* free_pages_list;

void kernel_main() {
    init_pfa_list();
    struct ppage* test = free_pages_list;
    test = test->next;
    esp_printf((const func_ptr) putc, "Physical addr: %p \n", test->physical_addr);
    test = test->next;
    esp_printf((const func_ptr) putc, "Physical addr: %p \n", test->physical_addr);
    test = test->next;
    esp_printf((const func_ptr) putc, "Physical addr: %p \n", test->physical_addr);
    test = test->next;
    esp_printf((const func_ptr) putc, "Physical addr: %p \n", test->physical_addr);
    test = test->next;

}

