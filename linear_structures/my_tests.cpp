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

	LinkedList<string> l;
//	LinkedList<int> li;
//	LinkedList<int>::Iterator i = l.begin();
	l.append("nacs");
	l.append("aoih");
	l.prepend(NULL);
	l.append("gqtdyu");

	l.print();



	list<string> std_l;
	std_l.push_back("nowy");
	list<string>::iterator  it_s = std_l.end();

//	cout << *it_s << endl << *(--(std_l.end())) << endl;
//	std_l.end()++;




	
	return 0;
}

//#endif