#include "cpp.h"

class myexp : public exception {
	public:
	const char* what() const throw()
	{
	//	cout<<"Myex"<<endl;
		return "MyCppExp";
	}
};

int main(void)
{
	int a = 10, b = 10;
	
	try {
		if(b==0)
			throw "DBZ exception";
		else if(b==10)
			throw myexp();
		else
			cout<<a/b<<endl;
	}catch (const char* msg) {
		cout<<msg<<endl;
	}catch(myexp& m) {
		cout<<m.what()<<endl;
	}
}
