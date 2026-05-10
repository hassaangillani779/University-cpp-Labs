#include <iostream>
using namespace std;

int main(){
	int a = 73;
	int* sPointer = &a;
	int** dPointer = &sPointer;
	
	cout<<"The value of int a: "<<a<<endl;
	cout<<"The value of single pointer is: "<<*sPointer<<endl;
	cout<<"The value of double pointer is: "<<**dPointer<<endl;
	
	**dPointer=69;
	cout<<"Changed value through double pointer: "<<a;
	
	return 0;
}
