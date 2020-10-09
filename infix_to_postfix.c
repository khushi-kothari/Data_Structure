//Infix to postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[60];
int top = -1;

void push(char x) {
    stack[++top] = x; //increment top and putting the value
}

char pop() {
    if(top == -1)
    return -1;
    else
    return stack[top--];
}

int priority(char x) {
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;
}

int main() {
    char exp[60];
    char x;
    printf("(No Spaces)\n");
    printf("Enter the infix expression : ");
    scanf("%s",exp);
    
    printf("Postfix expression : ");
    
    for(int i=0; i<strlen(exp); i++) {
    if(isalnum(exp[i])){
        printf("%c", exp[i]);
    }
    else if(exp[i] == '(')
        push(exp[i]);
    else if(exp[i] == ')') {
        while((x = pop()) != '(') {
        printf("%c", x);
        }
    }
    else {
        while(priority(stack[top]) >= priority(exp[i])) {
            x = pop();
            printf("%c", x);
        }
        push(exp[i]);
    }
    } 
    
    while(top != -1) {
        x = pop();
        printf("%c", x);
    }
    
    return 0;
}
