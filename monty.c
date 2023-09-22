#include "monty.h"



/**
 * main - run the monty program
 * @argc: number of arguments
 * @argv: string array of arguments
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	int i;
	stack_t *head;
	void (*operation)(stack_t **, unsigned int);
	char **lines = NULL;

	if (argc != 2) /* monty file */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	head = NULL;
	i = 0;
	lines = read_file(argv[1]);

	while (lines[i] != NULL)
	{
		operation = get_op(lines[i], i + 1);
		operation(&head, i + 1);
		free(lines[i]);
		i++;
	}
	free_stack(&head);
	free(lines);
	return (0);
}
