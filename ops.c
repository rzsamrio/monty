#include "monty.h"

void push (stack_t **stack, unsigned int line_number)
{
	int x;
	stack_t *node;
	char *tmp;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tmp = strtok(NULL, " "); /* First called in get_op */
	x = checknum(tmp);
	if (x == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(tmp);
	node->next = (*stack);
	node->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = node;
	(*stack) = node;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;
	curr = (*stack);

	while(curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
