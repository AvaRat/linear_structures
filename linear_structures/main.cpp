#include "pch.h"
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include "Vector.h"

using namespace aisdi;
using namespace std;




class test_class {
public:
	int x__;
	std::string word;
	double d__;
	test_class() {
		x__ = 0;
		d__ = 0;
		word = "default";
	}
	test_class(int a, double b, std::string w) 
	{
		x__ = a;
		d__ = b;
		word = w;
	}
	friend std::ostream& operator<< (std::ostream& stream, const test_class& object)
	{
		stream << "x: ";
		stream << object.x__ << std::endl << "d: " << object.d__ << std::endl << "word: " << object.word << std::endl;
		return stream;
	}




};


int main(int argc, char** argv)
{

/*
	int arr[5] = { 0,43,12,543,49 };

	Vector<float> vec = {1, 5, 24, 900, 1, 4, 2, 453, 1};
	vec.prepend(90);
	vec.print();
	vec.append(1239);
	vec.print();



	
	Vector<float>::Iterator ptr;
	ptr = vec.begin();
	std::cout << *ptr;
//	ptr++;
*/

//timer
	/*
	test_class einz(1, 2.543, "marcel");
	test_class zwei(2, 10.543, "kalinski");
	test_class drei(3, 1248921.5413433, "liczba");

	Vector<test_class> std_vec = { einz, zwei, drei};
	Vector<test_class>::Iterator it = std_vec.begin();
	it++;
	std::cout << *it;
	it--;
	std::cout << *it;
	it = std_vec.end();
	it -= 2;
	std::cout << *it;
	Vector<test_class> s_vec(std_vec);
	it = s_vec.begin();
	std::cout << it[2];

	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	for (size_t i = 0; i < 1000; i++)
	{
		test_class tmp(i, 10 * i, std::to_string(i / 10));
		s_vec.append(tmp);
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "appending 1000 object took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us. \n";
	*/ 

//std
	
	Vector<int> std_vec = { 1,2,3,4,5,6,7,8,9,10 };
//	for (int n : std_vec)
//		cout << n << endl;
	Vector<int>::iterator it = std_vec.begin();
	Vector<int>::iterator temp = std_vec.begin();

//	cout << *it << endl;
	it = it + 5;
	it = it- 3;
//	cout << *it << endl;
		std_vec.print();
	std_vec.insert(it, 1000);
//	std::cout << *--(it = std_vec.end());
	std_vec.print();

//	for (int n : std_vec)
//		cout << n << endl;

//	it += 4;
//	std_vec.insert(it, 6);
//	cout << std_vec[4] << endl << std_vec[5] << endl;
//	cout << std_vec.size() << endl;


//iterator
/*

	Vector<int> vec = { 1,2,3,4,5,6,7,8,9,10};

	vec.prepend(190);
	vec.print();

	Vector<int>::Iterator it = vec.begin();

	it += 4;
	vec.insert(it, 1000);
	//vec.print();
*/


	
	return 0;
}
