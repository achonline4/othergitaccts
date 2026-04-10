#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static int push(struct stack* stk)
{
	if(!stk) 
		return NO_STACK_FOUND;
	return 0;
}

static void stack_op(struct stack* stk)
{	
	int choice;
	int done = 0;
	int ret;

	while(!done) {
		ret = INVALID_OP;
		fprintf(stdout, "\nPlease select an operation : \n"
		"1. Create a Stack\n"
		"2. Push\n"
		"3. Pop\n"
		"4. Pull\n"
		"5. Search\n"
		"6. Exit\n");
		scanf("%d", &choice);
		switch(choice) {
			case CREATE:
				break;
			case PUSH:
				ret = push(stk);
				break;
			case POP:
				break;
			case PULL:
				break;
			case SEARCH:
				break;
			case EXIT:
				fprintf(stdout, "Exiting stack ...\n");
				done = 1;
				ret = SUCCESS;
				break;
			default:
				ret = INVALID_OP;
				fprintf(stdout, "Invalid stack operation !\n");
		}
		switch(ret) {
			case SUCCESS:
				fprintf(stdout, "Success\n");
				break;
			case FAILURE:
				fprintf(stdout, "Failure\n");
				break;
			case NO_STACK_FOUND:
				fprintf(stdout, "No stack found\n");
				break;
		}
	}
}

void stack(void* stk_f)
{
	struct stack* stk = (struct stack*)stk_f;
	
	fprintf(stdout, "Stack implementation through dynamic array ...\n");
	stack_op(stk);
	return;
}
