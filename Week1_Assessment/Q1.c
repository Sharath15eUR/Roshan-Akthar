#include <stdio.h>

int oddoreven(int n)
{
    if(n & 1 == 1)
        return 1;
    else
       return 0;
}

int main()
{
    int n;
    
    printf("Enter any integer:");
    scanf("%d",&n);
    
    if(oddoreven(n))
     printf("The number %d is odd ",n);  
    else
     printf("The number %d is even ",n);

    return 0;
}
