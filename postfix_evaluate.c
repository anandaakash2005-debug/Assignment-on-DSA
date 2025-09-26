#include<stdio.h>
#include<ctype.h>
#include<string.h>

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

int evaluatepostfix(char *exp)
{
    struct stack s;
    s.top=-1;
    for(int i=0;exp[i] != '\0';i++)
    {
        if(isdigit(exp[i]))
        {
            push(&s,exp[i]-'0');
        }
        else
        {
            int val2=pop(&s);
            int val1=pop(&s);
            switch(exp[i])
            {
                case '+':push(&s,val1+val2);
                break;
                case '-':push(&s,val1-val2);
                break;
                case '*':push(&s,val1*val2);
                break;
                case '/':push(&s,val1/val2);
                break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    char exp[]="23*54*+9-";
    printf("postfix evaluation:%d\n",evaluatepostfix(exp));
    return 0;
}