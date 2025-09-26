#include<stdio.h>
#include<string.h>
#include<ctype.h>

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

int prefixevaluate(char *exp)
{
    struct stack s;
    s.top=-1;
    int len=strlen(exp);
    for(int i=len-1;i>=0;i--)
    {
        if(exp[i] == ' ')
        continue;
        if(isdigit(exp[i]))
    {
        int val=0;
        int base=1;

        while(i>=0 && isdigit(exp[i]))
        {
            val=(exp[i]-'0')*base+val;
            base*=10;
            i--;
        }
        i++;
        push(&s,val);
    }
    else
    {
        int val1=pop(&s);
        int val2=pop(&s);
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
    char exp[]="- + * 2 3 * 5 4 9";
    printf("prefix evalution is:%d\n",prefixevaluate(exp));
    return 0;
}