#include <iostream>
using namespace std;

int main()
{
	int score, bonus, penalty;
	cout<<"Enter your score: ";
	cin>>score;
	if(score>50){
		bonus=score + 10;
		cout<<"You have got a bonus of extra 10 marks!\n";
		cout<<bonus;
	}else{
		penalty=score*2;
		cout<<"You have got a penalty!\n";
	    cout<<penalty;	
		
	}if (score<100){
		++score;
		cout<<"Increment applied due to good performance:New score is  "<<score<<"\n";
	}else{
		cout<<"No increment applied. You have reached the maximum level.\n";
	}
		
	if (score>0){
		cout<<"Life Used.Score is "<<score--<<"\n";
		
	}else{
		cout<<"No Lives Left. Game Over!!\n";
	}if (score > 50){
    cout << "You are a Pro Player!\n";
     }
      else{
    cout << "Keep Practicing!\n";
     }
}

