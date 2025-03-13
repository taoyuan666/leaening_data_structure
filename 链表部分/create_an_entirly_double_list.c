//
// Created by 陶源 on 24-11-26.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//
// Created by 陶源 on 24-11-26.
struct  node{
    struct node* before;
    int data;
    struct node* after;
};
struct node* create_a_list(struct node *head);

struct node* add_to_empty(struct node* head,int data);

struct node*  insert_at_ending(struct node *head,int data);



int main()
{
   struct node *head=(struct node*)malloc(sizeof(struct node));
head=create_a_list(head);
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->after;
    }
}
struct node* create_a_list(struct node *head)
{
    int node_number;
    int data;
    printf("press how mang nodes do you want to make");
    scanf("%d",&node_number);
    if (node_number==0)
    {
       return head;
    }
    else if (node_number>=1)
    {
        printf("enter the first data");
        scanf("%d",&data);
        head=add_to_empty(head,data);
        for (int i = 1; i < node_number;++i)
        {
            printf("enter the data of node %d",(i+1));
            scanf("%d",&data);
            head=insert_at_ending(head,data);
        }
    }
    return head;

}
struct node* add_to_empty(struct node* head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->after=NULL;
    temp->before=NULL;
    head=temp;
    return head;
}
struct node*  insert_at_ending(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *find_positon=head;
    temp->data=data;
    temp->after=NULL;
    temp->before=NULL;
    if (head == NULL) {
        head = temp;
        return head;
    }
    while (find_positon->after!=NULL)
    {
        find_positon=find_positon->after;
    }
    find_positon->after=temp;
    temp->before=find_positon;

    return head;
}