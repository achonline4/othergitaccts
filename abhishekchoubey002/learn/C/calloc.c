#include <stdio.h>
#include <stdlib.h>
/* calloc always initialises the menory to 0 no matter what type of memory it allocates.*/
int main(void)
{
	char** ptr;
	int i;

	ptr = calloc(5, sizeof(char*));
	for(i=0; ptr[i]==NULL; i++);
	printf("i = %d\n", i);
	return 0;
}
