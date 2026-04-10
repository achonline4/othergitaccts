#ifndef STACK
#define STACK



struct stack {
	int *arr;
	int size;
	int top;
	// int (*push)(struct stack*);
	// int (*pop)();
	// int (*search)(struct stack*);
	// int (*pull)(struct stack*);
};

void stack(void* stk);
enum stack_ops {
	NONE = 0,
	CREATE,
	PUSH,
	POP,
	PULL,
	SEARCH,
	EXIT
};

enum retcode {
	SUCCESS = 0,
	FAILURE,
	NO_STACK_FOUND,
	INVALID_OP
};

#endif
