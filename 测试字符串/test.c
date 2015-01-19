#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	char buf[] = "hello";
	char buff[5] = { 'h', 'd', 'd' };
	buf[4] = 0;
	int a;
	a = buf[5];
	printf("%d\n", a);
	printf("%c\n", buf[5]);
	printf("%s\n", buff);

	system("pause");
}