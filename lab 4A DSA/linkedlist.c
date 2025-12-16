#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void createList(int n){
    struct node *newnode, *temp;
    int data, i;
    if (n<0){
        printf("n should be greater than 0.");
        return;
    }
    for(i=1; i<=n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL){
            printf("Memory alloction failed.");
            return;
        }
        printf("Enter data:");
        scanf("%d",&data); 
        newnode -> data = data;
        newnode -> next = NULL;
        if (head == NULL){
            head = newnode;
        }
        else{
            temp -> next = newnode;
        }
        temp = newnode;
    }
    printf("Linked list is created.");

}

void insertAtBeginning(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = head;
    head = newnode;
    printf("Node inserted at the beginning.");
}

void insertAtEnd(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    if (head == NULL){
        head = newnode;
    }
    else{
        struct node *temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
    printf("Node inserted at the end.");
}

void insertAtPosition(int data, int pos){
    int i;
    struct node *newnode, *temp = head;
    if (pos<1){
        printf("Invalid position.");
        return;
    }
    if (pos == 1){
        insertAtBeginning(data);
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    for (i=1; i<pos-1 && temp!=NULL; i++){
        temp = temp ->next;
    }
    if(temp == NULL){
        printf("Position out of range.");
        free(newnode);
    }
    else{
    newnode -> next = temp -> next;
    temp -> next = newnode;
    printf("Node inserted at position %d",pos);
    }    
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
    int ch, n, data, pos;
    do{
        printf("\n1)Create linked list 2)Insert at beginning 3)Insert at any position 4)Insert at end 5)Display list");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1: 
                printf("Enter no. of nodes:");
                scanf("%d",&n);
                createList(n);
                break;
            case 2:
                printf("Enter data:");
                scanf("%d",&data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data, position:");
                scanf("%d %d",&data, &pos);
                insertAtPosition(data,pos);
                break;
            case 4:
                printf("Enter data:");
                scanf("%d",&data);
                insertAtEnd(data);
                break;
            case 5:
                display();
                break;
            deafult: printf("Invalid input.");
        }
    }while(ch != -1);
}