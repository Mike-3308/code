#include"../include/phone.h"
#include<stdio.h>



int manage_menu()
{
	int sel;
	int fg = 0;
	do{
		printf("\033[0;33m+***************************电话号码管理软件*********************+\033[0m\n");
		printf("\033[0;33m|\t\t\t1. 添加					 |\033[0m\n");
		printf("\033[0;33m|\t\t\t2. 删除					 |\033[0m\n");
		printf("\033[0;33m|\t\t\t3. 查找					 |\033[0m\n");
		printf("\033[0;33m|\t\t\t4. 显示所有记录				 |\033[0m\n");
		printf("\033[0;33m|\t\t\t0. 退出					 |\033[0m\n");
		printf("\033[0;33m+****************************************************************+\033[0m\n");

		printf("\033[0;33minput your choice#\033[0m");
		scanf("%d",&sel);
		if((sel<0) || (sel>4))
		{
			fflush(stdin);//清空输入缓冲区，放置多输入了信息
			
			system("clear");
			printf("\t\t\33[0;31m无效选项，请重新输入\33[0m\n");
			getchar();
			continue;
		}
		return sel;
	}while(1);

}
