#include<stdio.h>

int main()
{
    int arr[]={2,1,12,13,11,100,2};
    int max = 0;
    int size = sizeof(arr)/sizeof(int);
    int i;
    for ( i = 0; i <size-1; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
      
    }
    
     printf("max: %d",max);
}