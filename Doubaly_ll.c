#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node *new()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &temp->data);

    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}
void create_DLL()
{
    char ch;
    do
    {
        struct node *ptr = new ();
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
        }
        printf("\nDo you want to add anoter node on DLL: ");
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
}
void display_DLL()
{
    struct node *temp = head;
    printf("\n");
    printf("NULL");
    while (temp != NULL)
    {
        printf("<-| %d |-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}
void insertAtBeg()
{
    struct node *ptr = new ();
    struct node *temp = head;

    ptr->next = temp;
    temp->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
}
void insertAtIndex()
{
    struct node *ptr = head;
    int index, i = 0;
    printf("Enter the index: ");
    scanf("%d", &index);

    struct node *temp = new ();

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
}
void insertAtEnd()
{
    struct node *ptr = head;
    struct node *temp = new ();
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
}
void insertAfterNode()
{
    int value;
    printf("Enter the value of node: ");
    scanf("%d", &value);

    struct node *temp = head;
    struct node *ptr = new ();
    while (temp->data != value && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->data == value)
    {
        ptr->next = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
    }
}
void deleteAtFirst()
{
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}
void deleteAtIndex()
{
    int index, i = 0;
    printf("Enter the index: ");
    scanf("%d", &index);

    struct node *p = head;
    struct node *q;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    struct node *ptr = q->next;
    ptr->prev = p;
    free(q);
}
void deleteAtEnd()
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}
void deleteAtValue()
{
    int value;
    printf("Enter the value of node:");
    scanf("%d",&value);
    struct node *temp = head;
    struct node *ptr = temp->next;
    while (ptr->data != value && ptr->next != NULL)
    {
        ptr = ptr->next;
        temp = temp->next;
    }
    struct node *p = ptr->next;
    temp->next = ptr->next;
    p->prev = temp;
    free(ptr);
    
}
int main()
{
    int choice;
    do
    {

        printf("\n1.create Doubly  linked list \n2.insert element at begening \n3.insert element at given index \n4.insert at end \n5.insert after the node \n6.Deleting node at beginning \n7.delete at given index\n8.delete at end \n9.delete at given value\n10.Bubble sort \n11.exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_DLL();
            display_DLL();
            break;

        case 2:
            insertAtBeg();
            display_DLL();
            break;
        case 3:
            insertAtIndex();
            display_DLL();
            break;

        case 4:
            insertAtEnd();
            display_DLL();
            break;
        case 5:
            insertAfterNode();
            display_DLL();
            break;
        case 6:
            deleteAtFirst();
            display_DLL();
            break;
        case 7:
            deleteAtIndex();
            display_DLL();
            break;

        case 8:
            deleteAtEnd();
            display_DLL();
            break;

        case 9:
            deleteAtValue();
            display_DLL();
            break;
        // case 10:
        //     Bubbl case 2:
        //     insertAtBeg();
        //     display_CLL();
        //     break;
        default:
            break;
        }
    } while (choice != 11);
}