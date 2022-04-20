/************************************************************************************
 *下面的程序会在用户输入’freeze’的时候出问题，而’zebra’则不会，为什么？
 *
 * 这里的问题在于，代码会（通过增加“ptr”）修改while循环里“ptr”存储的地址。
 * 当输入“zebra”时，while循环会在执行前被终止，因此传给free()的变量
 * 就是传给malloc()的地址。但在“freeze”时，“ptr”存储的地址
 * 会在while循环里被修改，因此导致传给free()的地址出错，
 * 也就导致了seg-fault或者崩溃。
 ***********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ 
	char *ptr = (char*)malloc(10);
	if(NULL == ptr) 
	{ 
		printf("\n Malloc failed \n"); 
		return -1; 
	} 
	else if(argc == 1) 
	{ 
		printf("\n Usage \n"); 
	} 
	else 
	{ 
		memset(ptr, 0, 10);
		strncpy(ptr, argv[1], 9);
		
		while(*ptr != 'z') 
		{ 
			if(*ptr == ' ') 
				break; 
			else 
				ptr++; 
		}
		
		if(*ptr == 'z') 
		{ 
			printf("\n String contains 'z'\n"); 
			// Do some more processing 
		}
		free(ptr);     
	} 
	return 0; 
}
