#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
//
// Created by 陶源 on 2024/12/4.
//
struct node
{
    int data;
    struct node *link;
}*top=NULL;
void peek()
{
    printf("%d",top->data);
}
void pop()
{
   struct node* temp;;
    temp=top->link;
    free(top);
    top=NULL;
    top=temp;
}

void push(int data){
struct node* newnode=malloc(sizeof(newnode));
    newnode->link=NULL;
    newnode->data=data;
    newnode->link=top;
    top=newnode;
}
void print()
{
    struct node* temp;

    temp=top;
    while (temp)
    {
        printf("%d",temp->data);
        temp=temp->link;
    }
}
int main()
{
    int choice,data;
    while (1)
    {
        printf("1 push");
        printf("2 print");
        printf("3 pop");
        printf("3 peek");
        printf("5 quit");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("press num");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            print();
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(1);
        default:
            printf("reeor");
        }
        printf("");

    }
}