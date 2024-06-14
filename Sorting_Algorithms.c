#include <stdio.h>
#include<stdlib.h>

void accept(int *arr, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void display(int *arr, int n)
{
    printf("Data in the array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void BubbleSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Pass is %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void ConvinientBubbleSort(int *arr, int n)
{
    int temp;
    int isSorted = 0;

    for (int i = 0; i < n - 1; i++)
    {
        isSorted = 1;
        printf("Pass is %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 1;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

void insertion_sort(int *arr, int n)
{
    int key, j;
    for (int i = 1; i <= n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int *arr, int n)
{
    int MinimumIndex, temp;
    for (int i = 0; i < n - 1; i++)
    {
        MinimumIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[MinimumIndex])
            {
                MinimumIndex = j; // it Selct the index of array element which has minimum value
            }
        }
        // swap between i'th value and minimum index value (i is staring from 0 )

        temp = arr[MinimumIndex];
        arr[MinimumIndex] = arr[i];
        arr[i] = temp;
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        /* code */
        while (arr[i] <= pivot) // i locates the value which is less than pivot value
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i < j);

    // swap between pivot element and value at j
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quick_sort(int *arr, int low, int high)
{
    int partition_Index;

    if (low < high)
    {
        int partition_Index = partition(arr, low, high);
        quick_sort(arr, low, partition_Index - 1);
        quick_sort(arr, partition_Index + 1, high);
    }
}

void merge(int arr[],int low,int high,int mid)
{
    int i,j,k,B[100];
    i = low;
    j = mid+1;
    k = low;
    while(i<=mid  &&  j<=high)
    {
        if(arr[i]<arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
           
        }
        
        else
        {
            printf("%d  ",arr[j]);
            B[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        B[k] = arr[j];
        j++;
        k++;
     }
    for (i = low; i <= high; i++)
    {
        arr[i] = B[i];

    }   
}
void merge_sort(int arr[],int low ,int high)
{
     int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

int maximum(int *arr,int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
    
}
void count_sort(int *arr,int n)
{
    int max = maximum(arr,n);

    printf("max: %d",max);
    int *count = (int *)malloc((max+1) * sizeof(int));

    int i,j;
    for ( i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    //Count the occurance of each element of main array
    for ( i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]]+1;
    }

    i = 0; //to get index from count array 
    j = 0; //To initialize value in main array

    while ( i<= max)
    {
        if(count[i] > 0)
        {   
            arr[j] = i;
            count[i] = count[i]-1;
            j++;
            
        }
        else{
            i++;
        }
        
    }
    
      
}
int main()
{
    int arr[10];
    int n;
    int choice;
    do
    {
        printf("\n1.create and print array \n2.Bubble sort and convinient Bubble sort\n3.Insertion sort \n4.selection \n5.Quick Sort\n6.Merge Sort\n7.Count Sort\n8.Exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nHow many elements: ");
            scanf("%d", &n);
            accept(arr, n);
            printf("Array before sort: \n");
            display(arr, n);
            break;

        case 2:
            printf("\nBubble sort: \n");

            printf("\nAfter Regular Sort: \n");
            BubbleSort(arr, n);
            display(arr, n);

            printf("\nAfter convinient way of sort: \n");
            ConvinientBubbleSort(arr, n);
            display(arr, n);
            break;

        case 3:

            // -1   0    1   2   3   4   5
            //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
            //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

            //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
            //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

            //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
            //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
            //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
            //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
            //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

            // Fast forwarding and 4th and 5th pass will give:
            //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
            //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

            //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
            //      07, 09, 12, 23, 54, 65| --> After the 5th pass
            printf("\nInsertion Sort : \n");
            insertion_sort(arr, n);
            display(arr, n);
            break;

        case 4:
            // THIS ALGORITHM IS NOT STABLE BECAUSE THIS EXECUTES THE CODE STILL IT HAS SORTED ARRAY.
            //  Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
            //   00  01  02  03  04
            //  |03, 05, 02, 13, 12

            // After first pass
            //  00  01  02  03  04
            //  02,|05, 03, 13, 12

            // After second pass
            // 00  01  02  03  04
            // 02, 03,|05, 13, 12

            // After third pass
            // 00  01  02  03  04
            // 02, 03, 05,|13, 12

            // After fourth pass
            // 00  01  02  03  04
            // 02, 03, 05, 12,|13

            selection_sort(arr, n);
            display(arr, n);
            break;

        case 5:
            quick_sort(arr, 0, n - 1);
            display(arr, n);
            break;
        
        case 6:

            merge_sort(arr,0,n-1);
            display(arr,n);
            break;
        case 7:
            
            count_sort(arr,n);
            display(arr,n);
            break;
        }

    } while (choice != 8);

    return 0;
}
