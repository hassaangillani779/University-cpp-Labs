#include <iostream>
using namespace std;

void activity(int arr[], int size){
	int max= INT_MIN;
	bool alert= false;
	for (int i=0; i<size; i++){
		if(arr[i]>max){
		 max = arr[i];
		}
		cout<<"The score is at index "<<i<<" is: "<<arr[i]<<endl;
		if(arr[i]>75){
			alert= true;
		}
	}
	cout<<"The maximum number in the array is "<<max<<endl;
	if(alert) cout<<"ALERT: Suspicious Activity detected!!"<<endl;
	else cout<<"System clean---";
}

int main(){
	int arr[] ={34, 67, 89, 90, 70};
	int size = 5;
	
	cout<<"===== Suspicion Score Checker ====="<<endl;
	activity(arr, size);
	
	return 0;
}
