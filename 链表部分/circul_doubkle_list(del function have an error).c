#include <stdio.h>
#include <stdlib.h>
//
// Created by 陶源 on 24-11-28.
//
struct node
{
    struct node *before;
    int data;
    struct node *after;
};
struct node* add_to_empty(struct node* tail,int data)
{
    tail->data=data;
    tail->after=tail;
    tail->before=tail;
    return tail;
}
struct node* insert_at_begining(struct node* tail,int data)
{
    struct node *temp=malloc(sizeof( struct node));
    struct node *head=tail->after;
    temp->data=data;
   temp->before=tail;
    temp->after=head;
    head->before=temp;
    tail->after=temp;
    return tail;
}
struct node* insert_at_ending(struct node *tail,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    struct node *head=tail->after;
    temp->data=data;
    tail->after=temp;
    temp->after=head;
    head->before=temp;
    tail->after=temp;
    tail=temp;
    return tail;
}
struct node* insert_at_certain_position(struct node *tail,int data,int position)
{
    struct node *temp=malloc(sizeof( struct node));
    struct node *before=tail;
    struct node *afterr=tail->after;;
    temp->data=data;
    while (position!=1)
    {
        before=afterr;
        afterr=afterr->after;
        position--;
    }
    before->after=temp;
    temp->after=afterr;
    afterr->before=temp;
    temp->before=before;

return tail;
}
struct node* del_last(struct node* tail)
{
    struct node* temp;
    if (tail == NULL)
    {
        return tail;
    }
    if (temp == tail)
    {
        free (tail);
        tail = NULL;
        return tail;
    }
    temp = tail->before;
    temp->after = tail->after;
    tail->after->before= temp;
    free (tail);
    tail = temp;
    return tail;
}
struct node* del_first(struct node* tail)
{
struct node *head = tail->after;


    tail->after=head->after;
    head->after->before=tail;
    free(head);
    return tail;
}
struct node* del_at_certain_positio(struct node* tail,int position)
{
    {
        struct node *before=tail;
        struct node *afterr=tail->after;;
        while (position!=1)
        {
            before=afterr;
            afterr=afterr->after;
            position--;
        }
 before->after=afterr->after;
        afterr->after->before=before;
        free(afterr);
        return tail;
    }
}
int main()
{
struct node *tail=malloc(sizeof(struct node));
   tail =add_to_empty(tail,7);
    tail=insert_at_begining(tail,6);
    tail=insert_at_ending(tail,8);
    tail=insert_at_ending(tail,8);
    tail=insert_at_certain_position(tail,5,3);
    tail=del_first(tail);
     // tail=del_last(tail);
    tail=del_at_certain_positio(tail,3);
    {
        struct node *temp=tail->after;
        do{
            printf("%d",temp->data);
            temp=temp->after;
        } while (temp!=tail->after);
    }
return 0;
}
