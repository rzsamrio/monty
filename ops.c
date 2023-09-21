#include "monty.h"

head = NULL;

void push (stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = x;
	node->next = head;
	node->prev = NULL;
	if (head != NULL)
		head->prev = node
	else
		head = node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *curr;
	curr = head;

	while(curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
