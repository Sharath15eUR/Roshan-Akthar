#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printlinkedlist(struct Node* start)
{
    struct Node* temp3;
    temp3=start;
    while(temp3->next!=NULL)
    {
        printf("%d->",temp3->data);
        temp3=temp3->next;
    }
    printf("%d",temp3->data);
}

int main()
{
    struct Node* start;
    start=(struct Node*)malloc(sizeof(struct Node));
    int n,temp1;
    printf("Enter the size of the linked list:\n");
    scanf("%d",&n);
    struct Node* temp;
    temp=start;
    printf("Enter the elements of the linked list:\n");
    scanf("%d",&temp1);
    temp->data=temp1;
    for(int i=1;i<n;i++)
    {
        struct Node* newNode;
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&temp1);
        newNode->data=temp1;
        temp->next=newNode;
        temp=newNode;
    }
    
    printf("The elements of the linked list before removing the duplicate elements:\n");
    printlinkedlist(start);
    
    struct Node* current;
    current=start;
    while(current != NULL && current->next != NULL)
    {
        if(current->data == current->next->data)
        {
         struct Node* temp2 = current->next;
         current->next = current->next->next;
         free(temp2);
        }
        current = current->next;
    }
    
    printf("\nThe elements of the linked list after removing the duplicate elements:\n");
    printlinkedlist(start);
    
    
    return 0;
}

