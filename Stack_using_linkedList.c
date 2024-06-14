
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *top ;
void init_stack()
{
    top =NULL;
}
int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *new()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&temp->data);

    temp->next = NULL;
    return temp; 
}
void push()
{
    if(isFull())
    {
        printf("\nStack Overflow .. can't perform push operation!!");

    }
    else{
        struct node *ptr = new();
        if(top == NULL)
        {
            top =ptr;
            top->next = NULL;
        }
        else
        {
            ptr->next = top;
            top = ptr;
        }
    }
}
int pop()
{
    if(isEmpty())
    {
        printf("\nStack is empty!");
        
    }
    else
    {
        struct node *ptr = top;
        top = top->next;
        int data = ptr->data;
        free(ptr);
        return data;
    }
}
void display_stack()
{
    struct node *ptr = top;
    printf("\n");
    while(ptr != NULL )
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int StackTop()
{
    if(isEmpty())
    {
        printf("\nStack is empty!");
    }
    else
    {
        return top->data;
    }
}
int StackBottom()
{
    if(isEmpty())
    {
        printf("\nStack is empty!");
    }
    else
    {
        struct node *ptr = top;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }
}
int peek(int pos)
{
    if(isEmpty())
    {
        printf("\nStack is empty!");
        return -1;
    }
    else{
        int i = 0;
        struct node *ptr = top;
        while(i != pos)
        {
            ptr = ptr->next;
            i++;
        }
        return ptr->data;
    }
}
int main()
{
    int choice;
    int deleted_value;
     int pos;
    int top_Value;
    int res;

    do
    {
        printf("\n1.Initialize stack (create stack)\n2.isFull\n3.isEmpty\n4.push\n5.pop\n6.peek\n7.display stack\n8.Stacktop \n9.stackBottom\n10.exit!!\n\nEnter the choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
                init_stack();
                break;
        case 2:
                 res = isFull();
                 if(res ==1)
                 {
                    printf("\nStack is full ... Can't perform push operation!! ");

                 }
                 else
                 {
                     printf("\nStack is not full ");
                 }
                 break;
        case 3:
                res = isEmpty();
                if(res == 1)
                {
                    printf("\nStack is empty ... Can't perform pop operation!! ");
                }
                else
                {
                    printf("\nStack is not empty ");
                }
                 break;  
        case 4:
                 push();
                 display_stack();
                 break;
        case 5:
                 deleted_value = pop();
                 printf("\n%d is popped successfully.",deleted_value);
                 break; 
        case 6:
                
                 printf("Enter the position of stack element: ");
                 scanf("%d",&pos);
                 res = peek(pos);
                 if(res != -1)
                 {
                 printf("\nAt position %d element is %d",pos,res);
                 }
                 break;
        case 7:
                display_stack();
                break; 
        case 8:
                res = StackTop();
                printf("\nTop most value of stack is %d",res);
                break; 
        case 9:
                res = StackBottom();
                printf("\nBottom most value of stack is %d",res);
                break;            
        default:
            break;
        }
    } while (choice != 10);
    




}