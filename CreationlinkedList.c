#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *r;

struct node *new()
{
    int val;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d", &val);

    temp->data = val;
    temp->next = NULL;
    return temp;
}
void displayList()
{
    if (head == NULL)
    {
        printf("Linked list is empty!!");
    }
    else
    {
        r = head;
        printf("\n");
        while (r != NULL)
        {
            printf("%d -> ", r->data);
            r = r->next;
        }
        printf("\n");
    }
}
void create()
{
    char ch;
    do
    {
        new ();
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            r = head;
            while (r->next != NULL)
            {
                r = r->next;
            }
            r->next = temp;
        }
        printf("Do you want to continue (Y/N)");
        ch = getche();
    } while (ch == 'Y' || ch == 'y');
}
// insert at begening
void insertAtBeg()
{
    struct node *ptr = new ();
    ptr->next = head;
    head = ptr;
    // return head;
}
// insert at index
void insertAtIndex()
{
    int index;
    int i = 0;
    printf("Enter the index: ");
    scanf("%d", &index);
    struct node *p = head;
    struct node *ptr = new ();

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
}
// insert at end
void insertAtEnd()
{
    struct node *p = head;
    struct node *ptr = new ();
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
// insert after node
struct node *getNode()
{
    int i = 0, index;
    printf("Enter the index: ");
    scanf("%d", &index);

    struct node *ptr = head;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    return ptr;
}
void insertAfterNode()
{
    struct node *Node = getNode();
    struct node *t = new ();

    t->next = Node->next;
    Node->next = t;
}
void deleteAtFirst()
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}
void deleteAtIndex()
{
    struct node *ptr = head;
    int index;
    printf("Enter the Index: ");
    scanf("%d",&index);
    
    int i = 0;
    while (i != index-1)
    {
        ptr = ptr->next;
        i++;
    }
    struct node *p = ptr->next;
    ptr->next = p->next;
    free(p);
    
}
void deleteAtEnd()
{
    struct node *p = head;
    struct node *q = p->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

}
void deleteAtValue()
{
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);

    struct node * p = head;
    struct node * q = p->next;

    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
}
void BubbleSort()
{
    struct node *ptr;
    struct node *q , *t;
    
    for(ptr = head; ptr->next != NULL;ptr = ptr->next)
    {
        
        for (q = head->next; q->next != NULL; q = q->next)
        {
            printf("%d and %d \n",ptr->data,q->data);
            if(ptr->data > q->next->data)
            {
                t = ptr;
                ptr = q;
                q = t;
            }
        }
        
    }
}
int main()
{
    int choice;
    do
    {

        printf("\n1.create linked list \n2.insert element at begening \n3.insert element at given index \n4.insert at end \n5.insert after the node \n6.Deleting node at beginning \n7.delete at given index\n8.delete at end \n 9.delete at given value\n10.Bubble sort \n11.exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            displayList();
            break;
        case 2:
            insertAtBeg();
            displayList();
            break;
        case 3:
            insertAtIndex();
            displayList();
            break;

        case 4:
            insertAtEnd();
            displayList();
            break;
        case 5:
            insertAfterNode();
            displayList();
            break;
        case 6:
            deleteAtFirst();
            displayList();
            break;
        case 7:
            deleteAtIndex();
            displayList();
            break;

        case 8:
            deleteAtEnd();
            displayList();
            break;
        case 9:
            deleteAtValue();
            displayList();
            break;
        case 10:
            BubbleSort();
            displayList();
            break;
        
        default:
            break;
        }
    } while (choice != 11);
}