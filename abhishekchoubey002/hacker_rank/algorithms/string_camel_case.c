#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int word_count(const char* s)
{
	int i;
	int count = 1;
	int len = strlen(s);
	for(i=0; i< len; i++) 
		if((s[i] >= 'A') && (s[i]<='Z'))
			count++;
	return count;
}

int main(){
	char* s = (char *)malloc(10240 * sizeof(char));
	scanf("%s",s);
	printf("%s\n", s);
	printf("%d\n", word_count(s));
	return 0;
}
