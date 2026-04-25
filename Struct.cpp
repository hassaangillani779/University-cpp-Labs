#include <iostream>
using namespace std;

struct Threat{
	string source;
	int severity;
	bool blocked;
};

int main(){
	

	Threat h1;
	
	h1.source="192.168.43.0";
	h1.severity=8;
	h1.blocked=true;
	
	Threat h2;
	
	h2.source="192.168.35.9";
	h2.severity=2;
	h2.blocked=false;
	
	Threat h3;
	
	h3.source="192.178.89.3";
	h3.severity=4;
	h3.blocked=false;
	
		
	cout<<"Source "<<h1.source<<" |Severity "<< h1.severity<<" |Blocked ="<< (h1.blocked ? "Yes" : "No")<<endl;
    cout<<"Source "<<h2.source<<" |Severity "<< h2.severity<<" |Blocked ="<< (h2.blocked ? "Yes" : "No")<<endl;
    cout<<"Source "<<h3.source<<" |Severity "<< h3.severity<<" |Blocked ="<< (h3.blocked ? "Yes" : "No")<<endl;
    
    return 0;
}
