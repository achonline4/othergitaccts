#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "stack.h"
/* Variables to be used in this program */
struct program {
	int argc;
	char** argv;
	uint8_t ds;
	void (*fn)(void*);
}__attribute__((aligned));

int main(int argc, char** argv)
{
	struct program prog;
	struct stack* stk = NULL;

	prog.argc = argc;
	prog.argv = argv;
	prog.ds = 1;
	prog.fn = stack;
	prog.fn(stk);
	return 0;
}
