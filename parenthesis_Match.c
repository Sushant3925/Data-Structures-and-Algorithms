#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};
struct stack *s;

int isFull()
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    else
    {
       
        return 0;
    }
}

int isEmpty()
{
    if(s->top == -1)
    {
        
        return 1;
    }
    else
    {
        
        return 0;
    }
}
void push(char value)
{
    
    
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

char pop()
{

    if(isEmpty() == -1)
    {
        printf("\nStack is Empty ... Can't perform pop operation!! ");

    }
    else
    {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}
int parenthesis_match(char *exp)
{
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push('(');
        }
        else if (exp[i] ==')')
        {
            if(isEmpty())
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
        
    }
    if(isEmpty())
    {
        return 1;

    }
    else
    {
        return 0;
    }
    
}
int main()
{
        char exp[10];
        printf("Enter the expression: ");
        scanf("%s",&exp);

        printf("%s",exp); 

        int res = parenthesis_match(exp);
        if(res == 1)
        {
            printf("\nThis is BALANCED PARENTHESIS EXPRESSION .");
        }
        else
        {
          printf("\nThis is NOT BALANCED PARENTHESIS EXPRESSION !!.");  
        }
}