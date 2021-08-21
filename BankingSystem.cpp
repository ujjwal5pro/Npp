/*************************************************
		> Filename : Banking System
		> Author : clone
		> Mail : theujjwalverma@wordpress.com
		> created : 2021-08-20 20:19
*************************************************/

//Header files
#include<iostream>
#include<conio.h>
#include<string.h>
#define newl "\n\t\t\t"

using namespace std;

//Class
class admin{
	string user="Admin";
	string password="Admin";
	
	public : 
	void banner();
	int login();
    int mainmenu();
};

static class branch{
    string name;
    string address;
    long ID;
    int count=0;
	
	public: 
	void homepage();
	void add();
	void view();
	
}b,bnew[10];

static class customer{
	string name;
	string address;
	static int accounttno;
	long balance;
	int count=0;
	
	public: 
	void homepage(){
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
}c,cnew[10];

static class transacton{
	static int ID;
	int accounttno;
	long balance;
	long tr_amount;	
	int count=0;
	
	public: 
	void homepage(){
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
}t,tnew[50];

static class employee{
	string name;
	string address;
	static int ID;
	int count=0;
	
	public: 
	void homepage(){
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
}e,enew[10];


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


//Fuctions
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
			case 1: b.homepage();
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
	int selection;
	system("cls");
	cout<<"\n\n Branch Menu"<<endl;
	cout<<"1. Add"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Update"<<endl;
	cout<<"4. Search"<<endl;
	cout<<"0. Back"<<endl;
	cout<<"\nSelect option : ";
	cin>>selection;
	switch(selection){
		case 1:add();
			   break;
		case 4:view();
		       getch();
		default : break;
	}
}

void branch::add(){
	cout<<"Enter name :";
	cin>>bnew[count].name;
	cout<<"Enter address :";
	cin>>bnew[count].address;
	bnew[count].ID=count;
	count++;

}

void branch::view(){
	cout<<"\nBranch Details";
	cout<<"\nName: "<<bnew[count].name;
	cout<<"\nAddress: "<<bnew[count].address;
	cout<<"\nID: "<<bnew[count].ID;
}
