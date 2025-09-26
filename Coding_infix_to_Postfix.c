#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack*sp)
{
    return sp->arr[sp->top];
}

int isempty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack*sp,char val)
{
    if(isfull(sp))
    {
        printf("overflow!!\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=val;
    }
}

char pop(struct stack *sp)
{
    if(isempty(sp))
    {
        printf("underflow!!\n");
    }
    else
    {
        char val=sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

int precedance(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isoperater(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *infixtopostfix(char *infix)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char *postfix=(char *)malloc((strlen(infix)+1)* sizeof(char));
    int i=0;
    int j=0;
    while(infix[i] != '\0')
    {
        if(!isoperater(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedance(infix[i]) > precedance(stacktop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(! isempty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="x-y/z-k*d";
    printf("postfix is %s",infixtopostfix(infix));
    return 0;
}
