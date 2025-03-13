#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//
// Created by 陶源 on 24-11-28.
//
struct node
{
    int data;
    struct node *next;
};
struct node* add_at_tmple(struct node *head,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=temp;
    head=temp;
    return head;
}
struct node* add_at_begin(struct node *head,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *tempp=head;
    temp->data=n;
    temp->next=head;
    while (tempp->next!=head)
    {
        tempp=tempp->next;
    }
    tempp->next=temp;
    head=temp;
    return head;
}
struct node* add_at_end(struct node *head,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *tempp=head;
    temp->data=n;
    while (tempp->next!=head)
    {
        tempp=tempp->next;
    }
    tempp->next=temp;
    temp->next=head;
    return head;
}
struct node* creat_list(struct node *head)
{
    int node_num;
   printf("how many nodes do you need");
    scanf("%d",&node_num);
    int n;
    printf("press the first num");
    scanf("%d",&n);

    head=add_at_tmple(head,n);
    if (node_num-1==0)
    {
        return head;
    }
    else
    {
        for (int i = 1; i < node_num; ++i)
        {
            printf("press the %d num",i+1);
            scanf("%d",&n);
            head=add_at_end(head,n);
        }
    }
    return head;
}
struct node* del_the_end(struct node *head)
{
    struct node *tempp=head;
    struct node *temp=NULL;
    while (tempp->next!=head)
    {
        temp=tempp;
        tempp=tempp->next;
    }
   temp->next=head;
    free(tempp);
    tempp=NULL;
    return head;
}
struct node* del_the_first(struct node *head)
{
    struct node *tempp=head;
    while (tempp->next!=head)
    {
        tempp=tempp->next;
    }
    tempp->next=head->next;
    head=head->next;
    return head;
}
struct node* del_the_intermediate(struct node *head,int position)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *tempp=head;
    while (position!=1)
    {
        temp=tempp;
        tempp=tempp->next;
        position--;
    }
    temp->next=tempp->next;
    free(tempp);
    return head;
}
struct node* insert_between_node(struct node *head,int n,int position)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *tempp=head;
    struct node *insert=(struct node*)malloc(sizeof(struct node));
    insert->data=n;
    temp->data=n;
  while (position!=1)
    {
      temp=tempp;
        tempp=tempp->next;
      position--;
    }
   temp->next=insert;
    insert->next=tempp;
    return head;
}
void search(struct node *head)
{
    int search;
    bool a=false;
    printf("press your search nun");
    scanf("%d",&search);
    struct node *temp=head;
    int position=0;
    while (temp->next!=head)
    {
        if (temp->data==search)
        {
            printf("posion is %d",position);
            a=true;
        }
        temp=temp->next;
        position++;
    }
    if (a!=true)
    {
        printf("don't have this num");
    }
}
int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    // head=add_at_tmple(head,21);
    // head=add_at_begin(head,22);
    // head=add_at_begin(head,23);
    // head=add_at_end(head,20);
    // head=insert_between_node(head,10,6);
    head=creat_list(head);
    // head=del_the_end(head);
    // head=del_the_first(head);
    // head=del_the_intermediate(head,5);

    struct node *temp=head;
 do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while (temp!=head);
    search(head);
}
//把head、换成tail时间复杂度更小
//1
//2
//3
//4
//5
//6