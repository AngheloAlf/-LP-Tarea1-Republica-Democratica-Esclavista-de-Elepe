#include "list.h"

void list_append(struct list_node **node, int data)
{
	struct list_node *new_node, *aux;

	new_node = malloc(sizeof(struct list_node));
	new_node->data = data;
	new_node->next = NULL;
	aux = *node;

	if (aux == NULL) {
		*node = new_node;

	} else {
		for (; aux->next != NULL; aux = aux->next);
		aux->next = new_node;
	}
}

size_t list_size(struct list_node *node)
{
	size_t i;
	for (i = 0; node != NULL; node = node->next, i++);
	return i;
}

struct list_node *list_at(struct list_node *node, size_t i)
{
	for (; node != NULL; node = node->next, i--)
		if (!i) return node;

	return NULL;
}

int list_remove(struct list_node **node, size_t i)
{
	struct list_node *prev, *aux;

	prev = NULL;

	for (aux = *node; aux != NULL; aux = aux->next, i--) {
		if (!i) {
			if (prev == NULL)
				*node = (*node)->next;
			else
				prev->next = aux->next;

			free(aux);
			return 1;
		}

		prev = aux;
	}

	return 0;
}


void list_clean(struct list_node *node)
{
	if (node == NULL)
		return;

	list_clean(node->next);
	free(node);
}
