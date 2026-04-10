#include <stdio.h>
int main(void)
{
	struct a {
		int a;
	};

	struct a b;
	const struct a *a;

	a = &b;
	a->a = 10;
	return 0;
}
