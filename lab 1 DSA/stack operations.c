#include <stdio.h>

# define N 5
int stack[N];
int top = -1;
void push(){
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    if (top == N-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top] = a;
        printf("The top element:",stack[top]);
    }
}

void pop(){
    int item;
    if (top == -1){
        printf("Underflow");
    }
    else{
        item = stack[top];
        top--;
        printf("%d",item);
    }
}

void peek(){
    int item;
    if (top == -1){
        printf("Underflow");
    }
    else{
        printf("%d",stack[top]);
    }
}

void main(){
    int stack[5];
    int top = -1;
    int ch;
    printf("Enter 1,2,3 for insertion, deletion and peek:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        default:
        printf("Enter the valid input");
    }
}
