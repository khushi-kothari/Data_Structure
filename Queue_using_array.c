//Array implementation of queue

#include <stdio.h>
#include <stdlib.h>
#define max 5

int Arr[max];
int front = -1;
int rear = -1;

void Enqueue(int a);
void Dequeue();
int isEmpty();
void Display();

int main()
{
    int x, num;
    while(x!=4) {
    printf("Enter an option\n");
    printf("1 : Insert an element\n2 : Delete an element\n3 : Display queue elements\n4 : Exit\n");
    scanf("%d", &x);
    
    switch(x) {
        case 1: 
        printf("Enter number you want to insert\n");
        scanf("%d", &num);
        Enqueue(num);
        break;
        
        case 2: 
        Dequeue();
        break;
        
        case 3: 
        Display();
        break;
        
        case 4: 
        return 0;
        break;
    }
    }
    return 0;
}

int isEmpty() {
    if((rear == -1 && front == -1) || (front>rear)) {
        return 0; //true
    }
    else
    return 1; //false
}

void Enqueue(int a) {
    if(rear>=max) {
        printf("Overflow Error\n");
        return;
    }
    else if(isEmpty()==0) {
        front =0;
        rear=0;
    }
    else {
        rear++;
    }
    Arr[rear] = a;
    
}

void Dequeue() {
    if(front>rear) {
    printf("Underflow error\n");
    return;
    }
    
    else if(isEmpty()==0) {
        printf("Queue is empty\n");
        return;
    }
    
    else {
        front++;
    }
}

void Display() {
    if(isEmpty()==0)
        printf("Queue is empty\n");

    else {
        printf("Queue is : \n");
        if(rear<=max) {
        for (int i = front; i <= rear; i++)
            printf("%d ", Arr[i]);
        }
        else  {
            for (int i = front; i <= max; i++)
            printf("%d ", Arr[i]);
        }
        printf("\n");
    }
}
