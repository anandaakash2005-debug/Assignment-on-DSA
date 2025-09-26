#include<stdio.h>
#include<string.h>

#define MAX 100

struct stack
{
    int top;
    char arr[MAX];
};

void push(struct stack *sp,char ch)
{
    sp->top++;
    sp->arr[sp->top]=ch;
}

int pop(struct stack *sp)
{
    char ch=sp->arr[sp->top];
    sp->top--;
    return ch;
}

void reversestring(char *str)
{
    struct stack s;
    s.top=-1;
    int n=strlen(str);
    for(int i=0;i<n;i++)
    {
        push(&s,str[i]);
    }
    for(int i=0;i<n;i++)
    {
        str[i] = pop(&s);
    }
}

int main()
{
    char str[]="hello Akash";
    printf("original string is:%s\n",str);
    reversestring(str);
    printf("reversed string is:%s\n",str);
    return 0;
}