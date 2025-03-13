#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};
 struct link* add_at_least(struct link *ptr,int a){
    struct link *temp;
    temp=(struct link*)malloc(sizeof(struct link));
    temp->data=a;
    temp->next=NULL;
    while (ptr->next!=NULL) {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return ptr;
}
int main() {
    struct link *head=(struct link*)malloc(sizeof(struct link));
    head->data=2;
    head->next=NULL;
    struct link *ptr=head;
    ptr=add_at_least(ptr,1);
    ptr=head;
    while (ptr!=NULL) {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}//
// Created by 陶源 on 24-11-22.
//
