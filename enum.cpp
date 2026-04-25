#include <iostream>
using namespace std;

enum Threat{
	LOW,
	MEDIUM,
	HIGH
};

int main(){
	Threat t= HIGH;
	
	switch(t) {
    case LOW:    cout << "Low threat" << endl; break;
    case MEDIUM: cout << "Medium threat" << endl; break;
    case HIGH:   cout << "High threat" << endl; break;
}
return 0;
}
