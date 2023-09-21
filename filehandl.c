#include "monty.h"

/**
 *
 */

char **read_file(char *filename)
{
	int i, fd, len, line_c;
	char *tmp, buffer[ULIMIT], **lines;

	/* Section reads the file into a buffer */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}
	len = read(fd, buffer, ULIMIT - 1);
	buffer[len] = '\0';

	/* Splits buffer into seperate lines */
	for (i = 0, line_c = 1; buffer[i] != '\0'; i++) /* lc = 1, the def \0*/
	{
		if (buffer[i] == '\n')
			line_c++;
	}
	lines = malloc(sizeof(char *) * (line_c + 1)); /* should be freed */
	if (lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp = strtok(buffer, "\n");
	for (i = 0; tmp != NULL; i++)
	{
		trim(&tmp);
		lines[i] = tmp;
		tmp = strtok(NULL, "\n");
	}
	lines[line_c] = NULL;
	close(fd);
	return(lines);
}

/**
 *
 */

void validate(char **lines)
{
	int i, j, count;

	char buf[120], *cmds[] = {"push", "pop", NULL};

	for (i = 0; lines[i] != NULL; i++)
	{
		printf("%s\n", lines[i]);
		for (j = 0; cmds[j] != NULL; j++)
		{
			if (strncmp(lines[i], cmds[j], strlen(cmds[j])) == 0)
				break;
			else
			{
				for (j = 0, count = 0; lines[i][j] != '\0' && lines[i][j] != ' '; j++)
					count++;
				sprintf(buf, "L%d: unknown instruction %s", i + 1, strndup(lines[i], count));
				fprintf(stderr, "%s\n", buf);
				exit(EXIT_FAILURE);
			}
		}
	}
}


/**
 *
 */

void trim(char **s) /* working here */
{
	int i, next;

	for (i = 0, next = i + 1; (*s)[i] == ' '; i++, next++)
	{
		if ((*s)[next] != ' ')
		{
			(*s) = &(*s)[next];
		}
		else
			continue;
	}
}
