//
// Created by 陶源 on 24-11-22.
//
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};
struct list* del_first(struct list *head) {
    if (head==NULL) {
        printf("empty");
    }
    else {
        struct list *temp=head;
        head=head->next;
        free(temp);

    }
    return  head;
}
struct list* del_last_one_node(struct list *head) {
    if (head==NULL) {
        printf("empty");
        return 0;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        printf("only one");
        return 0;
        }
    else {
        struct list *temp1=head;
        struct list *temp2=head;
        while (temp1->next!=NULL) {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
        temp1=NULL;
    }

    return head;
    }
struct list* del_last_two_node(struct list *head) {
    if (head==NULL) {
        printf("empty");
        return 0;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        printf("only one");
        return 0;
    }
    else {
        struct list *temp1=head;

        while (temp1->next->next!=NULL) {

            temp1=temp1->next;
        }
        free(temp1->next);
     temp1->next=NULL;
    }

    return head;
}
void add_at_end(struct list *head,int a){
    struct list *tool=head;
    struct list *temp=(struct list*)malloc(sizeof( struct list));
    temp->data=a;
    temp->next=NULL;
    while (tool->next!=NULL) {
        tool=tool->next;
    }
    tool->next=temp;
}
int main(){
    struct list *head=(struct list*)malloc(sizeof(struct list));
    head->data=1;
    head->next=NULL;
    add_at_end(head,2);
    add_at_end(head,3);
    // head=del_first(head);
    head=del_last_one_node(head);
    head=del_last_two_node(head);
    if(head!=0) {
        struct list *str=head;
        while (str->next!=NULL) {
            printf("%d",str->data);
            str=str->next;
        }
        printf("%d",str->data);
    }
}

