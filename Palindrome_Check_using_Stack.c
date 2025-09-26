#include<stdio.h>
#include<string.h>

#define MAX 100

struct stack
{
    int top;
    char arr[MAX];
};

void push(struct stack *s,char ch)
{
    s->top++;
    s->arr[s->top]=ch;
}

char pop(struct stack *s)
{
    char ch=s->arr[s->top];
    s->top--;
    return ch;
}

int chkpalindrome(char *str)
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
        if(str[i] != pop(&s))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str1[]="madam";
    char str2[]="hallo";
    if(chkpalindrome(str1))
    {
        printf("%s is a palindrome\n",str1);
    }
    else
    {
        printf("%s is not a palindrome\n",str1);
    }
    if(chkpalindrome(str2))
    {
        printf("%s is a palindrome\n",str2);
    }
    else
    {
        printf("%s is not a palindrome\n",str2);
    }
    return 0;
}