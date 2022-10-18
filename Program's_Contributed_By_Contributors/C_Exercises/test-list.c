#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next; /* pointer to the same structure */
} node;

typedef node *list;

/*
 * Assume that the list is in increasing order and insert the element
 * preserving the increasing order
 */
list list_insert_ordered(list p, int val);

/*
 * Concatenate two lists
 */
list list_cat(list before, list after);
/*
 * Insert elements at the head of the list
 */
list list_insert_head(list p, int val);

/*
 * Insert elements at the tail of the list
 */
list list_insert_tail(list p, int val);

/*
 * Print the list content
 */
void list_print(list p);

/*
 * Free the list
 */
void list_free(list p);

/*
 * Delete and deallocate the first node of the list equal to the value
 */
list list_delete_if(list head, int to_delete);

/*
 * Remove every element at an odd index
 */
list list_delete_odd(list head);

/*
 * Remove every element with value less than cut_value
 */
list list_cut_below(list head, int cut_value);

/*
 * Return a copy of the list (copy every element)
 */
list list_dup(list head);

int main()
{
	list head = NULL;
	list head2 = NULL;

	head = list_insert_ordered(head, 4);
	head = list_insert_ordered(head, 2);
	head = list_insert_ordered(head, 3);

	head2 = list_insert_ordered(head2, 6);
	head2 = list_insert_ordered(head2, 12);
	head2 = list_insert_ordered(head2, 1);
	list_print(head);
	list_cat(head, head2);
	list_print(head);

	head = list_insert_head(head, -2);
	head = list_insert_tail(head, 100);
	head = list_insert_tail(head, 1003);
	head = list_insert_tail(head, 32);
	list_print(head);

	head = list_cut_below(head, 1);
	list_print(head);
	list head3 = list_dup(head);
	head3 = list_cut_below(head3, 20);
	list_print(head3);

	list_print(head);

	head = list_delete_odd(head);

	list_print(head);

	return 0;
}

list list_insert_tail(list p, int val)
{
	list new_node = malloc(sizeof(node));
	new_node->value = val;
	new_node->next = NULL;

	// Scroll to the end of the list and append the last element
	list curr = p;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;

	return p;
}

list list_cat(list before, list after)
{
	// Porbably implicit but if there is nothing to concatenate to, simply return the second list
	if (before == NULL)
	{
		return after;
	}

	// Scroll to the end and append the second list
	// this is done by changing the pointer of the last element
	// to point to the first element of the second list
	list curr = before;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = after;
	return before;
}

list list_insert_head(list p, int val)
{
	list new_el;

	/* Allocate the new list */
	new_el = malloc(sizeof(*new_el));
	/* Setting the data */
	new_el->value = val;
	/* head insertion: old head becomes .next field of new head */
	new_el->next = p;
	/* new head is the pointer to the new list */
	return new_el;
}

list list_insert_ordered(list p, int val)
{
	list new_node = malloc(sizeof(node));
	new_node->value = val;
	new_node->next = NULL;

	// Empty list
	if (p == NULL)
	{
		return new_node;
	}

	// Insert at the beginning
	if (val < p->value)
	{
		new_node->next = p;
		return new_node;
	}

	// Scroll through the list and insert the element at its correct position
	list prev = p;
	list curr = p->next;
	while (curr != NULL)
	{
		if (val < curr->value)
		{
			prev->next = new_node;
			new_node->next = curr;
			return p;
		}
		prev = curr;
		curr = curr->next;
	}

	prev->next = new_node;
	return p;
}

void list_print(list p)
{
	/* Looping all nodes until p == NULL */
	if (p == NULL)
	{
		printf("Empty list\n");
		return;
	}
	printf("[%i]", p->value);
	for (; p->next != NULL; p = p->next)
	{
		printf(" -> [%i]", p->next->value);
	}
	printf("\n");
}

void list_free(list p)
{
	/* If p ==  NULL, nothing to deallocate */
	if (p == NULL)
	{
		return;
	}
	/* First deallocate (recursively) the next nodes... */
	list_free(p->next);
	/* ... then deallocate the node itself */
	free(p);
}

list list_delete_if(list head, int to_delete)
{
	// Empty list
	if (head == NULL)
	{
		return NULL;
	}

	// Delete the first element
	if (head->value == to_delete)
	{
		list tmp = head->next;
		free(head);
		return tmp;
	}

	// Scroll through the list and delete the element if found
	list prev = head;
	list curr = head->next;
	while (curr != NULL)
	{
		if (curr->value == to_delete)
		{
			prev->next = curr->next;
			free(curr);
			return head;
		}
		prev = curr;
		curr = curr->next;
	}

	return head;
}

// Delete every element at an odd position in the list
list list_delete_odd(list head)
{
	// Empty list
	if (head == NULL)
	{
		return NULL;
	}

	list tmp = head->next;
	free(head);
	head = tmp;
	

	int pos = 1;
	list prev = head;
	list curr = head->next;
	while (curr != NULL)
	{
		if (pos % 2 == 1)
		{
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
		pos++;
	}

	return head;
}

list list_cut_below(list head, int cut_value)
{


	while(head && head-> value < cut_value)
	{
		list tmp = head->next;
		free(head);
		head = tmp;
	}

	// List might be empty now
	if (head == NULL)
	{
		return NULL;
	}

	// Iterate over the list
	list prev = head;
	list curr = head->next;
	while (curr != NULL)
	{
		if (curr->value < cut_value)
		{
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	return head;
}

list list_dup(list head)
{
	// Empty list
	if (head == NULL)
	{
		return NULL;
	}

	// Create a new list with the first element
	list new_list = malloc(sizeof(node));
	new_list->value = head->value;
	new_list->next = NULL;

	// Iterate over the list and copy every element over
	list curr = head->next;
	list new_curr = new_list;
	while (curr != NULL)
	{
		new_curr->next = malloc(sizeof(node));
		new_curr = new_curr->next;
		new_curr->value = curr->value;
		new_curr->next = NULL;
		curr = curr->next;
	}
	return new_list;
}
