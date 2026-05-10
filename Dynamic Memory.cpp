#include <iostream>
using namespace std;

int main(){
	int* p= new int (10);
	cout<<"The value of p is: "<<*p<<endl;
	delete p;
	p = nullptr;
	
	int* a= new int[5];
	for(int i=0; i<5; i++){
		cout<<"Enter value "<<i+1<<": ";
		cin>>*(a+i);
	}
	cout<<"\n";
	for(int i=0; i<5; i++){
		cout<<"Value at index "<<i<<" is: "<<*(a+i)<<endl;
	}
	delete[] a;
	a=nullptr;
return 0;
}
