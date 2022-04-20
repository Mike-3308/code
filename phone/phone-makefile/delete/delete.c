#include"../include/phone.h"

int delete(PHONE *head)
{
    PHONE *p;
    p = head;
    char name[20];
    int count = 0;
    printf("please input your want delete one name:\n");
    scanf("%s",name);

    while(head->next != NULL)
    {
		if(strcmp(head->next->name,name) == 0)
		{
		    count++;
		   PHONE *ptr = head->next;
		    head->next = ptr->next;
		    free(ptr);
		}
    }
    if(count == 0)
    {
		printf("No this one name!\n");
		return -1;
    }
    else
    {
		printf("\33[0;32m  delete is ok!\33[0m\n");
    }

    head = p;
    printf("\n");
    return 0;
    
}

