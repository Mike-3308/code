#include"../include/phone.h"
#include<stdio.h>

extern char password[20];

int login_menu()
{
	int i = 3;
	char name[32] = {0};
	char pass[32] = {0};
	
	printf("\033[0;96m+=================================================================+\033[0m\n");
	printf("\033[0;96m| 								  |\033[0m\n");
	printf("\033[0;96m| \t\t欢迎来到一口Linux的通讯录 			  |\033[0m\n");
	printf("\033[0;96m| 								  |\033[0m\n");
	printf("\033[0;96m| 			温馨提示：初始密码(yikoupeng)	          |\033[0m\n");
	printf("\033[0;96m| 			关注公众号：一口Linux	                  |\033[0m\n");	
	printf("\033[0;96m+=================================================================+\033[0m\n");

    while(i > 0)
    {
		printf("\033[0;96mplease input your password:\033[0m\n");
		scanf("%s",pass);
		if(strcmp(password,pass) == 0)
		{
		    return 0;
		}
		else
		{
		    i--;
		    printf("password error!,The remaining number of times is:%d\n",i);
		}
    }
    if(i == 0)
    {
		printf("over!");
		return -1;
    }

}

