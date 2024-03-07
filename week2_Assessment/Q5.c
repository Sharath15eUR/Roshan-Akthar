#include <stdio.h>
#include<string.h>

char stack[100];

char input[50];
char output[50];

int top=-1;

void push(int elem, int size)
{
    if(top==size+1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        top++;
        stack[top] = elem;
        printf("Pushed %c\n",elem);
    }
    
}

char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow!");
    }
    else
    {
        printf("Popped %c\n",stack[top]);
        return stack[top--];
    }
}
int main()
{
    int size;
    printf("Enter the String:\n");
    scanf("%s",input);
    size = strlen(input);
    for(int i=0;i<size;i++)
    {
        push(input[i],size);
    }
    for(int i=0;i<size;i++)
    {
        output[i] = pop();
    }
    for(int i=0;i<size;i++)
    {
        printf("%c",output[i]);
    }
    return 0;
}

