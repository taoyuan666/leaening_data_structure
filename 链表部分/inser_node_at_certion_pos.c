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
int add_at_certain_position(struct link *head,int position,int add_what) {
    struct link *ptr2=(struct link*)malloc(sizeof(struct link));
    struct link *ptr=head;
    ptr2->data=add_what;
    ptr2->next=NULL;
    int b=0;
    while (ptr->next!=NULL) {
        b=b+1;
        ptr=ptr->next;

    }
    ptr=head;
    if (position>b+2) {
        printf("i don't have to much node");
        return 0;
    }

   else if(position<=1) {
        printf("how do you want me to do that?");
        return 0;
    }
    position--;
 while (position!=1) {
     ptr=ptr->next;
     //move to appoint position
     position--;
 }
    ptr2->next=ptr->next;
    ptr->next=ptr2;

}
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

int main() {
    struct link *head=(struct link*)malloc(sizeof(struct link));
    head->data=1;
    head->next=NULL;
    add_at_end(head,2);
    add_at_end(head,3);
    add_at_certain_position( head,7,99 );
    struct link *str=head;
    while (str->next!=NULL) {
        printf("%d",str->data);
        str=str->next;
    }
    printf("%d",str->data);
}
