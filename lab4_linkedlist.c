#include <stdio.h>
#include <stdlib.h>
#include "lab4_linkedlist.h"

void append(struct node *head, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;
    cur->next = node;
}

void ins_ll(struct node *head, int ind, int value)
{
    struct node *cur = head;
    int saved_val = 0;

    for (int i = 1; i < ind; i++)
    {
        cur = cur->next;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;

    new_node->next = cur->next;
    cur->next = new_node;
}

void free_list_rec(struct node *head){
    if(head == NULL){
        return;
    }
    else{
        free_list_rec(head->next);
        free(head);
    }
}

void del_node(struct node *head, int value){
    struct node *cur = head;
    struct node *prev = head;

    while (cur->data != value && cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }

    if (cur->data == value){
        prev->next = cur->next;
        free(cur);
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
