#ifndef __PAGE_H__
#define _PAGE_H__

struct ppage {
	struct ppage *next;
	struct ppage *prev;
	void *physical_addr;
};

void init_pfa_list(void);

struct ppage *allocate_physical_page(unsigned int npages);

void free_physical_pages(struct ppage *ppage_list);

#endif
