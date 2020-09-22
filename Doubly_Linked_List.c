#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void traverse(struct node *head);
struct node * insertfirst(int data, struct node *head);
void insertend(int data, struct node *head);
struct node * insertany(int data, int position, struct node *head);
struct node * delfirst(struct node *head);
void delend(struct node *head);
struct node * delany(int position, struct node *head);


int main() {
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    
    head->data = 10;
    head-> prev = NULL;
    head->next = second;
    
    second->data = 20;
    second->prev = head;
    second->next = third;
    
    third->data = 30;
    third->prev = second;
    third->next = fourth;
    
    fourth->data = 40;
    fourth->prev = third;
    fourth->next = NULL;
    
    int X, num, position;
    do{
    printf("Enter an option\n1 - Traverse in linked list\n2 - Insert element in beginning\n3 - Insert element in the end\n4 - Insert element at any position\n5 - Delete first element\n6 - Delete last element\n7 - Delete an element from any position\n-1 - To exit\n\n");
    scanf("%d", &X);
    
   
    switch(X) {
        
        case 1:
        traverse(head);
        break;
        
        case 2:
        printf("Enter data you want to insert\n");
        scanf("%d", &num);
        head = insertfirst(num, head);
        break;
        
        case 3:
        printf("Enter data you want to insert\n");
        scanf("%d", &num);
        insertend(num, head);
        break;
        
        case 4:
        printf("Enter data you want to insert\n");
        scanf("%d", &num);
        printf("Enter the position where you want to insert %d\n", num);
        scanf("%d", &position);
        head = insertany(num, position, head);
        break;
        
        case 5:
        head = delfirst(head);
        break;
        
        case 6:
        delend(head);
        break;
        
        case 7:
        printf("Enter the position from which the element is to be deleted\n");
        scanf("%d", &position);
        head = delany(position, head);
        break;
        
        /*case -1:
        return 0;*/
    }
    }while(X!=-1);
    
    
    return 0;
}

void traverse(struct node *head) {
    int X;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    
    printf("Doubly Linked List in normal order\n");
    while(ptr->next != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }printf("%d\n", ptr->data);
    
    printf("Doubly Linked List in reversed order\n");
    while(ptr->prev != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }printf("%d\n\n", ptr->data);
}

struct node * insertfirst(int data, struct node *head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    
    ptr->data = data;
    ptr->next = head;
    head->prev = ptr;
    head=ptr;
    
    return head;
}

void insertend(int data, struct node *head) {
    struct node *endnode;
    endnode = (struct node *)malloc(sizeof(struct node));
    endnode->data = data;
    
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    //Now ptr is pointing to the last node of the LL
    
    ptr->next=endnode;
    endnode->prev = ptr;
    endnode->next = NULL;
}

struct node * insertany(int data, int position, struct node *head) {
    struct node *ptr;
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    p->data = data;
    
     if(position == 1) {
        printf("Please choose option 2 to insert an element in the beginning\n\n");
        return head;
    }
    
    int i=1;
    while(i!=position) {
        ptr = ptr->next;
        i++;
    }//Now the ptr is pointing the position where we want our new node
    
    ptr->prev->next = p;
    p-> prev = ptr->prev;
    ptr->prev = p;
    p->next = ptr;
    
    return head;
}

struct node * delfirst(struct node *head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

void delend(struct node *head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    struct node *prev;
    prev = (struct node *)malloc(sizeof(struct node));
    prev=head;
    
    while(ptr->next !=NULL) {
        prev = ptr;
        ptr=ptr->next;
    }
    
    prev->next=NULL;
    ptr->prev = NULL;
    free(ptr);
}

struct node * delany(int position, struct node *head) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    struct node *ahead;
    ahead = (struct node *)malloc(sizeof(struct node));
    ahead=head;
    if(position ==1) {
        printf("Please select option 5 to delete the first element of the list\n\n");
        return head;
               }
    
    int i=1;
    while(i<position) {
        ahead = ptr;
        ptr = ptr-> next;
        i++;
    }
    ptr->next->prev = ahead;
    ahead->next = ptr->next;
    ptr->next = NULL;
    ptr->prev = NULL;
    free(ptr);
    return head;
}
