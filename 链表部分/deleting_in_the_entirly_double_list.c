//
// Created by 陶源 on 24-11-27.
//
#include <stdio.h>
#include <stdlib.h>
struct  node{
    struct node* before;
    int data;
    struct node* after;
};
struct node* add_to_empty(struct node* head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->after=NULL;
    temp->before=NULL;
    head=temp;
    return head;
}
struct node* delete_the_first_node(struct node *head)
{
  struct node *temp=head;
    head=temp->after;
    head->before=NULL;
    free(temp);
    temp=NULL;
    return head;
}
struct node* delete_the_last_node(struct node *head)
{
    struct node *pre=head;
    struct node *now=head;
    while (now->after!=NULL)
    {
        pre=now;
        now=now->after;
    }
    pre->after=NULL;
    free(now);
    now=NULL;
    return head;
}
struct node* delete_the_intermedia_node(struct node *head)
{
    int del_num;
    printf("which point of num you'd del");
    scanf("%d",&del_num);

    struct node *pre=head;
    struct node *middle=head;
    struct node *next=head;
    // while (del_num>1)
    {
    pre=middle;
        middle=middle->after;
        next=middle->after;
        del_num--;
    }
    //
    //another way


    // while (del_num>1)
    // {
    //     middle=middle->after;
    //     del_num--;
    // }
    //   next=middle->after;
    // pre=middle->before;



    pre->after=next;
    next->before=pre;
    free(middle);
    middle=NULL;
    return head;
}
struct node*  insert_at_ending(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *find_positon=head;
    temp->data=data;
    temp->after=NULL;
    temp->before=NULL;
    if (head == NULL) {
        head = temp;
        return head;
    }
    while (find_positon->after!=NULL)
    {
        find_positon=find_positon->after;
    }
    find_positon->after=temp;
    temp->before=find_positon;
    return head;
}
int main()
{
   struct node *head=(struct node*)malloc(sizeof(struct node));
    head=add_to_empty(head,66);
head=insert_at_ending(head,88);
    head=insert_at_ending(head,22);
    head=insert_at_ending(head,33);
    // head=delete_the_first_node(head);
    // head=delete_the_last_node(head);
    head=delete_the_intermedia_node(head);
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->after;
    }
}