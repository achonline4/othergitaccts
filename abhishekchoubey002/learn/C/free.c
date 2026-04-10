#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char* ptr=1;
	if(ptr)
		free(ptr);
	return 0;
}
