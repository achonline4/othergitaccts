#include <stdio.h>
static void a()
{
	int b = 10;
	void* a = &b;
	printf("%d\n", *((int*)a));
	system("./a");
}
main(void)
{
	a();
}
