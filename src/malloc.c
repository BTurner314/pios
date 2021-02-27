
#include <stdio.h>

struct s {
	struct s *next;
	
	int k;
	
};

int main (){
struct s var;
struct s *s_ptr;
struct s *s_ptr2;

s_ptr = malloc(sizeof(var));

printf("Address of malloc region %d/n", s_ptr);


s_ptr->k = 0;
s_ptr2 = (int *) malloc(sizeof(var);
s_ptr2->next = s_ptr;
printf("address of second malloc region %d/n", s_ptr2);
printf("address of second malloc region next %d/n", s_ptr2->next);

}

