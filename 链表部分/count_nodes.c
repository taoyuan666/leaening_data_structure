#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    int data;
    struct linked_list *link;
};

void count_of_node(struct linked_list *head) {
    int count = 1;
    if (head == NULL) {
        printf("kong");
        return;
    }
    struct linked_list *p = NULL;
    p = head;
    while (p != NULL) {
        count++;
        p = p->link;
    }
    printf("%d", count);
}

void print_of_node(struct linked_list *head) {
    if (head == NULL) {
        printf("kong");
        return;
    }
    struct linked_list *p = NULL;
    p = head;
    while (p != NULL) {
        printf("%d", p->data);
        p = p->link;
    }
}

void add_at_add(struct linked_list *head, int data) {
    struct linked_list *str, *temp;
    str = head;
    temp = (struct linked_list *) malloc(sizeof(struct linked_list));
    temp->data = data;
    temp->link = NULL;
    while (str->link != NULL) {
        str = str->link;
    }
    str->link = temp;
}

int main() {
    struct linked_list *head;
    head = (struct linked_list *) malloc(sizeof(struct linked_list));
    head->data = 3;
    head->link = NULL;
    add_at_add(head, 2);
    add_at_add(head, 5);
    add_at_add(head, 7);
    count_of_node(head);
    print_of_node(head);
    // Free the second node
    free(head);
} //
// Created by 陶源 on 24-11-22.
//
