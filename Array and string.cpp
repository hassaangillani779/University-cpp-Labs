#include <iostream>
#include <string>
using namespace std;


int main(){
	int grades[5];
	int size = 5;
	
	
	for (int i=0; i<size; i++){
		cout<<"Enter grades of subject "<<i+1<<":  ";
		cin>>grades[i];
	}
	
	int highest=grades[0];
	int lowest=grades[0];
	
	for (int i=0; i<size; i++){
		if (grades[i]>highest) highest=grades[i];
		if (grades[i]<lowest) lowest=grades[i];
	}
	
	int sum=0;
	float avg;
	
	for(int i=0; i<size; i++){
		sum += grades[i];
	}
	avg = (float) sum / size;
	
	
	string name = "Hassaan";
	
	cout<<"Highest: "<<highest<<endl;
	cout<<"Lowest: "<<lowest<<endl;
	cout<<"Average: "<<avg<<endl;
	
	cout<<"Report for "<<name<<" -Average: "<<avg;
	
	
	
	
	
	
}
