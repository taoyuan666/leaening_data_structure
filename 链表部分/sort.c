//
// Created by 陶源 on 2024/11/28.
//
//
// Created by 陶源 on 24-11-22.
//
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};

void add_at_end(struct link *head,int a) {
    struct link *tool=head;
    struct link *temp=(struct link*)malloc(sizeof( struct link));
    temp->data=a;
    temp->next=NULL;
    while (tool->next!=NULL) {
        tool=tool->next;
    }
    tool->next=temp;
}
struct link* insert(struct link *head,int a)
{
        struct link *ptr2=head;
        struct link *ptr=NULL;
    struct link *data=malloc(sizeof( struct link));
    data->data=a;
        if (head->data>a)
        {
            data->next=head;
            head=data;
            return head;
        }
    ptr=ptr2;
    ptr2=ptr2->next;
    while (ptr2->data<a)
    {
        ptr=ptr2;
        ptr2=ptr2->next;
        if (ptr2==NULL)
        {
            ptr->next=data;
            return head;
        }
    }
    ptr->next=data;
    data->next=ptr2;
    return head;
}
int main(){
    struct link *head=malloc(sizeof(struct link));
    head->data=2;
    head->next=NULL;
    add_at_end(head,3);
    add_at_end(head,5);
    add_at_end(head,7);
    add_at_end(head,9);
    add_at_end(head,11);
    add_at_end(head,13);
    add_at_end(head,15);
    head=insert(head,20);
    head=insert(head,1);
    struct link *str=head;
    while (str->next!=NULL) {
        printf("%d",str->data);
        str=str->next;
    }
    printf("%d",str->data);
}