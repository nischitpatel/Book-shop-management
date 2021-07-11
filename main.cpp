//Book shop management system
#include<iostream>
#include<conio.h>
#include "files/headerFiles/BookShop.h"
using namespace std;

int main(){
	int choice;
	BookShop b;
	while(1){
		b.mainMenu();
		cout<<"\n\n\t\t\t\t\tEnter your choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				char another;
				do{
					b.addBook();
					cout<<"\nDo you want to add another ? [y/n] : ";
					cin>>another;
				}while(another!= 'n');
				break;
			case 2:
				b.dltBook();
				break;
			case 3:
				b.displayBooks();
				break;
			case 4:
				b.updateBook();
				break;
			case 5:
				b.searchBook();
				break;
			case 6:
				exit(0);
			default:
				cout<<"\nInvalid choice !";
		}
		cout<<"\nPress any key to go back to main menu !";
		getch();
	}
	return 0;
}
