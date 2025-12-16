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

void deleteAtFirst(){
    struct node *temp;
    if (head == NULL){
        printf("List is empty. Create a linked list");
        return;
    }
    temp = head;
    head = temp -> next;
    printf("Deleted ele: %d\n", temp->data);
    free(temp);
}

void deleteLast(){
    struct node *temp, *prev;
    if (head == NULL){
        printf("List is empty. Create a linked list");
        return;
    }
    if (head -> next == NULL){
        printf("Deleted ele: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    printf("Deleted ele: %d\n", temp->data);
    free(temp);
}

void deleteSpecific(int value){
    struct node *temp = head, *prev = NULL;
    if (head == NULL){
        printf("List is empty. Create a linked list");
        return;
    }
    if (head -> data == value){
        deleteAtFirst();
        return;
    }
    while (temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Value not found.");
        return;
    }
    prev->next = temp->next;
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
    int ch, n, value;
    do{
        printf("\n1)Create linked list 2)Delete at first 3)Delete specific 4)Delete at last 5)Display list");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1: 
                printf("Enter no. of nodes:");
                scanf("%d",&n);
                createList(n);
                break;
            case 2:
                deleteAtFirst();
                break;
            case 3:
                printf("Enter value:");
                scanf("%d",&value);
                deleteSpecific(value);
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                display();
                break;
            deafult: printf("Invalid input.");
        }
    }while(ch != -1);
}