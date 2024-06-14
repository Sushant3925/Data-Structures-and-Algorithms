#include<stdio.h>

int LSearch(int a[],int element,int size)
{
    for (int i = 0; i < size; i++)
    {
        if(a[i] == element)
        {
            return i;
        }
    }
    return -1;
    
}
int main()
{
    int element;
    int arr[100] = {3,4,52,8,76,90,6,7,8,2,6,9};
    printf("Enter the number to be search: ");
    scanf("%d",&element);
    int size = sizeof(arr)/sizeof(int);
    int res = LSearch(arr,element,size);

    if(res != -1)
    {
        printf("%d is found at %d",element,res);
    }
    else
    {
        printf("%d is not found!!",element);
    }
}