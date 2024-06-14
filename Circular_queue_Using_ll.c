#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
struct queue *f = NULL;
struct queue *r = NULL;

int isFull()
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    if (temp == NULL)
    {
        return 1;
    }
    return 0;
}
struct queue *new()
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    printf("\nEnter the data: ");
    scanf("%d", &temp->data);

    temp->next = NULL;
    return temp;
}
void enqueue()
{

    char ch;
    do
    {

        if (isFull())
        {
            printf("\nQueue is Full");
            break;
        }
        else
        {
            struct queue *ptr = new ();
            if (f == NULL)
            {
                f = r = ptr;
            }
            else
            {
                r->next = ptr;
                r = ptr;
            }
        }
        printf("\nDo you want to add more[Y/N] data in queue:");
        ch = getche();

    } while (ch == 'y');
}
int dequeue()
{
    int val = -1;
    if (f == NULL)
    {
        printf("Queue is Empty!!");
    }
    else
    {
        struct queue *ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
void qTraverse()
{
    struct queue *ptr = f;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}
int main()
{
    int choice;
    int res;
    do
    {
        printf("\n1.Insert (Enqueue)or create Queue \n2.Dequeue\n3.Queue Traverse\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            res = dequeue();
            printf("\n%d is deleted from Queue \n", res);
            break;
        case 3:
            qTraverse();
            break;
        }
    } while (choice != 4);
}