#include<stdio.h>

#define MAX 100

struct stack
{
    int top;
    int arr[MAX];
};

void push(struct stack *s,int val)
{
    s->top++;
    s->arr[s->top]=val;
}

int pop(struct stack *s)
{
    int val=s->arr[s->top];
    s->top--;
    return val;
}

int peek(struct stack *s)
{
    return s->arr[s->top];
}

int isempty(struct stack *s)
{
    return s->top=-1;
}

void nextgraterelement(int *arr,int n)
{
    int arr[n];
    struct stack s;
    s.top=-1;

    for(int i=n-1;i>=0;i++)
    {
        while(!isempty(&s) && peek(&s) <= )
    }
}