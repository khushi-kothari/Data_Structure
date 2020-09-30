#include <stdio.h>
#define max 20
#include<stdio.h>

int arr[max];
int top=-1;

int isEmpty();
int isFull();
void push(char x);
void pop();
void print();
void reverse(int s, char *c);

int main()
{
    char c[40];
    printf("Enter a string: ");
    gets(c);
    reverse(strlen(c), c);
    printf("%s", c);
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

void push(char x) {
    if(isEmpty()==0) 
        arr[++top] = x;

    else if(isFull()==0)
        printf ("Overflow Error\n");

    else
    arr[++top] = x;
}

void pop() {
    if(isFull()==0){
        printf("%c", arr[top]);
        top--;
}

    else if(isEmpty()==0)
        printf("Underflow Error\n");

    else{
        printf("%c", arr[top]);
        top--;
    }
}

void reverse(int s, char *c) {
    for(int i=0; i<s; i++) {
        push(c[i]);
    }
    
    for(int i=0; i<s; i++) {
        c[i] = top;
        pop();
    }
}

void print() {
    if(isEmpty()==0)
    printf("Stack is empty\n");

    else {
    for(int i=0; i<=top; i++)
        printf("%d ", arr[i]);
    }
}
