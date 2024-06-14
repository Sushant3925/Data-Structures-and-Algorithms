#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};

void init_queue(struct queue *q)
{
        q->size = 10;
        q->f = q->b = -1;
        q->arr = (int *)malloc(q->size * sizeof(int));
        printf("Queue is successfully initialized .");

}
void QueueTraverse(struct queue *q)
{
    printf("\nData in queue: ");
    
    while(q->f <= q->b)
    {
        printf("%d -> ",q->arr[q->f]);
       q->f++;
    }
}
int isFull(struct queue *q)
{
    if(q->f == q->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q)
{
    if(q->f == q->b)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q)
{
    int val;
    printf("\nEnter the value : ");
    scanf("%d",&val);

    if(isFull(q))
    {
        printf("\nQueue is full : ");

    }
    else
    {
        if(q->f = q->b ==-1)
        {
            q->b++;
            q->f++;
            q->arr[q->b] = val;
        }
        else
        {
            q->b++;
            q->arr[q->b] = val;
        }
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
        if(isEmpty(q))
        {
            printf("Queue is Empty!!");
        }
        else
        {

            a = q->arr[q->f++];
          
        }
        return a;
}
int main()
{
    
    int res;
    int choice;
    struct queue q;
    do
    {
        printf("\n\n1.Initialize queue\n2.Enqueue\n3.Dequeue\n4.isfull\n5.isempty\n6.display queue\n7.exit\nEnter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            
            init_queue(&q);
            break;

         case 2:
            enqueue(&q);
            break;

        case 3:
            res = dequeue(&q);
            printf("\n%d is removed from queue",res);
            break;      

        case 4:
            res = isFull(&q);
            if(res == 1)
            {
                printf("\nQueue is overfloW !!");
            }
            else
            {
                printf("\nQueue us not full ");
            }
            break;
        case 5:
            res = isEmpty(&q);
             if(res == 1)
            {
                printf("\nQueue is underflow !!");
            }
            else
            {
                printf("\nQueue us not full ");
            }
            break;
        case 6:
            QueueTraverse(&q);
            break;

        }
    } while (choice != 7);
    
}