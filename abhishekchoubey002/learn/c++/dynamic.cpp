#include "cpp.h"

int main(void)
{
	char *arr;
	std::ostringstream out;
	char *txt = "Hello WOrld!";
	out<<txt;
	cout<<out.str()<<endl;
	return 0;
}
