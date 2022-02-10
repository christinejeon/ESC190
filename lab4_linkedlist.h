#if !defined(LAB4_LINKEDLIST_H)
#define LAB4_LINKEDLIST_H

struct node{
    int data;
    struct node *next;
};

void append(struct node *head, int value);
void ins_ll(struct node *head, int ind, int value);
void free_list_rec(struct node *head);
void del_node(struct node *head, int value);
void printllr(struct node *head);

#endif // LAB4_LINKEDLIST_H_INCLUDED
