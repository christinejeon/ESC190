#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printll(struct node *head){
	struct node *cur = head;
	printf("Printing list:\n");
	while (cur != NULL){
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void printllr(struct node *head){
	struct node *cur = head;
	if ((cur->next) != NULL){
		printf("%d ", cur->data);
		cur = cur->next;
		printllr(cur);
	}
	else{
		printf("%d ", cur->data);
	}
}

int main(void)
{
	struct node *node0 = (struct node *)malloc(sizeof(struct node));
	node0 -> data = 3;
	printf("%ld\n", &node0);

	struct node *node1 = (struct node *)malloc(sizeof(struct node));
	node0 -> next = node1;
	node1 -> data = 5;
	printf("%ld\n", &node1);

	struct node *node2 = (struct node *)malloc(sizeof(struct node));
	node1 -> next = node2;
	node2 -> data = 7;
	printf("%ld\n", &node2);

	struct node *node3 = (struct node *)malloc(sizeof(struct node));
	node2 -> next = node3;
	node3 -> data = 9;
	printf("%ld\n", &node3);

	struct node *node4 = (struct node *)malloc(sizeof(struct node));
	node3 -> next = node4;
	node4 -> data = 11;
	node4 -> next = NULL;
	printf("%ld\n", &node4);

	printll(node0);
	printf("\nprintllr:\n");
	printllr(node0);

	return 0;
}
