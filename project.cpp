//following liberaries are used in this project
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;
//following functions are used in project
void welcome(string user);
void registr();
int login(string &user);
void newaccount();
void admin_menu(string user);
void acc_deposit();
void acc_withdraw();
void view_all();
void delete_acc();
int numoflines();
void modifyaccount();
void funds_transfer();
void billandshopping();
void user_menu(int &res);
int passwordexists(string username);
void user_deposit(int &res);
void user_withdraw(int &res);
void user_modify(int &res);
void user_funds(int &res);
void user_billshopping(int &res);
int main(){
	string user;
	welcome(user);
system("pause");
}
void welcome(string user) //this function displays welcome screen alongwith login and registration options
{
	system("cls");
	int a=0,res;
	cout<<endl<<endl<<"***********************************************************\n\n\n";
	cout<<"        WELCOME TO BANK MANAGEMENT SYSTEM\n\n\n"<<"***********************************************************\n\n\n";
	cout<<"  1: LOGIN\n  2: REGISTER\n\nEnter a choice\n";
	cin>>a;
	cin.ignore();
	system("cls");
	if(a==1)
	res=login(user);
	else if (a==2)
	registr();
	if (res==0)
	{
		admin_menu(user);
}
	else if(res!=0){
		user_menu(res);
	}}
int numoflines(){ //this function is used to calculate number of enteries in files by calculating lines of "user" file
string garb;
	int c=0;
	ifstream fin;
	fin.open("user.txt");
	while(!fin.eof()){
		getline(fin,garb);
		if(garb!="")
		c++;
		if(garb=="" && c==0)
			return 0;}
	fin.close();
	return c;
}
void registr() { //this is admin registration function
	int count=1,flag=0,flag2=0,flag3=0,c,count2=1,flag4=0,flag5=0;
	char username[50],password[50];
	string user;
	cout<<endl<<endl<<"Enter username: ";
	cin.getline(username,50);
	for (int a=0;username[a]!='\0';a++){
	if ((username[a]>31 && username[a]<48) || (username[a]>57 && username[a]<65))
	flag++;
	}
	if(flag!=0)
	cout<<"Username must not contain special characters\n";
	while (username[count]!='\0')
		count++;
	if (count<8)
	cout<<"Username is too short\n";
	else if (count>=7)
	flag3=1;
	c=count-1;
	if (count%2==0){
	if (username[c]<58 && username[c]>47)
	flag2=1;
	else if (flag2==0)
	cout<<"Username must contain a digit at middle or at end\n";
	}
	else if (count%2==1){
	if (username[c]<58 && username[c]>47)
	flag2=1;
	if (username[count/2]<58 && username[count/2]>47)
	flag2=1;
	else if (flag2==0)
	cout<<"Username must contain a digit at middle or at end\n";
	}
	if (flag2==1 && flag==0 && flag3==1)
	{cout<<endl<<"Enter password: ";
	cin.getline(password,50);
	while (password[count2]!='\0')
	count2++;
	if (count2<6)
	cout<<"Password is too short\n";
	else
	flag4=1;
	int result=strcmp(username,password);
	if (result==0)
	cout<<"Username and password can't be same\n";
	else
	flag5=1;
	if (flag4==1 && flag5==1)
	{
		ofstream fout;
		fout.open("register.txt",ios::app);
		fout<<username<<" "<<password<<endl;
		fout.close();
		cout<<"Registration successful\n";
}}
	getch();
		welcome(user);
}

int login(string &user) // this is login function for admin as well as user
{
	string username_l,password_l,username_inp,password_inp;
	int flag,choice,lines=numoflines(),c=0,count=0;
	cout<<"\n1. Login as admin\n\n2. Login as user\n\nEnter choice: ";
	cin>>choice;
	cin.ignore();
	system("cls");
	if(choice==1){
	cout<<"\nEnter username: ";
	getline(cin,username_inp);
	cout<<"\nEnter password: ";
	getline(cin,password_inp);
		ifstream fin;
	fin.open("register.txt");
	while(!fin.eof())
	{
		if(username_l=="" && password_l=="" && count==1)
			break;
		fin>>username_l>>password_l;
		count++;
		if(username_l==username_inp && password_l==password_inp){
			user=username_l;
			return 0;
		}
		else
		{
			flag=1;
		}
	}
	if(flag=1){
		cout<<"Username or password is not correct\n";
		getch();
		welcome(user);
}
}
	else if(choice==2){
		int flag;
		ifstream fin,fin1,fin2;
		string user,pass,userinp,passinp,usrn;
		cout<<"\nEnter your name: ";
		getline(cin,userinp);
		if (passwordexists(userinp)==1){
		cout<<"\nEnter password: ";
		getline(cin,passinp);
		int lines=numoflines();
		fin.open("user.txt");
		fin1.open("password.txt");
		for(int a=1;a<=lines;a++){
			getline(fin,user);
			getline(fin1,pass);
			c++;
			if(user==userinp && pass==passinp){
				return c;
			}
			else
				flag=1;
		}
			if(flag==1){
			cout<<"Username or password is incorrect\n";
			}}
		else{
			fin2.open("user.txt");
		for(int y=0;y<numoflines();y++){
			getline(fin2,usrn);
			if(usrn!=userinp)
				flag=1;
			else{
				flag=0;
				break;}

		}
		if(flag==1)
			cout<<"Your name is not in the list\n";
		else if(flag==0){
			string usr[100],passw,pas[100];
			ifstream fin,fin2;
			ofstream fout;
			fin.open("user.txt");
			fin2.open("password.txt");
			cout<<"Enter your new password: ";
			getline(cin,passw);
			for(int a=0;a<lines;a++)
			{
				getline(fin,usr[a]);
				getline(fin2,pas[a]);
			}
			fout.open("password.txt");
			for(int x=0;x<lines;x++){
				if(userinp==usr[x])
					fout<<passw<<endl;
				else
					fout<<pas[x]<<endl;
			}
			fout.close();
			cout<<"password updated\n";
		}}}
getch();
welcome(user);}
void admin_menu(string user)// this function displays admin menu and options
{
	system("CLS");
	int option;
	cout<<endl<<endl<<"WELCOME "<<user<<endl<<endl;
		cout<<"1. New Account Creation\n2. Amount Deposit\n3. Amount Withdraw\n4. Complete account holder list\n5. Delete an account\n6. Modify an account\n7. Funds transfer\n8. Use Account to pay Bills/Shoping\n9. Logout\n\n\nEnter a choice:\n";
		cin>>option;
		cin.ignore();
		system("CLS");
		switch(option){
			case 1:
				newaccount();
				getch();
				admin_menu(user);
				break;
			case 2:
				acc_deposit();
				getch();
				admin_menu(user);
				break;
			case 3:
				acc_withdraw();
				getch();
				admin_menu(user);
				break;
			case 4:
				system("cls");
				view_all();
				cout<<endl<<"Press any key to go back\n";
				getch();
				admin_menu(user);
				break;
			case 5:
				delete_acc();
				getch();
				admin_menu(user);
				break;
			case 6:
				modifyaccount();
				getch();
				admin_menu(user);
			case 7:
				funds_transfer();
				getch();
				admin_menu(user);
			case 8:
				billandshopping();
				getch();
				admin_menu(user);
			case 9:
				welcome(user);

		}
}
void newaccount(){// function of admin for creation of new account for user
		char username[50],type;
	int balnc;
	cout<<"Enter Name: ";
	cin.getline(username,50);
	cout<<endl<<"Enter Account Type(c/s): ";
	cin>>type;
	cout<<endl<<"Enter initial balance (Minimum 1000 for Current and 500 for saving): ";
	cin>>balnc;
	ofstream fout;
	if((type=='s' && balnc>=500)|| (type=='c' && balnc>=1000)){
	fout.open("user.txt",ios::app);
	fout<<username<<endl;
	fout.close();
	fout.open("type.txt",ios::app);
	fout<<type<<endl;
	fout.close();
	fout.open("balance.txt",ios::app);
	fout<<balnc<<endl;
	fout.close();
	cout<<"User account created\n";}
	else
		cout<<"Not enough balance\n";
	}
void acc_deposit()//admin function to add ammount of selected user in "user.txt" file
{
	int ch,lines=numoflines(),amm,arr[100];
	view_all();
	cout<<"Enter choice\n";
	cin>>ch;
	cout<<"Enter ammount to deposit\n";
	cin>>amm;
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<lines;a++){
		fin>>arr[a];
	}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<lines;b++){
		if(b+1==ch){
			fout<<arr[b]+amm<<endl;
		}
		else
		fout<<arr[b]<<endl;
	}
	cout<<"Ammount deposited\n";
}
void acc_withdraw()//admin function to withdraw ammount
{
	int ch,lines=numoflines(),amm,arr[100];
	view_all();
	cout<<"Enter choice\n";
	cin>>ch;
	cout<<"Enter ammount to withdraw\n";
	cin>>amm;
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<lines;a++){
		fin>>arr[a];
	}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<lines;b++){
		if(b+1==ch){
			if(arr[b]-amm>0){
			fout<<arr[b]-amm<<endl;
			cout<<"Ammount withdrawn\n";}
			else
			{fout<<arr[b]<<endl;
			cout<<"Not enough balance\n";
			}
		}
		else
		fout<<arr[b]<<endl;
	}
}
void view_all()//all user accounts saved by admin are displayed by this function
{
	int count=1,balnc;
	char type;
	string name;
	ifstream fin;
	ifstream fin1,fin2;
	fin.open("user.txt");
	fin1.open("balance.txt");
	fin2.open("type.txt");
	cout<<"\tACC.NO\t"<<"NAME"<<"\t"<<"\t"<<"\t"<<"BALANCE"<<"\t\t"<<"ACC.TYPE"<<endl<<endl;
	for(int a=0;a<numoflines();a++)
	{
		getline(fin,name);
		fin1>>balnc;
		fin2>>type;
		if(name!=""){
		cout<<"\t"<<count<<"\t"<<name<<"\t\t\t"<<balnc<<"\t\t"<<type<<endl;
		count++;}}
	}
void delete_acc()//it deletes a user's account. firstly all accounts details are saved in respective arrays and they are again written in file as it was before but the account that we want to delete is skipped while writing using if conditions.
{ 
	int balance[100],choice,lines=numoflines();
	string user[100];
	char typ[100];
	view_all();
	cout<<"Enter a choice\n";
	cin>>choice;
	ifstream fin,fin1,fin2;
	ofstream fout,fout1,fout2;
	fin.open("user.txt");
	fin1.open("type.txt");
	fin2.open("balance.txt");
	for(int a=0;a<lines;a++){
		fin>>user[a];
		fin1>>typ[a];
		fin2>>balance[a];
	}
	fin.close();
	fin1.close();
	fin2.close();
	fout.open("user.txt");
	fout1.open("type.txt");
	fout2.open("balance.txt");
	for(int b=0;b<lines;b++)
	{
		if(b+1!=choice){
			fout<<user[b]<<endl;
			fout1<<typ[b]<<endl;
			fout2<<balance[b]<<endl;
		}
}
	cout<<"Account deleted\n";
}
void modifyaccount(){//it modifies user account details
	view_all();
	int ch,ch1,lines=numoflines();
	string arr[20];
	cout<<"\nEnter a choice\n";
	cin>>ch;
	cin.ignore();
	system("cls");
	cout<<"\n\n1. Change name\n2. Change type\nEnter a choice\n";
	cin>>ch1;
	cin.ignore();
	ifstream fin;
	ofstream fout;
	if(ch1==1){
	fin.open("user.txt");
	cout<<"Enter new name\n";
	for(int a=0;a<lines;a++){
		getline(fin,arr[a]);
		if (a+1==ch){
			getline(cin,arr[a]);
		}
	}
	fin.close();
	fout.open("user.txt");
	for(int b=0;b<lines;b++){
		fout<<arr[b]<<endl;
	}
}
	if(ch1==2){
		fin.open("type.txt");
		cout<<"Enter type of account\n";
	for(int a=0;a<lines;a++){
		getline(fin,arr[a]);
		if (a+1==ch){
			getline(cin,arr[a]);
		}
	}
	fin.close();
	fout.open("type.txt");
	for(int b=0;b<lines;b++){
		fout<<arr[b]<<endl;
	}
	}
	cout<<"Done\n";
}
void funds_transfer(){//ammount for sender is subracted from balance and ammount of reciever is added while saving in file
	int ch,ch2,lines=numoflines(),amm,arr[100];
	view_all();
	cout<<"Enter account number of sender\n";
	cin>>ch;
	cout<<"Enter ammount to send\n";
	cin>>amm;
	cout<<"Enter account number of reciever\n";
	cin>>ch2;
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<lines;a++){
		fin>>arr[a];
	}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<lines;b++){
		if(b+1==ch){
			if(arr[b]-amm<0)
			{cout<<"Your balance is not sufficient\n";
			fout<<arr[b]<<endl;
			}
			else{
				fout<<arr[b]-amm<<endl;
			cout<<"Ammount transferred\n";
			}
		}
		else if(b+1==ch2){
			if(arr[b]-amm>0)
			fout<<arr[b]+amm<<endl;
			else
				fout<<arr[b]<<endl;
		}
		else
		fout<<arr[b]<<endl;
	}
}
void billandshopping(){//this function asks reason to withdraw ammount and then subtracts the ammount
	int ch,lines=numoflines(),amm,arr[100],ch1;
	view_all();
	cout<<"Enter choice\n";
	cin>>ch;
	cout<<"Withdraw ammount for: \n1.Billing\n2.Shopping\n";
	cin>>ch1;
	cout<<"Enter ammount to withdraw\n";
	cin>>amm;
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<lines;a++){
		fin>>arr[a];
	}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<lines;b++){
		if(b+1==ch){
			if(arr[b]-amm>0){
			fout<<arr[b]-amm<<endl;
			cout<<"Ammount withdrawn\n";}
			else
			{cout<<"Your balance is insufficient\n";
			fout<<arr[b]<<endl;}
		}
		else
		fout<<arr[b]<<endl;
	}
}
//END OF ADMIN FUNCTIONS
int passwordexists(string username){// this function checks whether user's password exists or user is logging in first time  
	string pass[100],user[100];
	int c=0;
	ifstream fin,fin1;
	fin1.open("password.txt");
	fin.open("user.txt");
	while(!fin.eof()){
		getline(fin,user[c]);
		getline(fin1,pass[c]);
		c++;
	}
	for(int a=0;a<=c;a++){
		if(username==user[a]){
			if(pass[a]=="")
				return 0;
			else
				return 1;
		}
	}
}
void user_menu(int &res){//thos function displays user's menu
	system("cls");
	string username;
	int choice;
	ifstream fin;
	fin.open("user.txt");
	for(int a=0;a!=res;a++){
		getline(fin,username);
	}
	cout<<"\nWELCOME "<<username<<endl<<endl;
	cout<<"1. Deposit ammount\n2. Withdraw ammount\n3. Modify account PIN\n4\. Funds Transfer\n5. Use Account to pay Bills/Shoping\n6. Logout\n\nENTER A CHOICE\n";
	cin>>choice;
	cin.ignore();
	switch (choice){
	case 1:
		user_deposit(res);
		getch();
		user_menu(res);
	case 2:
		user_withdraw(res);
		getch();
		user_menu(res);
	case 3:
		user_modify(res);
		getch();
		user_menu(res);
	case 4:
		user_funds(res);
		getch();
		user_menu(res);
	case 5:
		user_billshopping(res);
	case 6:
		welcome(username);
	}}
void user_deposit(int &res){//this function adds ammount in user's balance 
	system("cls");
	int amm;
	cout<<"\n\nEnter ammount to deposit: ";
	cin>>amm;
	int arr[100];
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<numoflines();a++){
		fin>>arr[a];}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<numoflines();b++){
		if(b==res-1){
			fout<<arr[b]+amm<<endl;}
		else
			fout<<arr[b]<<endl;
	}
	cout<<"Ammount deposited\n";
}
void user_withdraw(int &res){//this function subtracts ammount from user's balance. int &res is returned from login function and it tells acout the line in the file where a specific user is located. 
system("cls");
	int amm;
	cout<<"\n\nEnter ammount to withdaraw: ";
	cin>>amm;
	int arr[100];
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<numoflines();a++){
		fin>>arr[a];}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<numoflines();b++){
		if(b==res-1){
			if(arr[b]-amm<0){
				cout<<"Your balance is not sufficient\n";
				fout<<arr[b]<<endl;
			}
			else{
			fout<<arr[b]-amm<<endl;
			cout<<"Ammount withdrawn\n";
			}}
		else
			fout<<arr[b]<<endl;
	}
	}
void user_modify(int &res){//it finds the line of file where user is located by &res and then modify the information from file
	system("cls");
string pass[100];
string newpass;
cout<<"Enter new password: ";
getline(cin,newpass);
	ifstream fin;
	fin.open("password.txt");
	for(int a=0;a<numoflines();a++){
		fin>>pass[a];}
	fin.close();
	ofstream fout;
	fout.open("password.txt");
	for(int b=0;b<numoflines();b++){
		if(b==res-1){
			fout<<newpass<<endl;}
		else
			fout<<pass[b]<<endl;
	}
	cout<<"Password updated\n";
}
void user_funds(int &res){//it subtracts ammount from user's balance and then add it to sender's balance
	system("cls");
	int amm,currentamm,racc,balance[100];
	cout<<"Enter the amount: ";
	cin>>amm;
	view_all();
	cout<<"\nEnter account no of reciever\n";
	cin>>racc;
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<numoflines();a++){
		fin>>balance[a];}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<numoflines();b++)
	{
		if (b==res-1){
			if(balance[b]-amm<0){
				cout<<"Your balance is not sufficient\n";
				fout<<balance[b]<<endl;}
			else
			{fout<<balance[b]-amm<<endl;
			cout<<"Ammount transfered\n";}
		}
		if(b+1==racc){
			if(balance[b]-amm>0)
			fout<<balance[b]+amm<<endl;
		else
			fout<<balance[b]<<endl;
		}
		else
			fout<<balance[b]<<endl;}
}
void user_billshopping(int &res){//it asks for choice and then subtracts the ammount
	system("cls");
	int amm,ch;
	cout<<"\n\nEnter ammount to withdaraw: ";
	cin>>amm;
	cout<<"\n\n1. For bills\n2. For shopping\n\nEnter a choice:\n";
	cin>>ch;
	int arr[100];
	ifstream fin;
	fin.open("balance.txt");
	for(int a=0;a<numoflines();a++){
		fin>>arr[a];}
	fin.close();
	ofstream fout;
	fout.open("balance.txt");
	for(int b=0;b<numoflines();b++){
		if(b==res-1){
			if(arr[b]-amm<0){
				cout<<"Your balance is not sufficient\n";
				fout<<arr[b]<<endl;
			}
			else{
			fout<<arr[b]-amm<<endl;
			cout<<"Ammount withdrawn\n";
		}}}}
