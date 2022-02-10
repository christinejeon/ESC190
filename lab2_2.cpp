#include <stdio.h>
#include <stdlib.h>

struct node{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

void append_int(struct node *head, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    int *num = (int *)malloc(sizeof(int));
    *num = value;
    node->p_data = num;
    node->type = 0;
    node->next = NULL;
    cur->next = node;
}

void append_float(struct node *head, float value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    float *num = (float *)malloc(sizeof(float));
    *num = value;
    node->p_data = num;
    node->type = 1;
    node->next = NULL;
    cur->next = node;
}

void append_dbl(struct node *head, double value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    long *num = (long *)malloc(sizeof(long));
    *num = value;
    node->p_data = num;
    node->type = 2;
    node->next = NULL;
    cur->next = node;
}


void printllr(struct node *head){
	struct node *cur = head;
	if ((cur->next) != NULL){
		if (cur->type == 0){
			printf("%d ", *(int *)cur->p_data);
			printf("type: %d \n", cur->type);
		}
		else if (cur->type == 1){
			printf("%f ", *(float *)cur->p_data);
			printf("type: %d \n", cur->type);
		}
		else{
			printf("%ld ", *(long *)cur->p_data);
			printf("type: %d \n", cur->type);
		}
		cur = cur->next;
		printllr(cur);
	}
	else{
		if (cur->type == 0){
			printf("%d ", *(int *)cur->p_data);
		printf("type: %d \n", cur->type);
		}
		else if (cur->type == 1){
			printf("%f ", *(float *)cur->p_data);
			printf("type: %d \n", cur->type);
		}
		else{
			printf("%ld ", *(long *)cur->p_data);
			printf("type: %d \n", cur->type);
		}
	}
}

void free_list_rec(struct node *head){
    if(head == NULL){
        return;
    }else{
        free_list_rec(head->next);
        free(head);
    }
}

int main (void)
{
	int num0 = 3;
	struct node *node0 = (struct node *)malloc(sizeof(struct node));
	node0->p_data = &num0;
	node0->type = 0;
	
	float num1 = 7.86;
	struct node *node1 = (struct node *)malloc(sizeof(struct node));
	node0->next = node1;
	node1->p_data = &num1;
	node1->type = 1;
	node1->next = NULL;
	printllr(node0);
	
	append_int(node0, 9);
	append_float(node0, 4.61);
	append_dbl(node0, 189895901);
	
	printllr(node0);
	free_list_rec(node0)
	return 0;
}
