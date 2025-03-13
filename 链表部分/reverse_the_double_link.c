#include <stdio.h>
#include <stdlib.h>
//
// Created by 陶源 on 24-11-26.
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
struct node* reverse(struct node *head)
{
    struct node *temp=NULL;
    struct node *current=head;
    while (current!=NULL)
    {
        temp=current->after;
        current->after=current->before;
        current->before=temp;
temp=current;
        current=current->before;
    }
    head=temp;

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

head=insert_at_ending(head,77);

    head=insert_at_ending(head,22);

    head=insert_at_ending(head,33);
head=reverse(head);
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->after;
    }

}
