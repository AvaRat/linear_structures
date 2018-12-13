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
#include <list>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Vector.h"
#include "LinkedList.h"



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

//	LinkedList<int> l = {2,3};

	LinkedList<int> l2 = { 1,2,3,4,5,6,7,8,9 };
	LinkedList<int>::iterator it = l2.end();
	it--;
	l2.insert(it, 77);
	l2.print();
	cout << endl;
	l2.erase(l2.begin());
	l2.print();
	





	return 0;
}

//#endif