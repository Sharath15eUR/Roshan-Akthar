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

void rotateByN(struct Node** head, int N) {
    if (*head == NULL || N == 0) {
        return;
    }

    struct Node* current = *head;
    int count = 1;
    while (count < N && current != NULL) {
        current = current->right;
        count++;
    }

    if (current == NULL) {
        return;
    }

    struct Node* NthNode = current;

    while (current->right != NULL) {
        current = current->right;
    }

    current->right = *head;
    (*head)->left = current;
    *head = NthNode->right;
    (*head)->left = NULL;
    NthNode->right = NULL;
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

    printf("The elements of the doubly linked list before inserting new nodes:\n");
    printlinkedlist(start);

    int N;
    printf("Enter the number of nodes to rotate by: ");
    scanf("%d", &N);
    rotateByN(&start, N);


    printf("\nThe elements of the doubly linked list after inserting new nodes:\n");
    printlinkedlist(start);

    struct Node* temp5 = start;
    while (temp5 != NULL) 
    {
        struct Node *next = temp5->right;
        free(temp5);
        temp5 = next;
    }
return 0;
}


