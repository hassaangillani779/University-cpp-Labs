#include <iostream>

using namespace std;
int main()
{
	float a, b, c, d;
	cout<< "Enter first number:" << endl;
	cin>> a;
	cout<<"Enter second number:" << endl;
	cin >> b;
	cout << "Enter third number:" << endl;
	cin >> c;
	cout << "Enter four number:" << endl;
	cin >> d;
	
	float sum= a + b + c + d;
	float subtraction= a-b-c-d;
	float multiplication= a*b*c*d;
	
	if (b !=0 && c!=0 && d!= 0){
		float division= a/b/c/d;
		cout<<"Divison:"<<division<<endl;
	}else{
		cout<< "Division cannot be performed" <<endl;
	}
	
	cout<<"Addition:" <<sum <<endl;
	cout<< "Subtraction: "<<subtraction<<endl;
	cout<< "Multiplication: "<< multiplication<<endl;
	
	
	
	return 0;
}
