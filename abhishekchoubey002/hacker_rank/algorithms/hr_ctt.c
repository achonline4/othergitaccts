/* Compare the triplets */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int constraint_check(int x, int y, int z) {
	if(x<1 || x > 100)
		return 1;
	if(y<1 || y>100)
		return 1;
	if(z<1 || z>100)
		return 1;
	return 0;
}

int main(){
	int a0; 
	int a1; 
	int a2; 
	scanf("%d %d %d",&a0,&a1,&a2);
	int b0; 
	int b1; 
	int b2; 
	int score_alice = 0;
	int score_bob = 0;
	scanf("%d %d %d",&b0,&b1,&b2);
	if(constraint_check(a0, a1, a2) ||
			constraint_check(b0, b1, b2))
		return 0;
	else {
		if(a0 > b0)
			score_alice++;
		else if(b0 > a0)
			score_bob++;
		if(a1 > b1)
			score_alice++;
		else if(b1 > a1)
			score_bob++;
		if(a2 > b2)
			score_alice++;
		else if(b2 > a2)
			score_bob++;
	}
	printf("%d %d\n", score_alice, score_bob);
	return 0;
}

