//
// Created by 陶源 on 2024/12/3.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 6
int stack_arr[MAX];
int first=-1;

int isfull()
{
    if (first==MAX-1)
    {
        printf("stack is full");
        return 1;
    }
    else
        return 0;
}
int isempty()
{
    if (first==-1)
    {
        return 1;
    }
    else
        return 0;
}
int peek()
{
    if (isempty())
    {
        printf("empty");
    }
    return stack_arr[0];
}
int pop(){
    int i,value;
    if (first==-1)
    {
        printf("empty");
        return 0;
    }
    else
    {
        value=stack_arr[0];
        //write it down ,or you will forget move one node


        for (i = 0; i <first; i++)
        {
            stack_arr[i]=stack_arr[i+1];
        }
        first=first-1;
        return value;
    }
}
void push(int data)
{
    if (isfull())
    {
      printf("full");
    }
    else
    {
        first=first+1;
        for (int i = first; i >0; i--)
        {
            stack_arr[i]=stack_arr[i-1];
        }
            stack_arr[0]=data;
    };
}
void print()
{
    if (first==-1)
    {
        printf("empty");
    }
    else
    {
        for (int i = 0; i <= first; i++)
        {
            printf("%d\n",stack_arr[i]);
        }
    }
}
int main()
{
     int value;
    push(10);
    push(20);
    push(30);
    push(40);
    printf("%d",peek());
  value=pop();
    printf("%d",value);
    print();
}