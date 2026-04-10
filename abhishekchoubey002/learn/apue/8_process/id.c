#include <stdio.h>
#include "process.h"
int a;
static void child(void)
{
	int i = 0;
	while((i++)<10) {
		sleep(2);
		printf("Child is running %d\n", a++);
	}
}

static void parent(void)
{
	a = 10;
	printf("Parent is running, %d", a);
	sleep(10);
}

int main()
{
	pid_t pid = fork();
	if(!pid) 
		child();
	else
		parent();	
	printf("returning\n");
	return 0;
}
