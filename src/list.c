
#include <stdio.h>
#include <stdlib.h>
#include <list.h>


int main()
{
	
}


list_add(struct list_element *list_head, struct list_element *new_element)
{
	struct list_element new_node = *new_element;
	struct list_element *last = *head_ref;
	
	new_node->next = NULL;
	
	if (*list_head == NULL)
	{
		*list_head = new_node;
		return;
	}
	
	while (last->next != NULL)
	{
		last = last->next;
	}	
	
	last->next = new_node;
	return;
}

list_remove(struct list_element *element, struct list_element *head_ref)
{
	struct list_element *temp = *head_ref, *prev;
	
	if (temp != NULL && temp == element)
	{
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	while (temp != NULL && temp != element)
	{
		prev = temp;
		temp = temp->next;
	}
	
	if (temp == NULL)
		return;
		
	prev->next = temp->next;
	
	free(temp);
	 
}
	
