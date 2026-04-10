/*
 * # File : bp.c
 * # Aim : To print bit pattern of a given integer using recursion
 */
#include <stdio.h>
#include <string.h>
char pattern[32];
char* ptr = &pattern[31];

static void bp(const int num)
{
	if((num==1) || (num ==0)) {
		sprintf(ptr++, "%d", num);
		return;
	}
	bp(num/2);
	sprintf(ptr++, "%d", num%2);
}

int main(int argc, char**argv)
{
	int num = (argc > 1) ? atoi(argv[1]) : 100;
	fprintf(stdout, "Printing bit pattern for %d\n", num);
	memset(pattern, '-', sizeof(pattern));
	bp(num);
	fprintf(stdout, "\npattern = %s\n", pattern);
	return 0;
}
