#include<stdio.h>
void display(int a[],int size)
{
    int i;
    for ( i = 0; i < size; i++)
    {
        printf("%d ",a[i]);  
    }
    printf("\n");
    
}
int indInsertion(int a[],int size, int index,int element)
{
    int i;
    for (i = size-1; i >= index; i--)
    {
        a[i+1] = a[i];

    }
    a[index] = element;
    return 1;
       
}
int main()
{
    int arr[100] = {2,4,6,8,3,10};
    int size = 6;
    int element;
    printf("Enter the ekement to be insert: ");
    scanf("%d",&element);
    display(arr,size);

    int res = indInsertion(arr,size,2,element);
    size +=1;
    if(res == 1)
    {
        printf("successfully inserted element:\n");

    display(arr,size);
    }
    else
    {
        printf("Unable to insert element");
    }

}