#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev, *next;
    int data;
};
struct node *head = NULL, *tail = NULL;

void createlist(int n){
    struct node * newnode;
    int i, data;
    for (i=1; i<=n; i++){
        printf("Enter data:");
        scanf("%d",&data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = data;
        newnode -> prev = newnode -> next = NULL;
        if (head == NULL){
            head = tail = newnode;
        }
        else{
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
        }
    }
    printf("Doubly linked list is created.");
}

void insertAtFront(int data){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> prev = NULL;
    newnode -> next = head;
    if (head == NULL){
        head = tail =newnode;
    }
    else{
        head->prev = newnode;
        head = newnode;
    }
    printf("Node inserted at the beginning.");
}

void insertAtEnd(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = tail;
    if (tail == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
    printf("Node inserted at the end.");
}

void deleteAtFirst(){
    struct node *temp;
    if (head == NULL){
        printf("List is empty. Create a linked list");
        return;
    }
    temp = head;
    head = head -> next;
    if(head != NULL){
        head -> prev = NULL;
    }
    else{
        tail = NULL;
    }
    printf("Deleted ele: %d\n", temp->data);
    free(temp);
}

void deleteLast(){
    struct node *temp;
    if (head == NULL){
        printf("List is empty. Create a linked list");
        return;
    }
    temp = tail;
    tail = tail->prev;
    if (tail != NULL){
        tail->next = NULL; 
    }
    else{
        head = NULL;
    }
    printf("Deleted ele: %d\n", temp->data);
    free(temp);
}

void deleteByValue(int value){
    struct node *temp = head;
    if (head == NULL){
        printf("List is empty. Create a linked list");
        return;
    }
    while (temp != NULL && temp->data != value){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Value not found.");
        return;
    }
    if (temp == head){
        deleteAtFirst();
    }
    else if(temp == tail){
        deleteLast();
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    printf("Deleted ele: %d\n", temp->data);
    free(temp);
}

void display(){
    struct node *temp = head;
    if (head == NULL){
        printf("List is empty.");
    }
    else{
        printf("Linked List:\n");
        while (temp != NULL){
            printf("%d ->",temp -> data);
            temp = temp -> next;
        }
    }
}

int main(){
    int ch, n, value, data;
    do{
        printf("\n1)Create doubly linked list 2)Insert at first 3)Insert at last 4)Delete by value 5)Display list");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1: 
                printf("Enter no. of nodes:");
                scanf("%d",&n);
                createlist(n);
                break;
            case 2:
                printf("Enter data:");
                scanf("%d",&data);
                insertAtFront(data);
                break;
            case 3:
                printf("Enter data:");
                scanf("%d",&data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter value:");
                scanf("%d",&value);
                deleteByValue(value);
                break;
            case 5:
                display();
                break;
            deafult: printf("Invalid input.");
        }
    }while(ch != -1);
}