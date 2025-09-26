#include<stdio.h>
#define MAX 10

struct twostack
{
    int top1;
    int top2;
    int arr[MAX];
};

void init(struct twostack *ts)
{
    ts->top1=-1;
    ts->top2=MAX;
}

void push1(struct twostack *ts,int val)
{
    if(ts->top1 < ts->top2-1)
    {
        ts->top1++;
        ts->arr[ts->top1]=val;
    }
    else
    {
        printf("stack overflow in stack1\n");
    }
}

void push2(struct twostack *ts,int val)
{
    if(ts->top1 < ts->top2-1)
    {
        ts->top2--;
        ts->arr[ts->top2]=val;
    }
    else
    {
        printf("stack overflow in stack2\n");
    }
}

int pop1(struct twostack *ts)
{
    if(ts->top1 >= 0)
    {
        int val=ts->arr[ts->top1];
        ts->top1--;
        return val;
    }
}

int pop2(struct twostack *ts)
{
    if(ts->top2 < MAX)
    {
        int val=ts->arr[ts->top2];
        ts->top2++;
        return val;
    }
}

int main()
{
    struct twostack ts;
    init(&ts);

    push1(&ts,10);
    push1(&ts,20);
    push2(&ts,30);
    push2(&ts,40);

    printf("poped element from stack1: %d\n",pop1(&ts));
    printf("poped element from stack2: %d\n",pop2(&ts));

    return 0;
}