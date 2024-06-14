#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};
struct stack *s;

int isFull()
{
    if (s->top == s->size - 1)
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
    if (s->top == -1)
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

    if (isFull())
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

    if (isEmpty())
    {
        printf("\nStack is Empty ... Can't perform pop operation!! ");
        return 1;
    }
    else
    {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int precedance(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackTop()
{
    return s->arr[s->top];
}

char *infixToPostfix(char *infix)
{
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // To track the infix expression
    int j = 0; // To Fill the postfix Expression

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i]; // if infix element is not operator then fill in posfix
            j++;
            i++;
        }
        else
        {
            if (precedance(infix[i]) > precedance(StackTop()))
            {
                push(infix[i]);
                i++;
            }
            else
            {

                postfix[j] = pop();
                j++;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}
int main()
{
    char infix[10];
    printf("Enter the infix statement: ");
    scanf("%s", &infix);

    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}