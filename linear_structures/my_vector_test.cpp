#include "pch.h"
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>

#include "Vector.h"


//#ifdef NOT_TEST

using namespace aisdi;
using namespace std;




class tester {
public:
	int x__;
	std::string word;
	double d__;
	tester() {
		x__ = 0;
		d__ = 0;
		word = "default";
	}
	tester(int a, double b, std::string w) 
	{
		x__ = a;
		d__ = b;
		word = w;
	}
	friend std::ostream& operator<< (std::ostream& stream, const tester& object)
	{
		stream << "x: ";
		stream << object.x__ << std::endl << "d: " << object.d__ << std::endl << "word: " << object.word << std::endl;
		return stream;
	}




};

//main

int main(int argc, char** argv)
{
//timer
	
	tester einz(1, 2.543, "marcel");
	tester zwei(2, 10.543, "kalinski");
	tester drei(3, 1248921.5413433, "liczba");
/*
	Vector<tester> std_vec = { einz, zwei, drei};
	Vector<tester>::Iterator it = std_vec.begin();
	Vector<tester> sec_vec = { zwei, einz, drei };
	Vector<tester>::Iterator it2;
*/	
	Vector<int> vec = { 1,5,10,50,150,27,24,5432,235,6432 };
	Vector<int>::iterator it = vec.begin() + 2;
	Vector<int>::iterator it2 = it + 1;

	Vector<int> v = { 9,9,9,9,9, };
	v = move(vec);
	vec.print();
//	vec.erase(it, it2);
	cout << *it << endl;
	v.print();
	
	return 0;
}

//#endif