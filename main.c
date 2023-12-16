#include "monty.h"
#include <stdio.h>

cmds *command_list = NULL;

/**
 * is_blank - Checks for blank spaces in a string.
 *
 * @s: Source string
 * Return: 0 if successful (no blank spaces), 1 otherwise
 */
int is_blank(char *s)
{
	size_t i = 0;

	for (; s[i] && (s[i] == ' ' || s[i] == '\t'); i++)
		;
	return (s[i] == '\0');
}

/**
 * main - Entry point, evaluates the path name.
 *
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: EXIT_SUCCESS, EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t line_length;
	int read;
	stack_t *stack = NULL;
	cmds *current_command;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (line_length = 0; (read = getline(&line, &line_length, file)) != EOF;)
	{
		line[read - 1] = '\0';

		if (is_blank(line) || handle_comments(&line) || !(*line))
			continue;

		current_command = build_command_node(&command_list, line, line_length);
		if (!current_command)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);

	while (command_list)
	{
		execute_ops(&stack);
		free_command_node(&command_list);
	}

	free_stack(&stack);
	return EXIT_SUCCESS;
}
