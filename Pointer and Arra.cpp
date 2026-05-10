#include <iostream>
using namespace std;

int main(){
	int parr[]={65, 43,21,89,67};
	int* p= parr;
	
	cout <<"The address of arr[0]: "<<p<<endl;
	cout<<"\nPrinting all elements through pointer: \n";
	
	for (int i=0; i<5; i++){
		cout<<*(p+i)<<endl;
	}
	
	cout<<"\n\nPrinting the array after changing the value at index number 3:\n ";
	*(p+3)=21;
	for (int i=0; i<5; i++){
		cout<<*(p+i)<<endl;
	}
return 0;
}

