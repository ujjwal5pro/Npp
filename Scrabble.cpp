/**********************************
	> Filename : Scrabble.cpp
	> Author : clone
	> Mail : theujjwalverma@wordpress.com
	> Created : 24-08-2021 12:16 

**********************************/

// includes
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<exception>

// micros
#define FOR(i,num) for(int i=0;i<num;i++)

using namespace std;

int main(){
	
	int points[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
	string word;
	int result[2]{0,0};
	
	// To check any exception in runtime
	try{
		exception e;
		
		// players input
		cout<<"Player 1: ";
		cin>>word;
		
		FOR(i,word.length())
			result[0]+=points[int(toupper(word[i]))-65];
		
		cout<<"Player 2: ";
		cin>>word;
		
		FOR(j,word.length())
			result[1]+=points[int(toupper(word[j]))-65];
		
		/*cout<<"Player 1 score : "<<result[0]<<endl;
		cout<<"player 2 score : "<<result[1]<<endl;*/
		
		//Winner announce
		if(result[0]>result[1])
			cout<<"Player 1 won!";
		else if(result[0]<result[1])
			cout<<"Player 2 won!";
		else 	 
			throw "Game tie!";
			//cout<<"Game Tie!";
		
	}
	catch(exception& e) { cout<<"Error : "<<e.what(); }
	catch(...)	{ cout<<"Unknown error"; }
	
	cout<<"\n";
	return 0;
}


