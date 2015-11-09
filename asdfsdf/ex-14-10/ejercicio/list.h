#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct list_node
{
	int data;
	struct list_node *next;
};

void list_append(struct list_node **node, int data);
size_t list_size(struct list_node *node);
struct list_node *list_at(struct list_node *node, size_t i);
int list_remove(struct list_node **node, size_t i);
void list_clean(struct list_node *node);

#endif