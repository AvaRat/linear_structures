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

template<typename TimeT = std::chrono::milliseconds>
struct measure
{
	template<typename F, typename ...Args>
	static typename TimeT::rep execution(F&& func, Args&&... args)
	{
		auto start = std::chrono::steady_clock::now();
		std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
		auto duration = std::chrono::duration_cast<TimeT>
			(std::chrono::steady_clock::now() - start);
		return duration.count();
	}
};

int main(int argc, char** argv)
{

//	LinkedList<int> l = {2,3};

	LinkedList<double> li;
	for (size_t i = 0; i < 10000; ++i)
	{
		li.append(i * 5 + i / 3);
	}
/*
	std::list<int> l = { 1,2,3,4,5 };
	std::list<int> l2(std::move(l));
	cout << l.size();
	for (int n : l) {
		cout << "l\n";
		std::cout << n << '\n';
	}
	for (int n : l2) {
		cout << "l2\n";
		std::cout << n << '\n';
	}
*/


	return 0;
}

//#endif