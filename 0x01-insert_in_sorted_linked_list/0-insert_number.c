#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - check the code for Holberton School students.
 * @head: head
 * @number: number
 *
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *first = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;

	if (!first)
	{
		new->next = NULL;
		first = new;
		return (new);
	}

	if (number < first->n)
	{
		new->next = first;
		first = new;
		return (new);
	}

	while (first->next->n < number)
	{
		first = first->next;
	}
	new->next = first->next;
	first->next = new;
	return (new);
}
