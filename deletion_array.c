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
int indDeletion(int a[], int size,int index)
{
    int i;
    for ( i = index; i < size-1; i++)
    {
        a[i]=a[i+1];
    }
   

    
}
int main()
{
    int arr[100] = {2,4,6,8,3,10};
    int size = 6;
    int element;
    
    display(arr,size);

        indDeletion(arr,size,2);
        size -=1;
        display(arr,size);
    

}