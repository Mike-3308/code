#include"../include/phone.h"
#include<stdio.h>

PHONE *allfree(PHONE *head)
{
    while(head->next != NULL)
    {
		PHONE *ptr = head;
		head = head->next;
		free(ptr);
    }
    free(head);
    head = NULL;
    return head;
}

