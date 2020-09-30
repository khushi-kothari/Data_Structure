//stack using linked list
#include <stdio.h>
#include<stdlib.h>
 
struct node {
    int data;
    struct node *next;
};

struct node* push(int data, struct node* head);
void display(struct node* head);
struct node* pop(struct node* head);
struct node *head = NULL;


int main() {
    int val , option;
    do {
        printf("\n*****MAIN MENU*****");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your option:\n ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the number to be pushed on stack:\n ");
				scanf("%d",&val);
				head = push(val, head);
				break;
			case 2:
				head = pop(head);
				break;
			case 3:
				display(head);
				break;
		}
	}while(option != 4);
    
    return 0;
}

struct node* push(int data, struct node* head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if(head == NULL) {
        ptr->next = NULL;
        head = ptr;
    }
    else{
    ptr->next = head;
    head = ptr;
    }
    return head;
}

void display(struct node* head) {
    struct node *ptr;
    ptr=head;
    if(head == NULL) {
        printf("Stack is empty");
    }
    else {
    while(ptr->next!=NULL) {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } printf("%d", ptr->data);
    }
    //printf("%d", ptr->data);
}

struct node* pop(struct node* head) {
    struct node *ptr;
    ptr = head;
    head = head->next;
    ptr = NULL;
    return head;
}

