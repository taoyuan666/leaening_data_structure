
// Created by 陶源 on 2024/12/1.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top=-1;
int pop()
{
    int value;
    value=stack_arr[top];
    top=top-1;
    return value;
}
void push(int data)
{
    top=top+1;
    stack_arr[top]=data;
}
int isfull()
{
    if (top==MAX-1)
    {
        printf("stack is full");
        return 1;
    }
    return 0;
}
int isempty()
{
    if (top==-1)
    {
        printf("stack underflow");
        return 1;
    }
    return 0;
}
void print()
{
    if (isempty()) {
        printf("Stack is empty. Nothing to print.\n");
    } else {
        printf("Stack elements (from top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack_arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    int data,choice;
   while (1)
   {
       printf("press your operation\n");
       printf("1. push a num\n");
       printf("2. pop\n");
       printf("3. print the top element\n");
       printf("4. print all elements\n");
       printf("5. quit\n");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
           if (isfull()) {
               printf("Stack is full. Cannot push data.\n");
           } else {
               printf("Enter the number to push: ");
               scanf("%d", &data);
               push(data);
           }
           break;
       case 2:
           if (!isempty()) {
               printf("Popped element: %d\n", pop());
           }
           break;
       case 3:
           if (!isempty()) {
               printf("Top element: %d\n", stack_arr[top]);
           } else {
               printf("Stack is empty. No top element.\n");
           }
           break;
       case 4:
           if (!isempty())
           {
               print();
           }
           break;
       case 5:
           printf("Exiting program.\n");
           exit(0);
       default:
           printf("wrong choice");
       }
   }
}
