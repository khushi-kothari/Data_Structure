//Infix to prefix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[60];
int top = -1;

void push(char x) {
    stack[++top] = x; //increment top and putting the value
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
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
    char pre[60];
    char x;
    printf("(No Spaces)");
    printf("Enter the infix expression : ");
    scanf("%s",exp);
    
    for(int i=0; i<strlen(exp); i++) {
        if(exp[i] == '(') 
        exp[i] = ')';
        
        else if(exp[i] == ')')
        exp[i] = '(';
    }
    
    strrev(exp);
    
    printf("Prefix expression : ");
    int j=0;
    
    for(int i=0; i<strlen(exp); i++) {
    if(isalnum(exp[i])){
        pre[j] = exp[i];
        j++;
    }
    else if(exp[i] == '(')
        push(exp[i]);
    else if(exp[i] == ')')
    {
        while((x = pop()) != '(') {
        pre[j] = x;
        j++;
        }
    }
    else
    {
        while(priority(stack[top]) >= priority(exp[i])) {
            pre[j] = pop();
            j++;
        }
        push(exp[i]);
    }
    } 
    
    while(top != -1)
    {
        pre[j] = pop();
        j++;
        
    }
    
    strrev(pre);
    printf("%s", pre);
    return 0;
}
