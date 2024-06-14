#include <stdio.h>
#include <stdlib.h>

#define Max 10
int main()
{
    int a[Max][Max], i, j, no;

    printf("\nHow many number od nodes do you have in your graph?: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
    {
        for (j = 0; j < no; j++)
        {
            a[i][j] = 0;
        }
    }

    for (i = 0; i < no; i++)
    {
        for (j = 0; j < no; j++)
        {
            if (i != j)
            {
                printf("\nEnter 1 if edge is present between (%d,%d) if not press 0:", i, j);
                scanf("%d", &a[i][j]);
            }
        }
    }

    printf("\nGraphical representation of matrix is: \n");
    for (i = 0; i < no; i++)
    {
        for (j = 0; j < no; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}