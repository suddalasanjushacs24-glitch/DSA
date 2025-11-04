#include <stdio.h>
# define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(){
    int x;
    printf("Enter a num:");
    scanf("%d",&x);
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear+1)%N == front){
        printf("Queue is full\n");
    }
    else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if (front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        printf("Deleted ele = %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Deleted ele = %d\n", queue[front]);
        front = (front+1)%N;
    }
}

void display(){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        i = front;
        printf("Queue: \n");
        while(i != rear){
            printf("%d ", queue[i]);
            i = (i+1)%N;
        }
        printf("%d", queue[rear]);
     }
}

int main(){
    int ch;
    do{
        printf("\n1)Insert 2)Delete 3)Display \n");
        printf("Enter your choice:");
        scanf("%d",&ch);
    
        switch(ch){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            default: printf("Invalid input");
        }
    } while( ch != -1);
}