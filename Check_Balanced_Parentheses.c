#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isempty(struct stack*sp)
{
    if(sp->top==-1)
    {
        return 1;
    }
    return 0;
}

int isfull(struct stack*sp)
{
    if(sp->top==sp->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp,char ch)
{
    if(isfull(sp))
    {
        printf("overflow!!\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top]=ch;
    }
}

char pop(struct stack *sp)
{
    if(isempty(sp))
    {
        printf("underflow!!\n");
        return -1;
    }
    else
    {
        char ch=sp->arr[sp->top];
        sp->top--;
        return ch;
    }
}

int match(char a,char b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    else if(a == '{' && b == '}')
    {
        return 1;
    }
    else if(a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

char stacktop(struct stack *sp)
{
    if(isempty(sp))
    {
        return -1;
    }
    return sp->arr[sp->top]; 
}

int parenthesismatch(char *exp)
{
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    for(int i=0;exp[i] != '\0';i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] =='[')
        {
            push(sp,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] ==']')
        {
            if(isempty(sp))
            {
                return 0;
            }
            else
            {
                char poped_ch=pop(sp);
                if(!match(poped_ch,exp[i]))
                {
                    return 0;
                }
            }
        }
    }
    if(isempty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp="[4-6]((8){(9-8)})";
    if(parenthesismatch(exp))
    {
        printf("Balanced parenthesis!!\n");
    }
    else
    {
        printf("Not balanced parenthesis!!\n");
    }
    return 0;
}