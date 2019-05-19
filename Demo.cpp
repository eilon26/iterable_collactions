 
#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace itertools;

int main() {


	cout << endl << endl << "Range of ints: " << endl;
	for (int i: range(5,9))
		cout << i;    // 5678
	cout << endl << endl << "Range of doubles: " << endl;
	for (double i: range(5.1,9.1))
		cout << i << " ";    // 5.1 6.1 7.1 8.1
	cout << endl << endl << "Range of chars: " << endl;
	for (char i: range('a','e'))
		cout << i << " ";    // a b c d 

	// Note: this example works even without your code.
	// It shows that a string is also an "iterable" - it can be iterated with a for-each loop.
	cout << endl << endl << "Standard string: " << endl;
	for (char i: string("hello"))
		cout << i << " ";    // prints h e l l o 

	cout << endl << endl << "Chain of two ranges: " << endl;
	for (int i: chain(range(1,4), range(5,8)))
		cout << i;    // prints 123567
	cout << endl << endl << "Chain of a range and a string: " << endl;
	for (char i: chain(range('a','e'), string("hello")))
		cout << i;    // abcdhello
/*
    //itertools::pair<int,char> p(1,'c');
		//same
	for(auto p = zip(range(1,6),string("hello")).begin(); p != zip(range(1,6),string("hello")).end(); ++p)
	{
		cout << (*p) << " ";
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
*/
	cout << endl << endl << "Zip a range of ints and a string (must be of the same size)" << endl;
	for (auto pair: zip(range(1,6), string("hello")))
		cout << pair << "  ";    // 1,h  2,e  3,l  4,l  5,o


// for(zip<decltype(range(1,6)),decltype(string("hello"))>::iterator temp = zip(range(1,6),string("hello")).begin(); temp != zip(range(1,6),string("hello")).end() ; ++temp) 
// 			cout << *temp;

	cout << endl << endl << "Zip of zips" << endl;
	for (auto pair: zip(zip(range(1,4), string("xyz")),zip(string("abc"),range(6,9))))
		cout << pair << "  ";    // 1,x,a,6  2,y,b,7  3,z,c,8

	cout << endl << endl << "Cartesian product of a range of ints and a string (can be of different sizes)" << endl;
	for (auto pair: product(range(1,4), string("hello")))
		cout << pair << "  ";    // 1,h  1,e  1,l  1,l  1,o  2,h  2,e  2,l  2,l  2,o  3,h  3,e  3,l  3,l  3,o
/*
	for(powerset<decltype(range(1,6))>::iterator temp = powerset(range(1,6)).begin(); temp != powerset(range(1,6)).end() ; ++temp) 
					cout << *temp;
*/
	cout << endl << endl << "Power-set of range of ints " << endl;
	for (auto subset: powerset(range(1,4)))
		cout << subset;  // {}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}
    
	cout << endl << endl << "Power-set of chain " << endl;
	for (auto subset: powerset(chain(range('a','c'),range('x','z'))))
		cout << subset;  // {}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}
	
	return 0;
}
