#include <iostream>
using namespace std;

int main(){
	int x = 79;
	
	cout << "Address of x directly: " << &x << endl;
	int* p = &x;
	
	cout<<"Adress stored in pointer: "<<p<<endl;
	cout<<"Printing the value inside x through derefrencing: "<<*p<<endl;
	*p = 64;
	cout<<"Value after change: "<<*p;
	
	return 0;
}
