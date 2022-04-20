#include"../include/phone.h"
#include<stdio.h>

int init(PHONE **head)
{
    PHONE *newnode = (PHONE *)malloc(sizeof(PHONE));
    if(NULL == newnode)
    {
		return -1;
    }
    //newnode->value = 0;
    newnode->next = NULL;
    *head = newnode;
    return 0;
}

