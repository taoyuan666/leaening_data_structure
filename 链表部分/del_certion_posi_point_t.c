//
// Created by 陶源 on 24-11-23.
//
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};
void delect_at_certain_position(struct link *head,int position) {
    struct link *ptr2=head;
    struct link *ptr=head;
    int pos=position;
    pos--;
    while (pos!=1) {
        ptr=ptr->next;
        pos--;
    }
    pos=position;
    while (pos!=1) {
        ptr2=ptr2->next;
        pos--;
    }
    ptr->next=ptr2->next;
    free(ptr2);
    ptr2=NULL;
}
void delect_at_certain_position_better(struct link **head,int position) {
    struct link *current=*head;
    struct link *pervious=*head;
    if (*head==NULL) {
        printf("there is nothing");
    }
    else if(position==1) {
        *head=current->next;;
        free(current);
        current=NULL;
    }
    else{
        while (position!=1) {
            pervious=current;
            //a=1;// b=2;// a=b   a=2;// b=3
            current=current->next;
            position--;
        }
        pervious->next=current->next;
        free(current);
        current=NULL;
    }
}
void add_at_end(struct link *head,int a){
    struct link *tool=head;
    struct link *temp=(struct link*)malloc(sizeof( struct link));
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
    add_at_end(head,3);
    add_at_end(head,5);
    // delect_at_certain_position(head,3);
    delect_at_certain_position_better(&head,4);
    struct link *str=head;
    while (str->next!=NULL) {
        printf("%d",str->data);
        str=str->next;
    }
    printf("%d",str->data);
}