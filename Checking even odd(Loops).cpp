#include <iostream>
using namespace std;

int main()
{
	int num;
	for (int i=1; i<=10; i++){
		cout <<"Enter number "<< i <<": " ;
		cin>>num;
		
		
		if (num % 2==0){
			cout<<num<<" is Even. "<<endl;
		}else{
			cout<<num<<" is Odd. "<<endl;
		}
		
	}
	
	
}
