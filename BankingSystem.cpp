/*************************************************
	> Filename : Banking System
	> Author : clone
	> Mail : theujjwalverma@wordpress.com
	> created : 2021-08-20 20:19
*************************************************/

// includes
#include<iostream>
#include<conio.h>
#include<string.h>
#include".\b_help.h"
using namespace std;

//macros
#define newl "\n\t\t\t"
#define FOR(i,n) for(int i=0;i<n;i++)
	
//global variables
const int MAX_entry = 10;
int BCount = 0;
int CCount = 0;
int TCount = 0;
int ECount = 0;

struct branch{
    string name;
    string address;
    long ID;
	bool is_deleted;
    int count=0;
	
	public: 
	void homepage();
	void add();
	void del();
	void update();
	void viewlist();
	void view(int i);
	
}b[MAX_entry];

struct customer{
	string name;
	string address;
	static int accounttno;
	long balance;
	int count=0;
	bool is_deletd;
	
	public: 
	void homepage();
}c;

struct transacton{
	static int ID;
	int accounttno;
	long balance;
	long tr_amount;	
	int count=0;
	bool is_deleted;
	
	public: 
	void homepage();
}t;

struct employee{
	string name;
	string address;
	static int ID;
	int count=0;
	bool is_deleted;
	
	public: 
	void homepage();
}e;


//Main program
int main(){
	
	admin bank;
	bank.banner();
	
	while(1){
		bank.banner();
		if(bank.login()) {
			bank.mainmenu();
			cout<<"Do you want to exit (y/n):";
			if(getch()=='y') return 0;
		} 
	}		
	return 0;
}


//define Fuctions
void admin::banner(){
	system("cls");
	cout<<"**************************************";
	cout<<"**************************************\n";
	cout<<newl<<"Unisef Bank Mars PVT. LTD.\n";
	cout<<"**************************************";
	cout<<"**************************************\n";
}

int admin::login(){
    static string uname;
	string pwd;
	static string error;
	
	cout<<newl<<"Login"<<error;
	cout<<newl<<"Enter Username:";
	if(uname!=user)
		cin>>uname;
	else
		cout<<uname<<endl;
	if(uname!=user){
		error=" : Invalid user";
		return 0;
	}else{
		//cin.ignore('\n');
		cout<<"\t\t\tEnter Password:";
		cin>>pwd;
		if(pwd!=password){
			error =" : Invalid Password";
			return 0;
		}
		error="";
	}
		
	return 1;
}

int admin:: mainmenu(){
	int selection=-1;
	while(selection){
		system("cls");
		cout<<"\n\n\tMain Menu"<<endl;
		cout<<"1. Branch"<<endl;
		cout<<"2. Customer"<<endl;
		cout<<"3. Transaction"<<endl;
		cout<<"4. Employee"<<endl;
		cout<<"0. Logout"<<endl;
		cout<<"\nSelect option : ";
		cin>>selection;
		switch(selection){
			case 1: b[1].homepage();
			        break;
			case 2: c.homepage();
					break;
			case 3: t.homepage();
					break;
			case 4: e.homepage();
					break;
			case 0: break;
			Default : selection=-1;
		}
	}
	return 0;
}

void branch::homepage(){
   while(1){
		system("cls");
		cout<<"\n\n Branch Menu"<<endl;
		cout<<"1. Add"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Update"<<endl;
		cout<<"4. View"<<endl;
		cout<<"0. Back"<<endl;
		cout<<"\nSelect option : ";
		switch(getch()){
			case '1':add();
				break;
			case '2':del();
				break;
			case '3':update();
				break;
			case '4':viewlist();
				getch();
			    break;
			case '0': return;
			default : break;
		}
	}
}

void branch::add(){
	cout<<"\n";
	cout<<"Enter name :";
	cin>>b[BCount].name;
	cout<<"Enter address :";
	cin>>b[BCount].address;
	b[BCount].ID=BCount;
	b[BCount].is_deleted=false;
	BCount++;
}

void branch::del(){
	string b_name = "";
	int ID = -1;
	bool is_success=false;
	cout<<"\n";
	cout<<"1. Delete by name"<<endl;
	cout<<"2. Delete by ID"<<endl;
	cout<<"Select option :";
	switch(getch()){
		case '1' : 
			cout<<"\nEnter name :";
			cin>>b_name;
			break;
		case '2':
			cout<<"\nEnter ID :";
			cin>>ID;
			break;
		default : cout<<"Invalid selection"<<endl;
			break;
	}
	
	FOR(i,BCount){
		if(b[i].name==b_name || b[i].ID==ID){
			b[i].is_deleted=true;
			is_success=true;
			break;
		}
	}
	
	if(is_success)
		cout<<"Item deleted";
	else
		cout<<"item not found";
	
	getch();
	//comming soon;
}

void branch::update(){
	
	//comming soon;
}

void branch::viewlist(){
	cout<<"\n";
	cout<<"ID\tNAME\tADDRESS"<<endl;
	FOR(i,BCount){
		if(b[i].is_deleted==false)
			cout<<i<<"\t"<<b[i].name<<"\t"<<b[i].address<<endl;
	}
}

void branch::view(int i){
	cout<<"\nBranch Details";
	cout<<"\nName: "<<b[i].name;
	cout<<"\nAddress: "<<b[i].address;
	cout<<"\nID: "<<b[i].ID;
}

void customer::homepage(){
	int selection;
	system("cls");
	cout<<"\n\n Customer Menu"<<endl;
	cout<<"1. Add"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Update"<<endl;
	cout<<"4. Search"<<endl;
	cout<<"0. Back"<<endl;
	cout<<"\nSelect option : ";
	cin>>selection;
}

void transacton::homepage(){
	int selection;
	system("cls");
	cout<<"\n\n Transaction Menu"<<endl;
	cout<<"1. Deposit"<<endl;
	cout<<"2. Withdraw"<<endl;
	cout<<"3. Transaction details"<<endl;
	cout<<"0. Back"<<endl;
	cout<<"\nSelect option : ";
	cin>>selection;
}

void employee::homepage(){
	int selection;
	system("cls");
	cout<<"\n\n Employee Menu"<<endl;
	cout<<"1. Add"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Update"<<endl;
	cout<<"4. Search"<<endl;
	cout<<"0. Back"<<endl;
	cout<<"\nSelect option : ";
	cin>>selection;
}