#include<string.h>
using namespace std;

// declare structes
struct admin{
	string user="Admin";
	string password="Admin";
	
	public : 
	void banner();
	int login();
    int mainmenu();
	void masterHomepage(string str);
};

