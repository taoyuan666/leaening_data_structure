#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct cyber_pet {
//     char *name;
//     int age;
//     char *why_fimous;
//     struct cyber_pet *next;
// };
// int main() {
//     struct cyber_pet no1;
//     struct cyber_pet no2;
//     no1.age=1376666;
//     no1.name="dingzhen";
//     no1.why_fimous="wo ce ni men ma";
//     no1.next=NULL;
//     no2.age=2233;
//     no2.name="hetongxue";
//     no2.why_fimous="wo chao  ni de ma";
//     no2.next=NULL;
//     no1.next=&no2;
//
// printf("%d%s%s",no1.next->age,no1.next->name,no1.next->why_fimous);
//
//
// }
//
// Created by 陶源 on 24-11-22.
//





struct linked_list {
    int data;
    struct linked_list *link;
};
int main(){
struct linked_list *head;
    head=(struct linked_list*)malloc(sizeof(struct linked_list));
    head->data=1;
    head->link=NULL;
struct linked_list *current;
    current=(struct linked_list*)malloc(sizeof(struct linked_list));
    current->data=2;
    head->link=current;
    current=(struct linked_list*)malloc(sizeof(struct linked_list));
    current->data=3;
    head->link->link=current;

    printf("%d",head->data);
}
