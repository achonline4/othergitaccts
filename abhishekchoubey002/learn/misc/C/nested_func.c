/* Check if nested functions are supported. */
#include <stdio.h>
void world(void)
{
	printf("world\n");
	void hello()
	{
		printf("hello\n");
	}
	hello();
}
int main(void)
{
	void hello()
	{
		printf("hello\n");
	}
	printf("main\n");
	hello();
	world();
	return 0;
}
