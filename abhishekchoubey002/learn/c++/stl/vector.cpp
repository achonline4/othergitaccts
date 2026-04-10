#include "cpp.h"


static void insert(vector<int> *vect, float elem)
{
	vect->push_back(elem);
}

static void insert(vector<int> *vect, int elem)
{
	vect->push_back(elem);
}

static void fill_vect(vector<int> *vect, int size)
{
	int i;
	for(i=0; i<size; i++)
		vect->push_back(i);
}

static void print_vect(vector<int> *vect)
{
	vector<int>::iterator vit = vect->begin();
	while(vit != vect->end()) {
		cout<<*vit<<endl;
		vit++;
	}
}

template <typename T>
static int vsize(vector<T> *vect)
{
	return vect->size();
}


template <typename T>
static vector<T>::iterator* get_iterator(vector<T>  *vect)
{
	vector<T>::iterator *iter = new vector<T>::iterator;
	return iter;
}

int main(void)
{
	vector<int> vect;
	int i;
	fill_vect(&vect, 100);
	insert(&vect, 11.2f);
	//insert(&vect, 11.2); calling this way will result in compile time error.
	print_vect(&vect);
	cout<<"vect size = "<<vsize(&vect)<<endl;
	return 0;
}
