#include "monty.h"

/**
 * build_command_node - Adds a node to the end of the linked list of parsed commands.
 *
 * @head: Head of the linked list
 * @command_line: Command line to be parsed
 * @line_number: Line number of the script
 *
 * Return: New node, NULL if it fails.
 */
char *strdup(const char *s);

cmds *build_command_node(cmds **head, char *command_line, int line_number)
{
	cmds *current_node = *head, *new_node = NULL;
	char *token;

	new_node = malloc(sizeof(cmds));
	if (!new_node)
		return (NULL);

	new_node->cmd[0] = strdup(strtok(command_line, " \t"));
	if (!(new_node->cmd[0]))
	{
		free(new_node);
		return (NULL);
	}

	token = strtok(NULL, " \t");
	if (token)
	{
		new_node->cmd[1] = strdup(token);
		if (!(new_node->cmd[1]))
		{
			free(new_node->cmd[0]);
			free(new_node);
			return (NULL);
		}
	}
	else
		new_node->cmd[1] = NULL;

	new_node->line_number = line_number;
	new_node->next = NULL;
	new_node->mode = 0;

	if (!(*head))
	{
		*head = new_node;
		return (new_node);
	}

	for (; current_node->next; current_node = current_node->next)
		continue;

	current_node->next = new_node;
	return (new_node);
}

/**
 * handle_comments - Finds '#' in the line and removes it.
 *
 * @line: Line to read
 *
 * Return: 1 if '#' is found, 0 if not found.
 */
int handle_comments(char **line)
{
	int i = 0;

	for (; (*line)[i] && (((*line)[i] == ' ') || ((*line)[i] == '\t')); i++)
		;

	if ((*line)[i] == '#')
		return (1);

	for (i = 0; (*line)[i] && (*line)[i] != '#'; i++)
		;

	(*line)[i] = '\0';
	return (0);
}
