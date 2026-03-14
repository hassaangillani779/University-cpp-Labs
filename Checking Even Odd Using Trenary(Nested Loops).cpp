#include <iostream>
using namespace std;

int main()
{
	int num;
	for(int i=1; i<=10; i++){
		cout<< "Enter number "<<i<<" : ";
		cin>>num;
		
		string evenodd= (num%2==0)? "Even Number" : "Odd Number";
		string posneg= (num>0)? "Positive " : (num<0)? "Negative " : "Zero";
		
		cout<<num<<" is "<<evenodd<< " and " <<posneg<<"\n\n";
	}
}
