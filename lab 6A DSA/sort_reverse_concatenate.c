#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;  

void createList(struct node **head, int n){
    struct node *newnode, *temp=NULL;
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
        if (*head == NULL){
            *head = newnode;
        }
        else{
            temp -> next = newnode;
        }
        temp = newnode;
    }
    printf("Linked list is created.");

}

void bubbleSort(struct node *head){
    struct node *i, *j, *tempdata;
    if (head == NULL){
        return;
    }
    for (i=head; i->next != NULL; i=i->next){
        for (j=i->next; j != NULL; j = j->next){
            if (i->data > j->data){
                tempdata = i->data;
                i->data = j->data;
                j->data = tempdata;
            }
        }
    }
}

struct node *reverse(struct node *head){
    struct node *prev = NULL, *cur = head, *next = NULL;
    while (cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct node *concatenate(struct node *head1, struct node *head2){
    struct node *temp;
    if (head2 == NULL){
        return head1;
    }
    if (head1 == NULL){
        return head2;
    }
    temp = head1;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

void display(struct node *head){
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
    int ch, n, listChoice;
    do{
        printf("\n1)Create linked list 2)Sort linked list 3)Reverse linked list 4)Concatenation 5)Display list");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch){
            case 1: 
                printf("List choice(1 or 2):");
                scanf("%d",&listChoice);
                printf("Enter no. of nodes:");
                scanf("%d",&n);
                if (listChoice == 1){
                    createList(&head1,n);
                }
                else if (listChoice == 2){
                    createList(&head2,n);
                }
                else{
                    printf("invalid list number");
                }
                break;
            case 2:
                printf("Sort list(1 or 2):");
                scanf("%d",&listChoice);
                
                if (listChoice == 1){
                    bubbleSort(&head1);
                }
                else if (listChoice == 2){
                    bubbleSort(&head2);
                }
                else{
                    printf("invalid list");
                }
                break;
            case 3:
                printf("Reverse list(1 or 2):");
                scanf("%d",&listChoice);
                
                if (listChoice == 1){
                    head1 = reverse(&head1);
                }
                else if (listChoice == 2){
                    head2 = reverse(&head2);
                }
                else{
                    printf("invalid list");
                }
                break;
            case 4:
                head1 = concatenate(head1,head2);
                break;
            case 5:
                printf("\nList1:");
                display(head1);
                printf("\nList2:");
                display(head2);
                break;
            default: printf("Invalid input.");
        }
    }while(ch != -1);
}