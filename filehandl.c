#include "monty.h"

/**
 *
 */

char **read_file(char *filename)
{
	int i, fd, len, line_c;
	char *tmp, buffer[ULIMIT], **arr;

	/* Section reads the file into a buffer */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}
	len = read(fd, buffer, ULIMIT - 1);
	buffer[len] = '\0';

	/* Splits buffer into seperate arr */
	for (i = 0, line_c = 1; buffer[i] != '\0'; i++) /* lc = 1, the def \0*/
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
		arr[i] = tmp;
		tmp = strtok(NULL, "\n");
	}
	arr[line_c] = NULL;
	close(fd);
	return(arr);
}

/**
 *
 */

void validate(char **arr)
{
	int i, j, count;

	char buf[120], *cmds[] = {"push", "pop", NULL};

	for (i = 0; arr[i] != NULL; i++)
	{
		printf("%s\n", arr[i]);
		for (j = 0; cmds[j] != NULL; j++)
		{
			if (strncmp(arr[i], cmds[j], strlen(cmds[j])) == 0)
				break;
			else
			{
				for (j = 0, count = 0; arr[i][j] != '\0' && arr[i][j] != ' '; j++)
					count++;
				sprintf(buf, "L%d: unknown instruction %s", i + 1, strndup(arr[i], count));
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
