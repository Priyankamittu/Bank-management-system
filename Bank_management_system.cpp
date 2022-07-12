#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
class account{
	private:
		string password,username;
		string password1,username1;
		int total;
		struct user{
			string name,email,ID;
			int contact,cash;
		}user[100];
	public:
		account(){
			total=0;
		}
		void choice();
		void start();
		void signUp();
		void login();
		void Data();
		void show();
		void update();
		void search();
		void transactions();
		void del();
};
main(){
	account b;
	b.start();
	b.signUp();
	b.login();
}
void account::choice(){
	char ch;
	while(true){
   	cout<<"\n\n  Welcome to Bank management system\nPRESS..!!"<<endl;
	cout<<"1. Create new account"<<endl;
	cout<<"2. View customers list"<<endl;
	cout<<"3. Update information of existing account"<<endl;
	cout<<"4. Check the details of an existing account"<<endl;
	cout<<"5. For transactions"<<endl;
	cout<<"6. Remove existing account"<<endl;
	cout<<"7. Exit"<<endl;
	ch=getch();
	system("ClS");
	switch(ch){
		case '1':
			account::Data();
			break;
		case '2':
			account::show();
			break;
		case '3':
			account::update();
			break;
		case '4':
			account::search();
			break;
		case '5':
			account::transactions();
			break;
		case '6':
			account::del();
			break;
		case '7':
			exit(0);
			break;
		default:
			cout<<"\aInvalid input"<<endl;
	        break;
	}
    }
}
void account::start(){
			char arr[]={'B','A','N','K',' ','M','A','N','A','G','E','M','E'
			,'N','T',' ','S','Y','S','T','E','M'};
			cout<<"\n\n\n\n\n\t\t\t";
			for(int i=0;i<24;i++){
				cout<<arr[i];
				Sleep(30);
			}
			Sleep(1000);
			system("CLS");
		}
		void account::signUp(){
			cout<<"\n\n\t\t\t\t\t\tWelcome to Bank Management System"<<endl;
			cout<<"\n\t\t  Please SIGN UP"<<endl;
			cout<<"\t\tEnter Username: ";
			cin>>username;
			cout<<"\t\tEnter Password: ";
			cin>>password;
			cout<<"\t\tYour new id is creating please wait";
			for(int i=0;i<5;i++){
				cout<<".";
				Sleep(100);
			}
		}
		void account::login(){
			system("CLS");
			cout<<"\n\n\t\t LOGIN"<<endl;
			cout<<"\t\tEnter Username: ";
			cin>>username1;
			cout<<"\t\tEnter Password: ";
			cin>>password1;
			if(username==username1&&password==password1){
				system("CLS");
				account::choice();
			}
			else if(username!=username1&&password==password1){
				cout<<"\t\t\aPlease enter valid username!!";
				Sleep(3000);
				account::login();
			}
			else if(username==username1&&password!=password1){
				cout<<"\t\t\aPlease enter valid password!!";
				Sleep(3000);
				account::login();
			}
			else{
				cout<<"\t\t\aUsername and password is invalid !! Please try again!!";
				Sleep(3000);
				account::login();
			}
		}
		void account::Data(){
			cout<<"\nFill in the respective details of the user:"<<endl<<endl;
			cout<<"Enter Name: ";
			cin>>user[total].name;
			cout<<"Enter ID: ";
			cin>>user[total].ID;
			cout<<"Enter Contact: ";
			cin>>user[total].contact;
			cout<<"Enter Email: ";
			cin>>user[total].email;
			cout<<"Enter Cash: ";
			cin>>user[total].cash;
			total++;
		}
		void account::show(){
			for(int i=0;i<total;i++){
				cout<<"\nData of the user "<<i+1<<endl;
				cout<<"Name: "<<user[i].name<<endl;
				cout<<"ID: "<<user[i].ID<<endl;
				cout<<"Contact: "<<user[i].contact<<endl;
				cout<<"Email: "<<user[i].email<<endl;
				cout<<"Cash: "<<user[i].cash<<endl;
			}
		}
		void account::update(){
			string id;
			cout<<"Enter ID of user whose details are to be updated"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==user[i].ID){
				cout<<"\nPrevious data of user "<<i+1<<endl;
				cout<<"Name: "<<user[i].name<<endl;
				cout<<"ID: "<<user[i].ID<<endl;
				cout<<"Contact: "<<user[i].contact<<endl;
				cout<<"Email: "<<user[i].email<<endl;
				cout<<"Cash: "<<user[i].cash<<endl;
				cout<<"\nEnter new data"<<endl<<endl;
				cout<<"Enter Name: ";
			cin>>user[i].name;
			cout<<"Enter ID: ";
			cin>>user[i].ID;
			cout<<"Enter Contact: ";
			cin>>user[i].contact;
			cout<<"Enter Email: ";
			cin>>user[i].email;
			cout<<"Enter Cash: ";
			cin>>user[i].cash;
			cout<<"Your required data is updated"<<endl;
			break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void account::search(){
			string id;
			cout<<"Enter ID of user for check"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==user[i].ID){
				cout<<"\nData of user "<<i+1<<endl;
				cout<<"Name: "<<user[i].name<<endl;
				cout<<"ID: "<<user[i].ID<<endl;
				cout<<"Contact: "<<user[i].contact<<endl;
				cout<<"Email: "<<user[i].email<<endl;
				cout<<"Cash: "<<user[i].cash<<endl;
				break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void account::transactions(){
			string id;
			char ch;
			int cash;
			cout<<"Enter id of user in which you want transactions to be done"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==user[i].ID){
					cout<<"Name: "<<user[i].name<<endl;
			     	cout<<"ID: "<<user[i].ID<<endl;
			    	cout<<"Contact: "<<user[i].contact<<endl;
				    cout<<"Email: "<<user[i].email<<endl;
					cout<<"\nExisting Cash "<<user[i].cash<<endl;
				    cout<<"\nPress 1 to deposit cash"<<endl;
				    cout<<"Press 2 to withdraw cash"<<endl;
				    ch=getch();
				    switch(ch){
				    	case '1':
				    		cout<<"Enter the amount of cash to be deposited"<<endl;
				    		cin>>cash;
				    		user[i].cash+=cash;
				    		cout<<"Your Balance after transaction is "<<user[i].cash<<endl;
				    		break;
				    	case '2':
				    		back:
				    		cout<<"Enter the amount of cash to be withdrawn"<<endl;
				    		cin>>cash;
				    		if(cash>user[i].cash){
				    			cout<<"Your existing balance is just "<<user[i].cash<<endl;
				    			Sleep(3000);
								goto back;
							}
				    		user[i].cash-=cash;
				    		cout<<"New amount is "<<user[i].cash<<endl;
				    		break;
				    	default:
				    		cout<<"\aInvalid Input"<<endl;
				    		break;
					}
					break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void account::del(){
				if(total!=0){
				char ch;
				cout<<"Press 1 to remove specific record"<<endl;
				cout<<"Press 2 to remove full record"<<endl;
				ch=getch();
				if(ch=='1'){
						string id;
						cout<<"Enter id of user to be removed"<<endl;
						cin>>id;
						for(int i=0;i<total;i++){
							if(id==user[i].ID){
								for(int j=i;j<total;j++){
									user[j].name=user[j+1].name;
									user[j].ID=user[j+1].ID;
									user[j].email=user[j+1].email;
									user[j].contact=user[j+1].contact;
									user[j].cash=user[j+1].cash;
									total--;
									cout<<"Your required record is deleted"<<endl;
									break;
								}
							}
							if(i==total-1){
				         	cout<<"No such record found"<<endl;
				            }
						}
		         	}
		         	else if(ch=='2'){
		         		total=0;
		         		cout<<"All record is deleted"<<endl;
					 }
					 else{
					 	cout<<"\aInvalid Input"<<endl;
					 }
						
				}
			
			else{
				cout<<"No data is entered"<<endl;
			}
		}
		
