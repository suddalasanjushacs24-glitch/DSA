#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enque(){
    int x;
    printf("Enter a number:");
    scanf("%d",&x);
    if (rear == N){
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

int deque(){
    if (front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if (front == rear){
        front = rear = -1;
    }
    else{
        printf("Deleted element = %d\n", queue[front]);
        front++;
    }
}

int display(){
    int i;
    if (front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue:\n");
        for (i=front; i<=rear; i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int ch;
    do{
        printf("Enter your choice '1' for Insertion, '2' for Deletion and '3' for Display:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid Input");
        }
    }
    while (ch != -1);
}
