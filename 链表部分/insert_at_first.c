#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};
struct link* add_at_first(struct link *head,int a){
    struct link *ptr;
    ptr=(struct link*)malloc(sizeof(struct link));
    ptr->data=a;
    ptr->next=NULL;
    ptr->next=head;
    head=ptr;
    // draw it.this means only move the tag

    return head;
}
int main() {
    struct link *head=(struct link*)malloc(sizeof(struct link));
    head->data=2;
    head->next=NULL;
    struct link *ptr=(struct link*)malloc(sizeof(struct link));
ptr->data=1;
    ptr->next=NULL;
    head->next=ptr;
    int dara=3;
    head=add_at_first(head,dara);
    ptr=head;
    while (ptr!=NULL) {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }

}