/* Accessing enviroment variables of a program without passing the argv
 * pointer */
#include <stdio.h>
extern char** environ;
static void abc(void)
{
	int i;
	for(i=0; environ[i]!=NULL; i++)
		printf("%s\n", environ[i]);
}

int main(int argc, char** argv)
{
	abc();
	return 0;
}
