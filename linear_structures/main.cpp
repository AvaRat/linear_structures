#include <cstddef>
#include <cstdlib>
#include <string>
#include "pch.h"
#include <iostream>
//#include <vector>
#include "Vector.h"

using namespace aisdi;
//using namespace std;
/*
void print_vector(vector<int> &v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
}
*/


int main(int argc, char** argv)
{
	int arr[5] = {0,43,12,543,49};

	Vector<int> vec;

	vec.append(4);
	vec.append(839);
//	vec.print();

	for (unsigned int i = 0; i < 200; ++i)
		vec.append(i * 12);

	Vector<int> v = { 1,5,1234,34};
	v.print();
//	vec.print();
//	vec.printStats();




//	Vector<int>::iterator it;

//	++it;
//	cout << "capacity " << vec.capacity() << endl;
//	cout << sizeof vec << endl;
//	vec.push_back(290);
//	print_vector(vec);
	
	return 0;
}

