#include <iostream>
using namespace std;

int main(void)
{
	int b = 10;
	int &ref = b;
	cout<<&b<<" ## "<<&ref<<endl;
	return 0;
}
