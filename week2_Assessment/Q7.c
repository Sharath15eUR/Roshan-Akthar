#include <stdio.h>
#define size 10


int queue[size];
int front = -1, rear = -1;

void enqueue(int elem)
{
  if (front == size - 1)
	{
	  printf ("Queue Overflow!");
	}
  else
	{
	  rear++;
	  queue[rear] = elem;
	  printf ("Enqueued %d\n", elem);
	  if (front == -1)
		{
		  front = 0;
		}
	}
}

void dequeue()
{
  if (front > rear)
	{
	  printf ("Queue underflow!");
	}
  else
	{
	  printf ("Dequeued\n");
	  front++;
	}
}

void display()
{
  int temp = front;
  printf("Queue elements are: ");
  while (temp <= rear)
	{
	  printf ("%d\t", queue[temp]);
	  temp++;
	}
}

void count()
{
  int temp = front;
  int count=0;
  if(front==-1 && rear==-1 || front>rear)
  {
      printf("The Queue is empty!\n");
  }
  else
  {
      printf("Number of elements in queue: ");
      while (temp <= rear)
    	{
    	  count++;
    	  temp++;
    	}
      printf ("%d", count);
  }
}

int main ()
{
  printf("Queue is Initialized!\n");
  int elem, choice, wish;
  do
	{
	  printf
		("Enter\n 1->Enqueue\n 2->Dequeue\n 3->Display\n 4->check the number of elements in the queue\n");
	  scanf ("%d", &choice);
	  switch (choice)
		{
		case 1:
		  printf ("Insert some elements into the queue: \n");
		  scanf ("%d", &elem);
		  enqueue (elem);
		  break;
		case 2:
		  printf ("Delete some elements from the queue: \n");
		  scanf ("%d", &elem);
		  for(int i=0;i<elem;i++)
		  {
		      dequeue ();
		  }
		  break;
		case 3:
		  display ();
		  break;
		case 4:
		  count();
		  break;
		default:
		  printf ("Invalid Choice\n");
		}
	  printf ("\nDo you want to continue? \n 1.Yes \n 2.No\n");
	  scanf ("%d", &wish);
	}
  while (wish == 1);

  return 0;
}
