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

int isoperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

char stacktop(struct stack*sp)
{
    if(isempty(sp))
    {
        return -1;
    }
    return sp->arr[sp->top];
}

int pracedance(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}

void reverse(char *exp)
{
    int n=strlen(exp);
    for(int i=0;i<n/2;i++)
    {
        char temp=exp[i];
        exp[i]=exp[n-i-1];
        exp[n-i-1]=temp;
    }
}

char*infixtopostfix(char *infix)
{
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=strlen(infix);
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char*postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i] != '\0')
    {
        if((infix[i]>='A' && infix[i]<='Z') || (infix[i]>='a' && infix[i]<='z') || (infix[i]>='0' && infix[i]<='9'))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else
        {
            if(pracedance(infix[i]) > pracedance(stacktop(sp)))
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
    while(!isempty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

char*infixtoprefix(char *infix)
{
    int n=strlen(infix);
    char *rev=(char*)malloc((n+1)*sizeof(char));
    strcpy(rev,infix);
    reverse(rev);
    char *postfix=infixtopostfix(rev);
    reverse(postfix);
    return postfix;
}

int main()
{
    char *infix="w/s+f/c*a+n";
    printf("prefix expression:%s\n",infixtoprefix(infix));
    return 0;
}