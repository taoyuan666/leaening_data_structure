#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//
// Created by 陶源 on 2024/11/28.
//
struct node
{
    float corff;
    int expo;
    struct node *next;
};
struct node* creat_a_link(struct node *head);
void add_a_node(struct node *head,float corff,int expo);
void calculate(struct node *head,int x);
void free_list(struct node *head);
int main()
{
    struct node *head=malloc(sizeof(struct node));
head->next=NULL;
    creat_a_link(head);


    calculate(head,4);

    free_list(head);

    return 0;
}
struct node* creat_a_link(struct node *head)
{
    struct node *temp=head;
    int node_num;
    printf("how many nodes does the polynomial have?");
    scanf("%d",&node_num);
    if (node_num>=1)
    {
        for (int i = 0; i < node_num; ++i)
        {
       printf("press  corff(xishu) and expo(mici) of node %d",i+1);
            int expo;
            float corff;
            scanf("%f %d",&corff,&expo);
      add_a_node(head,corff,expo);
        }
    }
    return head;
}
void add_a_node(struct node *head,float corff,int expo)
{

    struct node *data=malloc(sizeof(struct node));
    data->corff=corff;
    data->expo=expo;
    data->next=NULL;

   struct node *temp=head;
      while (temp->next!=NULL)
      {
          temp=temp->next;
      }
      temp->next=data;

    printf("adding finished!");
    printf("\n");

}
void calculate(struct node *head,int x)
{
float sum=0;
    struct node *temp = head->next;
    while (temp != NULL) {
        sum += temp->corff * pow(x, temp->expo);
        temp = temp->next;
    }
    printf("%.2f",sum);
}
void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
//whrer's the error at first time.in the function
// add_a_node
// struct node *temp=head;
// while (temp->next!=NULL)//only considering the second node is't empty
                     //       but my primary idea is judle whether there has the first node
                      //so i ignored it's value is what
// ///////////{    struct node *head=malloc(sizeof(struct node));
//                         head->next = NULL;(i forgot)
                          // promise to set the function of free!
//     temp=temp->next;
// }
// temp->next=data;
