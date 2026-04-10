#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int i;
	for(i=0;i<100;i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return 0;
}
