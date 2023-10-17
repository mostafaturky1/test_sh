#include "shell.h"

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
 * free_Arguments - frees the array of pointers arguments
 *@arv: array of pointers
 */
void free_Arguments(char **arguments)
{
	int i;

	for (i = 0; arguments[i]; i++)
		free(arguments[i]);
	free(arguments);
}
