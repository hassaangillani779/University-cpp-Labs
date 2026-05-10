#include <iostream>
using namespace std;

void pointerSwap(int* x, int* y){
	int temp =*x;
	*x = *y;
	*y = temp;
	cout<<"The value of x after swapping is: "<<*x<<endl;
	cout<<"The value of y after swapping is: "<<*y<<endl;
}

int main(){
	int x=10;
	int y=9;
	
	cout<<"Values before swapping:\n"<<x<<"\n"<<y<<endl;
	pointerSwap(&x , &y);
return 0;
}
