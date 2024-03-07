#include<stdio.h>
#include<stdbool.h>  

void main()
{
    int size1,size2;
    int count;
    
    printf("Enter the size of the 1st array:\n");
    scanf("%d",&size1);
    
    int arr1[size1];
    for(int i=0;i<size1;i++)
    {
     printf("Enter the %d element of the 1st array:\n",i);
     scanf("%d",&arr1[i]);   
    }
    printf("Enter the size of the 2nd array:\n");
    scanf("%d",&size2);
    
    int arr2[size2];
    for(int i=0;i<size2;i++)
    {
     printf("Enter the %d element of the 2nd array:\n",i);
     scanf("%d",&arr2[i]);   
    }
   
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(arr1[i]==arr2[j])
            {
                count++;
            }
        }
    }
    if(count==size2)
    {
        printf("arr2[] is a subset of arr1[]");
    }
    else
    {
        printf("arr2[] is a not subset of arr1[]");
    }
}