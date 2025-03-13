#include <stdio.h>
#include <stdlib.h>
//
// Created by 陶源 on 24-11-23.
//
struct list {
    int data;
    struct list *next;
};
void del_the_whole(struct list **head) {
    struct list *curent=*head;
    while (curent->next!=NULL) {
        struct list* temp=curent;
        curent=curent->next;
        free(temp);
    }
 *head=NULL;
}
struct list* del_the_whole_normal(struct list *head){
struct list* temp=head;
    while (temp!=NULL) {
        temp=temp->next;
        free(head);
        head=temp;
    }
    return head;
}
struct list* best(struct list* head){

        while (head!=NULL) {
            struct list* aaa=head;
            head=head->next;
            free(aaa);
            aaa=NULL;

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
    //head=del_the_whole_normal(head);
// del_the_whole(&head);
   // head=best(head);
    if (head==NULL) {
        printf("cleaning!");
    }

}
