#include <iostream>
using namespace std;


double maximum (double arr[], int size){
	double max= arr[0];
	for (int i=0; i<size; i++){
		if (arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}

double minimum (double arr[], int size){
	double min= arr[0];
	for (int i=0; i<size; i++){
		if (arr[i]<min){
			min= arr[i];
		}
	}
	return min;
}

double average(double arr[], int size){
	double sum=0;
	double avg;
	
	for(int i=0; i<size; i++){
		sum += arr[i];
	}
	avg = (double) sum / size;
	return avg;
}


int main(){
	double num[5];
	int size=5;
	int no=1;
	cout<<"Enter five numbers: "<<endl;
	for (int i=0; i<size; i++){
		cout<<"Enter number "<<no<<" :";
		cin>>num[i];
		cout<<"\n";
		no++;
	}
	
	cout<<"The maximum number among these is: "<<maximum(num, size)<<endl;
	cout<<"The minimum number among these is: "<<minimum(num, size)<<endl;
	cout<<"The average of these numbers is: "<<average(num, size)<<endl;
	
	return 0;
	
}
