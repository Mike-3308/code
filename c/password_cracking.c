/************************************************************************************************************
 * 破解上述加密的关键在于利用攻破strcpy()函数的漏洞。
 * 所以用户在向“passwd”缓存输入随机密码的时候并没有提前检查“passwd”的容量是否足够。
 * 所以，如果用户输入一个足够造成缓存溢出并且重写“flag”变量默认值所存在位置的内存的
 * 长“密码”，即使这个密码无法通过验证，flag验证位也变成了非零，也就可以获得被保护的数据了。
 *
 * 虽然上面的密码并不正确，但我们仍然可以通过缓存溢出绕开密码安全保护。要避免这样的问题，
 * 建议使用 strncpy()函数。但一些编译器会在内部检测栈溢出的可能，所以这样往栈里存储变量很难出现栈溢出。
 * 比如gcc中就要使用编译命令‘-fno-stack-protector’来实现上述方案。
 ***********************************************************************************************************/


#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[])
{ 
	int flag = 0;     
	char passwd[10];     
	memset(passwd,0,sizeof(passwd));     
	strcpy(passwd, argv[1]);     
	if(0 == strcmp("LinuxGeek", passwd)) 
	{ 
		flag = 1; 
	}    
	
	if(flag)
	{
		printf("\n Password cracked \n");
	}
	else
	{
		printf("\n Incorrect passwd \n");
	}
	
	return 0; 
}
