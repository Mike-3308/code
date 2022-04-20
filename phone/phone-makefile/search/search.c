#include"../include/phone.h"
int search(PHONE *head)
{
    PHONE *p;
    p = head;
    int count = 0;
    char name[30];
    printf("please input you want search name:\n ");
    scanf("%s",name);
    while(head->next != NULL)
    {
	if(strcmp(head->next->name,name) == 0)
	{
	    count++;
	    show_item(head);
	}
	head = head->next;
    }
    if(count == 0)
    {
		printf("No search this people!\n");
		printf("Search error!\n");
    }
    printf("\n");
    head = p;

}

