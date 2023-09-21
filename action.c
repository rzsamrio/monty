#include "monty.h"

/**
 *
 */

void (*get_op(char *s, unsigned int n))(stack_t **, unsigned int )
{
	int i;
	char *tmp,	buf[120];

	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	tmp = strtok(s, " ");
	
	for(i = 0; cmd[i].opcode != NULL && tmp != NULL; i++)
	{
		if (strcmp(tmp, cmd[i].opcode) == 0)
			return (cmd[i].f);
	}
	sprintf(buf, "L%d: unknown instruction %s", n, tmp);
	fprintf(stderr, "%s\n", buf);
	exit(EXIT_FAILURE);
}

int checknum(char *s)
{
	int i;

	if (s == NULL)
	{
		return (0);
	}
	for(i = 0; s[i] != 0; i++)
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	}
	return (1);
}

