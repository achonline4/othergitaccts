#include <iostream>
#include <vector>
using namespace std;

template <class X> 

class var {
	private:
		vector<X> vars;
	public:
		void add_vars(X elem);
		void print_vars(void);
		void print_hello();
# if 0
		void print_vars(void)
		{
			int i;
			for(i=0;i<this->vars.size();i++)
				cout<<this->vars[i]<<endl;
		}

		void add_vars(X elem)
		{
			this->vars.push_back(elem);
		}
#endif
};

template <class X>
void var<X>::print_hello()
{
	cout<<"Hello World!"<<endl;
}

template <class X>
void var<X>::add_vars(X var)
{
	this->vars.push_back(var);
}	

template <class X>
void var<X>::print_vars(void)
{
	int i;
	for(i=0;i<this->vars.size();i++)
		cout<<this->vars[i]<<endl;
}

int main(void)
{
	var<int> ints;
	var<string> strs;
	var<float> flts;
	var<string> simple;

	simple.print_hello();
	ints.add_vars(1);
	ints.add_vars(1);
	ints.add_vars(1);
	ints.add_vars(1);
	ints.add_vars(1);
	ints.add_vars(12);
	ints.add_vars(113);
	ints.print_vars();
	strs.add_vars("Hello");
	strs.add_vars("World !");
	strs.print_vars();
	flts.add_vars(1.1);
	flts.add_vars(1.2);
	flts.add_vars(1.3);
	flts.print_vars();
	return 0;
}

/* Notes : 
 * 1. If we declare a class with template params, then we cannot
 * declare an instance of that class without template. For eg:
 * 	It is not possible to declare an instance of "class var" like this:
 * 	var instance;
 * 	*/

