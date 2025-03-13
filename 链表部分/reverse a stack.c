//
// Created by 陶源 on 2024/12/4.
//
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void peek(struct node *top);
void pop(struct node *top);
void push(int data,struct node *top);
void print(struct node *top);
void reverse(struct node *top);
int main()
{
   struct node *top=NULL;
    struct node *top2=NULL;
    struct node *top3=NULL;
    int choice,data;
    while (1)
    {
        printf("1 push");
        printf("2 print");
        printf("3 pop");
        printf("4 peek");

        printf("5 quit");
        printf("6 reverse");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("press num");
            scanf("%d",&data);
            push(data,top);
            break;
        case 2:
            print(top);
            break;
        case 3:
            pop(top);
            break;
        case 4:
            peek(top);
            break;
        case 5:
            exit(1);
        case 6:
            reverse(top);
        default:
            printf("reeor");
        }
        printf("");

    }
}

void peek( struct node *top)
{
    printf("%d",top->data);
}
void pop(struct node *top)
{
    struct node* temp;;
    temp=top->link;
    free(top);
    top=NULL;
    top=temp;
}
void push(int data, struct node *top){
    struct node* newnode=malloc(sizeof(newnode));
    newnode->link=NULL;
    newnode->data=data;
    newnode->link=top;
    top=newnode;
}
void print( struct node *top)
{
    struct node* temp;
    temp=top;
    while (temp)
    {
        printf("%d",temp->data);
        temp=temp->link;
    }
}
// void reverse(struct node *top)
// {
//    struct node *temp=top;
//     while (temp!=NULL)
//     {
//         push(peek(top),top2);
//     }
// }