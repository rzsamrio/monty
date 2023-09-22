#include "monty.h"

/**
 * add - prints the elements of a stack
 * @stack: top stack address
 * @line_number: byte command line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int i, sum;
	stack_t *curr, *first;

	i = 1;
	sum = 0;
	curr = *stack;
	first = curr;
	while (i > 0)
	{
		if (curr == NULL)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		curr = curr->next;
		i--;
	}
	sum = curr->n + first->n;
	curr->n = sum;
	*stack = curr;
	free(first);
}

/**
 * nop - does nothing
 * @stack: top stack address
 * @line_number: byte command line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
