#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};
struct stack *s;
void create_stack()
{
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));
    printf("\nStack has been created suxxessfully .");
}
int isFull()
{
    if(s->top == s->size-1)
    {
        return -1;
    }
    else
    {
       
        return 1;
    }
}

int isEmpty()
{
    if(s->top == -1)
    {
        
        return -1;
    }
    else
    {
        
        return 1;
    }
}
void push()
{
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);

    if(isFull() == -1)
    {
        printf("\nStack is full ... Can't perform push operation!! ");

    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop()
{

    if(isEmpty() == -1)
    {
        printf("\nStack is Empty ... Can't perform pop operation!! ");

    }
    else
    {
        int value = s->arr[s->top];
        s->top--;
        return value;
    }
}
int peek(int pos)
{
    if(isEmpty() == -1)
    {
        printf("\nStack is Empty ... Can't perform peek operation!! ");

    }
    else{
       
        return s->arr[s->top-pos+1];
    }
}
void display_stack()
{
    printf("\nStack Data is:\n\n");
    
    int i = 0;
    while(i <= s->top)
    {
        printf("%d ",s->arr[i]);
        i++;
    }

}
int StackBottom()
{
    return s->arr[0];
}

int StackTop()
{
    return s->arr[s->top];
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
        printf("\n1.Initialize stack (create stack)\n2.isFull\n3.isEmpty\n4.push\n5.pop\n6.peek\n7.display stack\n8.Stacktop \n 9.stackBottom\n10ed  3.exit!!\n\nEnter the choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
                create_stack();
                break;
        case 2:
                 res = isFull();
                 if(res ==-1)
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
                if(res == -1)
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
                 top_Value = peek(pos);
                 printf("\nAt position %d element is %d",pos,top_Value);
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