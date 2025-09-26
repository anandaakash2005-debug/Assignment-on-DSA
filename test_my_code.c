#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

void linkedlisttraversal(struct Node*ptr)
{
    while(ptr != NULL)
    {
        printf("Elements:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node*insertAtfirst(struct Node*head,int val)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=val;
    ptr->next=head;
    return ptr;
}

struct Node*insertAtindex(struct Node*head,int index,int val)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    int i=0;
    while(i != index-1)
    {
        p = p ->next;
        i++;
    }
    ptr->data=val;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct Node*insertAtend(struct Node*head,int val)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    while (p->next != NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=val;
    return head;
}

struct Node*insertAtnode(struct Node*head,struct Node*prev,int val)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=val;
    ptr->next=prev->next;
    prev->next=ptr;
    return head;
}

struct Node*deleteAtfirst(struct Node*head)
{
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node*deleteAtindex(struct Node*head,int index)
{
    struct Node *p=head;
    struct Node *ptr=p->next;
    int i=0;
    while(i != index-1)
    {
        p=p->next;
        ptr=ptr->next;
        i++;
    }
    p->next=ptr->next;
    free(ptr);
    return head;
}

struct Node*deleteAtend(struct Node*head)
{
    struct Node*p=head;
    struct Node*ptr=p->next;
    while(ptr->next!= NULL)
    {
        p=p->next;
        ptr=ptr->next;
    }
    p->next=NULL;
    free(ptr);
    return head;
}

struct Node*deleteAtNode(struct Node *head,struct Node *prev)
{
    struct Node*ptr=prev->next;
    ptr->next=prev->next;
    free(ptr);
    return head;
}

int main()
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *last=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=15;
    third->next=last;

    last->data=19;
    last->next=NULL;

    //head=insertAtfirst(head,3);
    //head=insertAtindex(head,2,13);
    //head=insertAtend(head,23);
    //head=insertAtnode(head,third,17);
    //head=deleteAtfirst(head);
    //head=deleteAtindex(head,2);
    //head=deleteAtend(head);
    head=deleteAtNode(head,second);

    linkedlisttraversal(head);

    return 0;
} 