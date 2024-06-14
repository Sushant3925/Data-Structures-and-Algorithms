#include<stdio.h>
#include<stdlib.h>

int BSearch(int arr[],int element,int size)
{
    int high,low,mid;
     high = size-1;
    low = 0;
    for( ;low <= high ; )
    {
    mid = (low+high)/2;

    if(arr[mid] == element)
    {
            return mid;
            
    }
    else if(arr[mid] > element)
    {
        high = mid-1;
    }
    else if(arr[mid] < element)
    {
        low = mid+1;
    }
    else{
        return -1;
        
    }
    }

}

int main()
{
    int element;
    int arr[] = {3,4,8,76,90,120,130,136};
    printf("Enter the number to be search: ");
    scanf("%d",&element);
    int size = sizeof(arr)/sizeof(int);
    int res = BSearch(arr,element,size);

    if(res != -1)
    {
        printf("%d is found at %d",element,res);
    }
    else
    {
        printf("%d is not found!!",element);
    }
}