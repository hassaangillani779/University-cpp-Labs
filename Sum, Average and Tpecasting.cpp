#include <iostream>
using namespace std;

int main()
{
	// Sum
	int a, b, c, d;
    cout << "Enter four numbers:";
	cin>> a >> b >> c >> d;
	int sum;
	sum = a + b + c + d;
	cout<< "The sum of a, b, c and d is:" << sum;
	
	//Average and Typecasting
	float average = (float)sum / 4;
	cout<< "The average of these four numbers is:" << average;
	
	return 0;
	
	
}
