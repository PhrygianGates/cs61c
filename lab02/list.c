#include "list.h"

/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
void append_node (node** head_ptr, int new_data) {
	/* First lets allocate memory for the new node and initialize its attributes */
	node *nptr = malloc(sizeof(node));
	nptr->val = new_data;
	nptr->next = NULL;

	/* If the list is empty, set the new node to be the head and return */
	if (*head_ptr == NULL) {
		*head_ptr = nptr;
		return;
	}
	node* curr = *head_ptr;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	/* Insert node at the end of the list */
	curr->next = nptr;
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list (node** head_ptr) {
	if ((*head_ptr) == NULL || (*head_ptr)->next == NULL) return;
	node* end = *head_ptr;
	node* front = *head_ptr;
	node* next = end->next->next;
	while (end->next != NULL) {
		end->next->next = front;
		front = end->next;
		end->next = next;
		if (next != NULL) {
			next = next->next;
		}
	}
	/* Set the new head to be what originally was the last node in the list */
	*head_ptr = front;
}



