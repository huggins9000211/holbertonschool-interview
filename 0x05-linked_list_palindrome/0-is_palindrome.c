#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse - prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: number of nodes
 */
listint_t *reverse(listint_t *head)
{
    listint_t *next;


    listint_t *newHead = NULL;
    
    while (head != NULL)
    {
        next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return (newHead);
}

/**
 * is_palindrome - prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: number of nodes
 */
int is_palindrome(listint_t **head)
{
    listint_t *fast;
    listint_t *slow;

    if (*head == NULL)
    {
        return (1);
    }
    fast = *head;
    slow = *head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = slow->next;
    listint_t *shh = reverse(slow);
    listint_t *fhh = *head;

    while (shh != NULL && fhh != NULL)
    {
        if (fhh->n != shh->n)
        {
            return (0);
        }
        shh = shh->next;
        fhh = fhh->next;
    }
    return (1);
    
}