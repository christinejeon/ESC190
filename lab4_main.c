#include <stdio.h>
#include <stdlib.h>
#include "lab4_linkedlist.h"

int main(void)
{
	struct node *node0 = (struct node *)malloc(sizeof(struct node));
	node0 -> data = 3;

	struct node *node1 = (struct node *)malloc(sizeof(struct node));
	node0 -> next = node1;
	node1 -> data = 5;

	struct node *node2 = (struct node *)malloc(sizeof(struct node));
	node1 -> next = node2;
	node2 -> data = 7;

	struct node *node3 = (struct node *)malloc(sizeof(struct node));
	node2 -> next = node3;
	node3 -> data = 9;

	struct node *node4 = (struct node *)malloc(sizeof(struct node));
	node3 -> next = node4;
	node4 -> data = 11;
	node4 -> next = NULL;

	printf("\nprintllr:\n");
	printllr(node0);

	append(node0, 13);
	printf("\nprintllr after append:\n");
	printllr(node0);

	del_node(node0, 9);
	printf("\nprintllr after del:\n");
	printllr(node0);

	ins_ll(node0, 2, 0);
	printf("\nprintllr after ins_ll:\n");
	printllr(node0);

	free_list_rec(node0);

    return 0;
}
