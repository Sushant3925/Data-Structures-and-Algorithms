#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *new()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}
void create_CLL()
{
    char c;
    do
    {
        struct node *temp = new();

        if(head == NULL)
        {
            head = temp;
            temp->next = head;

        }
        else
        {
            struct node *r = head;
            while (r->next != head)
            {
                r = r->next;
            }
            r->next = temp;
            temp->next = head;
        }
        printf("Do you want to add more nodes: ");
        c = getche();
        
    } while (c == 'Y' || c == 'y');
    
}
void display_CLL()
{
    struct node *temp = head;

        printf("\n");
        do
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("-> %d ",temp->data);
        printf("\n");

}
void insertAtBeg()
{
    struct node *temp = head;
    struct node *ptr = new();

    if(head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else{
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp ->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    
}
void insertAtIndex()
{
    int index;
    struct node *temp=head;
    int i = 0;
    printf("\nEnter the indedx: ");
    scanf("%d",&index);

    struct node *ptr = new();
    while(i !=index-1)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;


}
void insertAtEnd()
{
    struct node *temp = head;
    struct node *ptr = new();
    while(temp->next != head)
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next=ptr;
}


void insertAfterNode()
{
    struct node *temp = head;
    struct node *ptr = new(); 
    int value;
    printf("Enter the value of a node:");
    scanf("%d",&value);

    while(temp->data != value && temp->next != head)
    {
        temp = temp->next;
    }

    if(temp->data == value)
    {
            ptr->next = temp->next;
            temp->next = ptr;
    }

}
void deleteAtFirst()
{
    struct node *temp = head;
    struct node *ptr = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    free(ptr);

}
void deleteAtIndex()
{
    int index,i=0;
    struct node *temp = head;
    printf("Enter the index: ");
    scanf("%d",&index);

    while(i != index-1)
    {
        temp = temp->next;
        i++;
    }
    struct node *ptr = temp->next;
    temp->next = ptr->next;

    free(ptr);

}
void deleteAtEnd()
{
    struct node *p = head;
    struct node *q = p->next;

    while (q->next != head)
    {
        q=q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);
    
}
void deleteAtValue()
{
    int value;
    struct node *ptr = head;
    struct node *temp = ptr->next;

    printf("Enter the value to delete: ");
    scanf("%d",&value);

    while(temp->data != value && temp->next !=head)
    {
        temp = temp->next;
        ptr = ptr->next;
    }
    if(temp->data == value)
    {
        ptr->next = temp->next;
        free(temp);
    }
}
int main()
{
    int choice;
    do
    {

        printf("\n1.create Circular  linked list \n2.insert element at begening \n3.insert element at given index \n4.insert at end \n5.insert after the node \n6.Deleting node at beginning \n7.delete at given index\n8.delete at end \n 9.delete at given value\n10.Bubble sort \n11.exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_CLL();
            display_CLL();
            break;
        case 2:
            insertAtBeg();
            display_CLL();
            break;
        case 3:
            insertAtIndex();
            display_CLL();
            break;

        case 4:
            insertAtEnd();
            display_CLL();
            break;
        case 5:
            insertAfterNode();
            display_CLL();
            break;
        case 6:
            deleteAtFirst();
            display_CLL();
            break;
        case 7:
            deleteAtIndex();
            display_CLL();
            break;

        case 8:
            deleteAtEnd();
            display_CLL();
            break;
        case 9:
            deleteAtValue();
            display_CLL();
            break;
        // case 10:
        //     BubbleSort();
        //     displayList();
        //     break;
        
        default:
            break;
        }
    } while (choice != 11);
}