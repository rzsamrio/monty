#include "monty.h"

/**
 * read_file - reads input from a file
 * @filename: name of file to read
 * Return: returns an array of byte commands
 */

char **read_file(char *filename)
{
	int i, fd, len, line_c;
	char *tmp, buffer[ULIMIT], **arr = NULL;

	/* Section reads the file into a buffer */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	len = read(fd, buffer, ULIMIT - 1);
	buffer[len] = '\0';

	/* Splits buffer into seperate arr */
	for (i = 0, line_c = 0; buffer[i] != '\0'; i++) /* lc = 1, the def \0*/
	{
		if (buffer[i] == '\n')
			line_c++;
	}
	arr = malloc(sizeof(char *) * (line_c + 1)); /* should be freed */
	if (arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp = strtok(buffer, "\n");
	for (i = 0; tmp != NULL; i++)
	{
		trim(&tmp);
		arr[i] = strdup(tmp);
		tmp = strtok(NULL, "\n");
	}
	arr[line_c] = NULL;
	close(fd);
	return (arr);
}

/**
 * trim- trims white spaces
 * @s: string to trim
 */

void trim(char **s) /* working here */
{
	int i, next;

	for (i = 0, next = i + 1; (*s)[i] == ' '; i++, next++)
	{
		if ((*s)[next] != ' ')
		{
			(*s) = &(*s)[next];
			return;
		}
		else
			continue;
	}
}
