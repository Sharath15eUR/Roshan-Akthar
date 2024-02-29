#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int a,b;
    printf("Enter any two integers:\n");
    scanf("%d%d",&a,&b);
    void (*ptrswap)(int*,int*);
    ptrswap = swap;
    printf("\nBefore Swapping:\na=%d,b=%d",a,b);
    ptrswap(&a,&b);
    printf("\nAfter Swapping:\na=%d,b=%d",a,b);
    return 0;
}
