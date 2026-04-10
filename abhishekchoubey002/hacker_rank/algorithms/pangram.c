/* Given a sentence tell its a pangram(contains all the letters from a-z) or not ? */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static void pangram_or_not(const char* str)
{

}

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	int max_len = 1000;
	const  char *str = malloc(1024);
	if(!str)
		return 0;
	pangram_or_not(str);
	return 0;
}

