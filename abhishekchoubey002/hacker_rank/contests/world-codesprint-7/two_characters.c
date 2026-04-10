#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int constraint_check(char* s, int slen)
{
	int i;
	if(!s || (slen <=0))
		return 1;
	/* Check that all the chars are small case letters */
	for(i=0;s[i]!='\0'; i++)
		if((s[i]>='a') && (s[i]<='z'))
			return 1;
	/* Check for string length */
	if(slen < 1 || slen > 1000)
		return 1;
	if(strlen(s) > slen)
		return 1;
	return 0;
}

int main(int argc, char* argv[])
{
	char tmp[1024];
	char *t;
	int slen = 0;
	char* s = (char *)malloc(512000 * sizeof(char));
	
	scanf("%d",&slen);
	memset(s, '\0', 512000);
	scanf("%s",s);
	
	printf("s = %s\n", s);
	if(constraint_check(s, slen))
		return 1;
	return 0;
}
