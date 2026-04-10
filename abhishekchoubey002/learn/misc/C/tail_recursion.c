/* tail_recursion 
 * Aim : to see if the number of stack frames in case of a tail recursive function increase or
 * remain the same.
 * Observsation : Without enabling optimizations the number of stack frames increase with each 
 * call to the function, with optimization -O3 #stack frames remains same .i.e. 1 */
#include <stdio.h>

static void tr(int num)
{
	if(num--)
		fprintf(stdout, "Hello \n");
	tr(num);
}

int main(void)
{
	tr(10);
	return 0;
}
