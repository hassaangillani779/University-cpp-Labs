#include <iostream>
using namespace std;

int main()
{
	int a=5, b=5;
	
	cout<< "Initial value of a:" << a << endl;
	cout<< "Initial value of b:" << b << endl;
	
	cout<< "\nUsing prefix(++a):" << ++a << endl;
	cout<< "Value of a after prefix" << a << endl;
	
	cout<< "\nUsing postfix(b++)" << b++ << endl;
	cout<< "Value of b after postfix" << b << endl;
	
	return 0;
}
