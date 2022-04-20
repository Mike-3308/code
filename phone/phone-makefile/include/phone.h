#ifndef _LIST_H
#define _LIST_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<assert.h>

typedef struct phone_st
{
    struct phone_st *next;
    int id;
    char  name[20];
    char phone_number[20];
    char home_address[30];
    char company_number[20];

}PHONE;

void show_item(PHONE *head)    ;
int init(PHONE **head);
int create(PHONE *head);
int delete(PHONE *head);
int display(PHONE *head);
int search(PHONE *head);
PHONE *allfree(PHONE *head);

#endif
