#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static int factorial(int num) {
	if(num==1)
		return num;
	else
		return num * factorial(num-1);
}

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int num, fact;
	
	scanf("%d", &num);
	if(num <2 || num >12)	/* Constraint check */
		return 0;
	fact = factorial(num);
	printf("%d\n", fact);
	return 0;
}
