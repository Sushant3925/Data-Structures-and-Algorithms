#include<stdio.h>
#include<stdlib.h>

struct graph
{
    int data;
    struct graph *next;
};
struct graph *temp,*r,*list[5];

int main()
{
   int G[10][10],i,j;
    int node;

    printf("\nEnter the number of nodes: ");
    scanf("%d",&node);
   for ( i = 0; i < node; i++)
   {
        for ( j = 0; j < node; j++)
        {
            printf("Enter 1 if edge present between(%d,%d): ",i,j);
            scanf("%d",&G[i][j]);

        }
        
   }

   printf("\nAdjacency matrux : \n");

   for ( i = 0; i < node; i++)
   {
        for ( j = 0; j < node; j++)
        {
            printf("%d ",G[i][j]);
        }

        printf("\n");
   }
   
   //creating adjacency list

   for (i = 0; i < node; i++)
   {
        list[i] = NULL;
        for ( j = 0; j < node; j++)
        {
            if(G[i][j] == 1)
            {
                temp = (struct graph *)malloc(sizeof(struct graph));
                temp->data = j;
                temp->next =NULL;
                if(list[i] == NULL)
                {
                    list[i] = temp;
                    r = temp;
                }
                else
                {
                    r->next = temp;
                    r = temp;
                }


            }

        }
        
   }
    //Adjacency list

    printf("\nAdjacency list: \n");

    for ( i = 0; i < node; i++)
    {
        printf("%d ",i);

        for ( temp = list[i];temp != NULL; temp = temp->next)
        {
            printf("| %d |-> ",temp->data);
        }

        printf("| NULL");
        printf("\n");
        
    }
    
}