#include <stdio.h>
#define size 10

int queue[size];
int front=-1,rear=-1;

void enqueue(int elem)
{
    if(front == size-1)
    {
        printf("Queue Overflow!");
    }
    else
    {
        rear++;
        queue[rear] = elem;
        printf("Enqueued %d\n",elem);
        if(front==-1)
        {
            front=0;
        }
    }
}

void dequeue()
{
    if(front>rear)
    {
       printf("Queue underflow!"); 
    }
    else
    {
        printf("Dequeued\n");
        front++;
    }
}

void sorting()
{
    for (int i = front; i <= rear - 1; i++)
    {
        for (int j = front; j <= rear - i - 1; j++)
        {
            if (queue[j+1] < queue[j])
            {
                int swap = queue[j + 1];
                queue[j + 1] = queue[j];
                queue[j] = swap;
            }
        }
    }
}

void display()
{
    int temp = front;
    while(temp<=rear)
    {
        printf("%d\t",queue[temp]);
        temp++;
    }
}

int main()
{
    int elem,choice,wish;
    
    do
    {
        printf("Enter\n 1->Enqueue\n 2->Dequeue\n 3->Sort the Queue\n 4->Display the Queue\n");  
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the Element to Enqueue:\n");   
            scanf("%d",&elem);
            enqueue(elem);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            sorting();
            break;
            case 4:
            display();
            break;
            default:
            printf("Invalid Choice\n");
        }
        printf("\nDo you want to continue? \n 1.Yes \n 2.No\n");
        scanf("%d",&wish);
    }while(wish==1);
    
    return 0;
}
