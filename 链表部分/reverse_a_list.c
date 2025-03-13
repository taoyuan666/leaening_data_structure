//
// Created by 陶源 on 24-11-24.
//
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct link {
    int data;
    struct link *next;
};
struct link* reverse(struct link *head)
{
    struct link *temp=NULL;
    struct link *temp2=NULL;
    while (head!=NULL)
    {
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;
    return head;
}
void add_at_end(struct link *head,int a){
    struct link *tool=head;
    struct link *temp=(struct link*)malloc(sizeof(struct link));
    temp->data=a;
    temp->next=NULL;
    while (tool->next!=NULL) {
        tool=tool->next;
    }
    tool->next=temp;
}
int main(){
    struct link *head=(struct link*)malloc(sizeof(struct link));
    head->data=1;
    head->next=NULL;
    add_at_end(head,2);
    add_at_end(head,4);
    add_at_end(head,3);
    head=reverse(head);
    if(head!=0) {
        struct link *str=head;
        while (str->next!=NULL) {
            printf("%d",str->data);
            str=str->next;
        }
        printf("%d",str->data);
    }
}

