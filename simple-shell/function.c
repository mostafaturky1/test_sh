#include "shell.h"

/**
 * any_Path - Search 'filename' in 'head' dirs.
 * @filename: The file to search.
 * @head: List of directories.
 * Return: Path if found, else NULL.
 */


char *any_Path(char *filename, list_path *head)
{
	struct stat st;
	char *string = NULL;

	list_path *tmp = head;

	while (tmp)
	{

		string = search_Path(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * search_Path - Combine 'name', 'sep', and 'value' into a single string.
 * @name: The first part of the resulting string.
 * @sep: The separator to insert between parts.
 * @value: The last part of the resulting string.
 *
 * This function creates a string by concatenating 'name', 'sep', and 'value'.
 * Return: A new string or NULL on allocation failure.
 */

char *search_Path(char *name, char *sep, char *value)
{
	char *result = NULL;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * end_node_ - adds a new node at the end of a linked list
 * @head: double pointer to the list_path list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
*/
list_path *end_node(list_path **head, char *str)
{

	list_path *tmp;
	list_path *new;

	new = malloc(sizeof(list_path));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}

/**
 * free_linked - frees a list_t
 *@head: pointer to our linked list
 */
void free_linked(list_path *head)
{
	list_path *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}

}
/**
 * free_Arguments - Free memory allocated for an array of strings.
 * @arguments: The array of strings to be freed.
 *
 * This function to releasing memory allocated for an array of strings.
 */

void free_Arguments(char **arguments)
{
	int i;

	if (arguments == NULL) return;

	for (i = 0; arguments[i]; i++)
    {	
		if (arguments[i] == NULL) continue;
		
		free(arguments[i]);
    }
	
	free(arguments);
}
