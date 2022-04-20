/************************************************************************************
 *因为main()方法的返回类型，这段代码的错误在大多数编译器里会被当作警告。
 *main()的返回类型应该是“int”而不是“void”，好多人都习惯写成void，
 *因为“int”返回类型会让程序返回状态值。这点非常重要，特别当程序是
 *作为依赖于程序成功运行的脚本的一部分运行时，所以强烈建议大家以后要写int。
 * **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char *ptr = (char*)malloc(10);
	if(NULL == ptr) 
	{
		printf("\n Malloc failed \n");
		return; 
	}
	else 
	{
		// Do some processing
		free(ptr); 
	}
	
	return;
}
