#include <iostream>
using namespace std;

struct Threat {
    string source;
    int severity;
    bool blocked;
};

void printThreat(Threat t){
		cout<<"Source "<<t.source<<" |Severity "<< t.severity<<" |Blocked ="<< (t.blocked ? "Yes" : "No")<<endl;
}

int main(){
	
	Threat threats[3] = {
    {"192.168.43.0", 8, true},
    {"192.168.35.9", 2, false},
    {"192.178.89.3", 4, false}
};

for (int i = 0; i < 3; i++) {
    printThreat(threats[i]);
}
return 0;
}
