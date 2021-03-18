#include "page.h"
#include "list.h"
extern int __end;
#define NULL (void*)0

struct ppage physical_page_array[128];
struct ppage* free_pages_list = NULL;

void init_pfa_list(void){
	void* address_p = 0x200000;
	int x;
	for (x=0; x<128; x++){
		listAdd((struct listElement**) &free_pages_list, (struct listElement*) &physical_page_array[x]);
		physical_page_array[x].physical_addr = address_p;
		address_p += 0x200000;
	}
}

//create the following functions to allocate and free physical pages
struct ppage *allocate_physical_page(unsigned int npages){
	struct ppage* new_var = free_pages_list;
	struct ppage* new_list = NULL;
	int x;
	for (x=0; x<npages; x++){
		listRemove((struct listElement*)new_var);
		listAdd((struct listElement**)&new_list,(struct listElement*) new_var);
	}
	return new_list;
}

void free_physical_pages(struct ppage *ppage_list){
	struct ppage* new_var = ppage_list;
	while (ppage_list !=NULL){
		listRemove((struct listElement*) new_var);
		listAdd((struct listElement**) &free_pages_list,(struct listElement*) new_var);

	}
}
