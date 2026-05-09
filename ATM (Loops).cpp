#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int pin= 7993;
	int enteredpin;
	double balance= 5500;
	double amount;
	int attempts= 0;
	
	cout<<"Welcome to the ATM \n\n";
	
	do{
		cout<<"Enter your PIN: ";
		cin>> enteredpin;
		attempts++;
		
		if (enteredpin!=pin){
			if(attempts==3){
				cout<<"Too many wrong attempts. Card is Locked. Contact the Bank! \n\n";
				return 0;
			}
			cout<<"Wrong Password! "<<(3-attempts)<<" Left! \n\n";
		}
	}while (enteredpin!=pin && attempts<3);
	
	cout<<"Pin Accepted.\n Welcome!";
	
	string again;
	do{
		cout<<"Enter the amount you want to withdraw: ";
		cin>>amount;
		
		if (amount <= 0){
			cout<<"Invalid Amount\n\n";
		}else if (amount>balance){
			cout<<"Insufficent Balance! Your current balance is "<<balance<<" rupees.\n\n";
	      }else if (fmod (amount, 10) !=0){
	      	cout<<"Only amount in multiples of 10 can be withdrawn.\n\n";
		  }else{
		  	balance -= amount;
		  	cout<<"Dispensing "<<amount<<"\n\n";
		  	cout<<"Remaining Balance is "<<balance<<"\n\n";
		  }
		  cout<<"Do you want to withdraw more money? (yes/no)";
		  cin>>again;
		  cout<<"\n";
	
	}while (again=="yes");
	cout<<"Thanks for using the ATM";
	return 0;
}
