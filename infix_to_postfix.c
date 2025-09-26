#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isempty(struct stack *sp)
{
    if(sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int isfull(struct stack *sp)
{
    if(sp->top == sp->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp,char ch)
{
    if(isfull(sp))
    {
        printf("stack overflow!!\n");
        return ;
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
        printf("stack underflow!!\n");
    }
    else
    {
        char ch=sp->arr[sp->top];
        sp->top--;
        return ch;
    }
}

char stktop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isoperator(char ch)
{
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

int pracedance(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    if(ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}

char *infixtopostfix(char *infix)
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=strlen(infix);
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size *sizeof(char));
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i] != '\0')
    {
        if((infix[i]>= 'A' && infix[i] <= 'Z') || (infix[i]>= 'a' && infix[i] <= 'z') || (infix[i]>= '0' && infix[i] <= '9'))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else if(infix[i] == '(')
        {
            push(sp,infix[i]);
            i++;
        }
        else if(infix[i] == ')')
        {
            while(!isempty(sp) && stktop(sp)!='(')
            {
                postfix[j]=pop(sp);
                j++;
            }
            pop(sp);
            i++;
        }
        else if(isoperator(infix[i]))
        {
            if(!isempty(sp) && pracedance(stktop(sp)) >= pracedance(infix[i]))
            {
                postfix[j]=pop(sp);
                j++;
            }
            else
            {
                push(sp,infix[i]);
                i++;
            }
        }
    }
    while(!isempty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="w/s+f/c*a+n";
    printf("infix to postfix conversion is:%s\n",infixtopostfix(infix));
    return 0;
}