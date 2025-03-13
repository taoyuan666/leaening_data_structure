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
struct node* insert_at_begining(struct node* head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->after=NULL;
    temp->before=NULL;
    if (head != NULL) {
        head->before = temp;
    }
    temp->after=head;
    head->before=temp;
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
struct node*  insert_at_certain_position(struct node *head,int data,int position)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *before=NULL;
    struct node *after=NULL;
    temp->after=NULL;
    temp->before=NULL;
    temp->data=data;
    after=head;

    while (position!=0)
    {
        before=after;
        after=after->after;
        position=position-1;
    }
    before->after=temp;
    temp->after=after;
    temp->before=before;
    after->before=temp;
    after->after=NULL;
    return head;
}
int main()
{
   struct node *head=(struct node*)malloc(sizeof(struct node));
    head=add_to_empty(head,66);
    head=insert_at_begining(head,55);
head=insert_at_ending(head,77);
    head=insert_at_certain_position(head,22,2);
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->after;
    }

}