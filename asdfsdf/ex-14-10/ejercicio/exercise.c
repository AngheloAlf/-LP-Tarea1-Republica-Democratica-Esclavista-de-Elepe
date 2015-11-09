#include <stdio.h>
#include "list.h"

/* Why?! esta mal */
/* Why?! algunos reciben doble y otros single */

void show_list(struct list_node *list)
{
	int i;
	for (i = 0; i < list_size(list); i++)
		printf("list[%d] = %d\n", i, list_at(list, i)->data);
}

int main(int argc, char const *argv[])
{
	struct list_node *list = NULL;

	int i;
	for (i = 0; i < 10; i++)
		list_append(&list, i);

	printf("list size: %zu\n", list_size(list));
	show_list(list);

	printf("removing element 3...\n");
	list_remove(&list, 3);
	show_list(list);

	printf("removing element 4...\n");
	list_remove(&list, 4);
	show_list(list);

	printf("removing element 7\n");
	list_remove(&list, 7);
	show_list(list);

	printf("removing element 0\n");
	list_remove(&list, 0);
	show_list(list);

	printf("cleaning heap\n");
	list_clean(list);
	return 0;
}
