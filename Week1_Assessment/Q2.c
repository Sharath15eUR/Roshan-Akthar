#include <stdio.h>

int bitssets(int n)
{
    int count;
    while(n>=1)
    {
        if(n&1==1)
         count++;
        n>>=1;
    }
    return count;
}

int main()
{
    int n,count;
    printf("Enter any integer:");
    scanf("%d",&n);
    count=bitssets(n);
    printf("The number of set bits is %d",count);
    return 0;
}
