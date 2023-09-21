#include "monty.h"

int main(int argc, char **argv)
{
	char **lines;

	if (argc != 2) /* monty file */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	lines = read_file(argv[1]);
	validate(lines);
	return (0);
}


