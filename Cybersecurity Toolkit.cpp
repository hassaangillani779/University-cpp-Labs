#include <iostream>
#include <string>
using namespace std;

//function for password strength
string passwordStrength(string pass){
	bool length = false;
	bool hasdigit = false;
	bool hasupper = false;
	bool special = false;
	if(pass.length()>=8) length=true;
	
	for(int i=0; i<pass.length(); i++){
		if (isdigit(pass[i])){
			hasdigit = true;
		}
		if(isupper(pass[i])){
			hasupper = true;
		}if(!isalpha(pass[i]) && !isdigit(pass[i])){
			special = true;
		}
		
	}
	if(!hasdigit)cout<<"Include atleast one digit(1-9)\n";
	if(!hasupper)cout<<"Include atleast one uppercase letter(A-Z)\n";
	if(!length)cout<<"Increase the length to more than 8 characters!!\n";
	if(!special)cout<<"Add a special character to give a tuff time to hackers$$\n";
	
	if(length && hasupper && hasdigit && special){
		return "Hmm---Strong Password\n";
	}
	
	if(length && hasupper && hasdigit){
		return "It can be a Strong Password\n";
	}else{
		return "Ah---An easy target!!\n";
	}
}

//ceaser cypher
string ceaser(string pass, int value){
	string result="";
	for (int i=0; i<pass.length(); i++){
		if (isupper(pass[i])){
		 result += 'A'+(pass[i]-'A'+value) % 26;
		}else if (islower(pass[i])){
			result += 'a'+(pass[i]-'a'+value) % 26;
		}else{
			result += pass[i];
		}
	}
	return result;
}
//defining struct for login system
struct User{
	string Username;
	string password;
};



//function for login system
string loginsystem(string enteredUser, string enteredPass){
	User users[]={
{"Haider", "in78"},
{"Mustafa", "uih89"},
{"Imran", "j!hiu8"}
};

int size = 3;

for (int i=0; i<size; i++){
	if(enteredUser==users[i].Username && enteredPass==users[i].password){
	return "Access Granted";}
	
}
	return "Access Denied\n\n";
}

//main function contains the menu loop and calls other functions
int main(){
	int choice;
	bool running = true;
	string password;
	int value;
	string username, pass;
	
	while (running){
		cout<<"=====Cybersecurity Toolkit=====\n\n";
		cout<<"-----Toolkit Menu-----\n";
		cout<<"Choose any of the options below: \n\n";
		cout<<" 1: Password Strength Checker-\n";
		cout<<" 2: Ceaser Cipher-\n";
		cout<<" 3: User Login System-\n";
		cout<<" 4: XOR Encrypter-\n";
		cout<<" 5: Brute Force PIN Detector-\n";
		cout<<" 6: Exit--\n\n";
		cout<<"Enter your choice: ";
		
		cin>>choice;
		
		if (choice==1){
			cout<<"Enter the password you want to analyze: ";
			cin.ignore();
			getline(cin, password);
			cout<<passwordStrength(password);
			cout<<"\n\n";
		}if(choice==2){
			cout<<"Enter a string to see the magic of encryption: ";
			cin.ignore();
			getline(cin, password);
			cout<<"\n";
			cout<<"Enter the shifting value: ";
			cin>>value;
			cin.ignore();
			
			while(!(cin>>value)){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"Invalid! Enter a number: ";
		}
		
		cout<<"The encrypted string is: "<<ceaser(password,value)<<"\n\n";
	}if (choice==3){
		cout<<"-----Login Page-----\n";
		cout<<"Enter your username: ";
		cin.ignore();
		getline(cin, username);
		cout<<"\nEnter your password: ";
		getline(cin,pass);
		cout<<endl;
		cout<<loginsystem(username, pass);
	}
		if (choice==6){
			running=false;
		}
	}
	return 0;
}
