#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void printlinkedlist(struct Node *start)
{
    struct Node *temp3;
    temp3 = start;
    while (temp3->right != NULL)
    {
        printf("%d->", temp3->data);
        temp3 = temp3->right;
    }
    printf("%d\n", temp3->data);
}

void insertnode(struct Node *start)
{
    int value;
    struct Node *temp3 = start;
    while (temp3->right != NULL)
    {
        temp3 = temp3->right;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter the value for the new element:\n");
    scanf("%d", &value);
    newNode->data = value;
    temp3->right = newNode;
    newNode->left = temp3;
    newNode->right = NULL;
}

void sorting(struct Node *start, int size)
{
    struct Node *temp4;
    struct Node *temp5;

    for (int i = 0; i < size; i++)
    {
        temp4 = start;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (temp4->data > temp4->right->data)
            {
                int swap = temp4->data;
                temp4->data = temp4->right->data;
                temp4->right->data = swap;
            }
            temp4 = temp4->right;
        }
    }
}

int main()
{
    struct Node *start = (struct Node *)malloc(sizeof(struct Node));
    if (start == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int n, temp1;
    printf("Enter the size of the linked list:\n");
    scanf("%d", &n);

    struct Node *temp = start;
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp1);
        temp->data = temp1;

        if (i < n - 1)
        {
            temp->right = (struct Node *)malloc(sizeof(struct Node));
            if (temp->right == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1;
            }
            temp->right->left = temp;
            temp = temp->right;
        }
        else
        {
            temp->right = NULL;
        }
    }

    sorting(start, n);

    printf("The elements of the doubly linked list before inserting new nodes:\n");
    printlinkedlist(start);

    while (1)
    {
        int wish;
        printf("\nDo you wish to insert value in sorted way:\n 1.yes\n 2.No\n");
        scanf("%d", &wish);
        if (wish == 2)
        {
            break;
        }
        else if (wish == 1)
        {
            insertnode(start);
            n++;
            sorting(start, n);
        }
    }

    printf("\nThe elements of the doubly linked list after inserting new nodes:\n");
    printlinkedlist(start);

    free(start); 

    return 0;
}

