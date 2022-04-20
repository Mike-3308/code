#include"../include/phone.h"
#include<stdio.h>

char password[20]="yikoupeng";

PHONE *phone_head;//链表头

int management(PHONE *head)
{
	int sel;
	int fg = 0;
	do{
		system("clear");

		sel = manage_menu();

		switch(sel)
		{
			case 1:
				create(head);
				getchar();
				getchar();				
				break;
			case 2:
				delete(head);
				getchar();
				getchar();
				break;
			case 3:
				search(head);
				getchar();
				getchar();
				break;
			case 4:
				display(head);

				break;
			case 0:
				printf("\t\t\tBye\n");
				allfree(head);
				getchar();
				getchar();
				fg = 1;
			default:
				break;
		}
		if(fg == 1)
		{
			return 1;
		}

	}while(1);
	return 0;
}

int main(int argc, char **argv)
{
	int ret;

	init(&phone_head);
	ret = login_menu();

	if (ret == 0)                        //密码正确，则给出提示
	{
		printf("\33[0;32m登录成功了！！你真帅！！！\33[0m\n");
		getchar();
		getchar();
		management(phone_head);
	}
	else if (ret == -1)                  //如果三次输出密码均错误，则给出提示，并返回-1
	{
		printf("\33[0;31m输入次数已经用尽，系统将自动退出！\33[0m\n");
		return(-1);
	}

}

