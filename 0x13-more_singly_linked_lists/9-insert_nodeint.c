#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a list.
 * @head: Double pointer to the head of the list.
 * @idx: Index of the list where the new node should be added (starting at 0).
 * @n: Value to be assigned to the new node's data.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *current = *head;
    unsigned int count = 0;

    if (head == NULL || idx == 0)
    {
        new_node = malloc(sizeof(listint_t));
        if (new_node == NULL)
            return (NULL);
        new_node->n = n;
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    while (current != NULL && count < idx - 1)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}}
