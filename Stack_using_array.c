#include <stdio.h>
#define max 20
int arr[max];
int top=-1;

int isEmpty();
int isFull();
void push(int x);
void pop();
void print();

int main()
{
    int x;
    while(x != -1) {
    printf("\nEnter an option\n");
    printf("1 - Push an element in stack\n");
    printf("2 - Pop an element from stack\n");
    printf("3 - Display stack\n");
    printf("4 - Check if stack is empty\n");
    printf("5 - Check if stack is full\n");
    printf("-1 - To Exit\n");

    scanf("%d", &x);
    int num;
    switch(x) {
        case 1: 
        printf("Enter element to be pushed in stack\n");
        scanf("%d", &num);
        push(num);
        break;
        
        case 2: 
        pop();
        break;
        
        case 3:
        print();
        break;
        
        case 4:
        if(isEmpty()==0)
        printf("Stack is empty\n");
        
        else
        printf("Stack is not empty\n");
        break;
        
        case 5:
        if(isFull()==0)
        printf("Stack is full\n");
        
        else
        printf("Stack is not full\n");
        break;
    }
    }
    return 0;
}

int isEmpty() {
    if(top==-1)
        return 0;
        
    else 
    return -1;
}

int isFull() {
    if(top == max-1)
        return 0;

    else
    return -1;
}

void push(int x) {
    if(isEmpty()==0) 
        arr[++top] = x;
    
    else if(isFull()==0)
        printf ("Overflow Error\n");
        
    else
    arr[++top] = x;
}

void pop() {
    if(isFull()==0)
    top--;
    
    else if(isEmpty()==0)
        printf("Underflow Error\n");
        
    else
    top--;
}

void print() {
    if(isEmpty()==0)
    printf("Stack is empty\n");
    
    else {
    for(int i=0; i<=top; i++)
        printf("%d ", arr[i]);
    }
}
