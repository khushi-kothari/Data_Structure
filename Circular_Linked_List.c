#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traverse (struct node *head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr->next != head);
    printf("%d ", ptr->data);
}

struct node * insertfirst(int data, struct node *head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p = head;
    ptr->data = data;
    
    do {
        p = p->next;
    } while(p->next != head);
    
    //juz now p is pointinf to the last node of the circlar linked list(b4 head)
    
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    
    return head;
}

struct node * insertend(int data, struct node *head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p = head;
    ptr->data = data;
    
    do {
        p = p->next;
    } while(p->next != head);
    
    //juz now p is pointinf to the last node of the circlar linked list(b4 head)
    
    p->next = ptr;
    ptr->next = head;
    
    return head;
}

struct node * delfirst(struct node *head) {
    struct node *p;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    p = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    p = head;
    
    do {
        p = p->next;
    } while(p->next != head);
    
    //juz now p is pointinf to the last node of the circlar linked list(b4 head)
    
    p->next = head->next;
    head = head->next;
    free(ptr);
    
    return head;
}

struct node * delend(struct node *head) {
    struct node *p;
    struct node *prev;
    prev = (struct node *)malloc(sizeof(struct node));
    p = (struct node *)malloc(sizeof(struct node));
    prev = head;
    p = head;
    
    do {
        prev = p;
        p = p->next;
    } while(p->next != head);
    
    //juz now p is pointinf to the last node of the circlar linked list(b4 head)
    
    prev->next = head;
    free(p);
    
    return head;
}

int main() {
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    
    //Allocate memory to the above nodes created
    
    head = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    
    head -> data = 10;
    head -> next = second;
    
    second -> data = 20;
    second -> next = third;
    
    third -> data = 30;
    third -> next = fourth;
    
    fourth -> data = 40;
    fourth -> next = head;
    
    printf("Orignial Circular Linked List\n");
    traverse(head);
    
    head = insertfirst(80, head);
    printf("\n\nAfter inserting 80 in the beginning\n");
    traverse(head);
    
    head = insertend(22, head);
    printf("\n\nAfter inserting 22 at the end\n");
    traverse(head);
    
    head = delfirst(head);
    printf("\n\nAfter deleting the first element\n");
    traverse(head);
    
    head = delend(head);
    printf("\n\nAfter deleting the last element\n");
    traverse(head);
}
