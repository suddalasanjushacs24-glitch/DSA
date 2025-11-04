#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char c){
    if (top == MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop(){
    if (top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek(){
    if (top == -1){
        printf("Stack Underflow");
        return -1;
    }
    return stack[top];
}

int precedence (char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
        default:
            return -1;
    }
    return -1;
}

int associativity(char op){
    if (op == '^'){
        return 1; //R-L
    }
    else{
        return 0; //L-R
    }
}

void InfixToPostfix(char infix[], char postfix[]){
    int i, k=0;
    char c;
    for (i=0; infix[i] != '\0'; i++){
        c = infix[i];
        if (isalnum(c)){
            postfix[k++] = c;
        }
        else if (c == '('){
            push(c);
        }
        else if (c == ')'){
            while (peek() != '('){
                postfix[k++] = pop();
            }
            pop(); //discard '('
        }
        else{
            //L-R
            while (top != -1 && ((precedence(peek()) > precedence(c)) || (precedence(peek()) == precedence(c) && associativity(c) == 0))){
                postfix[k++] = pop();
            }
            //R-L
            push(c);
        }
    }
    //pop remaining operators
    while (top != -1){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter a valid paranthesis infix expression:");
    scanf("%s",infix);
    InfixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n",postfix);
    return 0;
}


