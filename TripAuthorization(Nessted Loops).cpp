#include<iostream>
using namespace std;

int main()
{
	
	int checkedin=0;
	int rejectedp=0;
	int rejectedm=0;
	int rejectedboth=0;
	string name, permission, money;
	
	for (int i=1; i<=5; i++){
		cout<<"Student "<<i<<": \n";
		cout<<"Enter your name: ";
		cin >>name;
		do{
			cout<<"Has "<<name<<" got permission from his parents:(yes/no)  ";
			cin>>permission;
			if(permission!="yes" && permission!="no")
			cout<<"Invalid Output. Only yes or no are accepted!";
		}while (permission!="yes" && permission!="no");
		
		do{
			cout<<"Has "<<name<<" paid the money:(yes/no) ";
			cin>> money;
			if (money!="yes" && money!="no")
			cout<<"Invalid Output. Only yes or no are accepted!\n";
		}while(money!="yes" && money!="no");
		if (permission=="yes" && money=="yes"){
			cout<<name<<" is eligible to go on the trip. \n\n";
			checkedin++;
		}else if (permission=="no" && money=="no"){
			cout<<name<<" is not eligble because he has not granted perrmission and not paid his money.";
			rejectedboth++;
		}else if (permission!="yes"){
			cout<<name<<" is not eligble because permission is not granted.";
			rejectedp++;
		}else{
			cout<<name<<" is not eligble because he has not paid his money.";
			rejectedm++;
		}
		
		
		
	}
	cout <<"Total Summary \n\n";
	cout <<"Total number of students going on trip: "<<checkedin<<"\n";
	cout <<"Number of rejected students due to permission: "<<rejectedp<<"\n";
	cout <<"Number of rejected students due to money: "<<rejectedm<<"\n";
	cout <<"Number of rejected students due to both: "<<rejectedboth<<"\n";
}
