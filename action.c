#include "monty.h"

/**
 * get_op - gets the operation to perfrom from opcode
 * @s: opcode string
 * @n: line number
 * Return: function that returns void
 */

void (*get_op(char *s, unsigned int n))(stack_t **, unsigned int)
{
	int i;
	char *tmp,	buf[120];

	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	tmp = strtok(s, " ");

	for (i = 0; cmd[i].opcode != NULL && tmp != NULL; i++)
	{
		if (strcmp(tmp, cmd[i].opcode) == 0)
			return (cmd[i].f);
	}
	sprintf(buf, "L%d: unknown instruction %s", n, tmp);
	fprintf(stderr, "%s\n", buf);
	exit(EXIT_FAILURE);
}

/**
 * checknum - checks if a string is a number
 * @s: string
 * Return: 0 on true, 1 on false
 */
int checknum(char *s)
{
	int i;

	if (s == NULL)
	{
		return (0);
	}
	for (i = 0; s[i] != 0; i++)
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	}
	return (1);
}

/**
 * free_stack - frees the created stack
 * @head: address of the top element
 */
void free_stack(stack_t **head)
{
	stack_t *curr;

	curr = *head;
	while (*head != NULL)
	{
		curr = (*head)->next;
		free(*head);
		*head = curr;
	}
}
