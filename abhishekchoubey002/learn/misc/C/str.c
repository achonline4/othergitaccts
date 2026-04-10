#include <stdio.h>
void fillbuf(char *errbuf)
{
	        sprintf(errbuf, "hello world\n");
}

int main(void) {
	        char errbuf[1024];
		        fillbuf(errbuf);
			        printf("errbuf = %s\n", errbuf);
}
