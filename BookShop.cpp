#include "files/headerFiles/BookShop.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
using namespace std;

void BookShop::mainMenu(){
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t\t\t*********** MAIN MENU ***********"<<endl;
	cout<<"\t\t\t\t\t---------------------------------"<<endl<<endl;
	cout<<"\t\t\t\t\t[1.]	ADD A BOOK"<<endl;
	cout<<"\t\t\t\t\t[2.]	DELETE A BOOK"<<endl;
	cout<<"\t\t\t\t\t[3.]	DISPLAY BOOKS"<<endl;
	cout<<"\t\t\t\t\t[4.]	UPDATE A BOOK"<<endl;
	cout<<"\t\t\t\t\t[5.]	SEARCH A BOOK"<<endl;
	cout<<"\t\t\t\t\t[6.]	EXIT"<<endl;
}

void BookShop::addBook(){
	system("cls");
	int total_books;
	string book_name, author_name, book_id;
	fstream books;
	cout<<"\n\n\n\n\n\t\t\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\t\t\t*********** ADD NEW BOOK ***********"<<endl;
	cout<<"\t\t\t\t\t------------------------------------"<<endl<<endl;
	cout<<"\t\t\t\t\tEnter Book's Name : ";
	cin>>book_name;
	cout<<"\n\t\t\t\t\tEnter Book's ID : ";
	cin>>book_id;
	cout<<"\n\t\t\t\t\tEnter Author's Name : ";
	cin>>author_name;
	cout<<"\n\t\t\t\t\tEnter Total Number of Books : ";
	cin>>total_books;
	books.open("files/books.txt", ios::out | ios::app);
	books<<"\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<total_books<<"\n";
	books.close();
}

void BookShop::dltBook(){
	system("cls");
	fstream books, newfile;
	int total_books;
	bool flag=0;
	string book_name, author_name, book_id, check_id;
	books.open("files/books.txt", ios::in);
	if(!books){
		cout<<"\nFile opening error !";
	}
	else{
		newfile.open("files/newfile.txt",ios::out | ios::app);
		cout<<"\n\n\t\t\t ---------------------------------------------------------------------";
		cout<<"\n\t\t\t *************************** DELETE A BOOK ***************************"<<endl;
		cout<<"\t\t\t ---------------------------------------------------------------------"<<endl;
		cout<<"\n\t\t\tEnter ID of a book you want to delete : ";
		cin>>check_id;
		books>>book_id>>book_name>>author_name>>total_books;
		while(!books.eof()){
			
			if(book_id == check_id){
				flag=1;
				cout<<"\n\n\n\n\t\t\t\t\t******** BOOK DELETED SUCCESSFULLY ! **********"<<endl;
			}
			else{
				newfile<<"\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<total_books<<"\n";	
			}
			books>>book_id>>book_name>>author_name>>total_books;
		}
		if(!flag){
			cout<<"\n\n\n\n\t\t\t\t\t******** BOOK ID NOT FOUND ! **********"<<endl;
		}
	}
	newfile.close();
	books.close();
	remove("files/books.txt");
	rename("files/newfile.txt", "C://Users/np588/OneDrive/Desktop/C++/Projects/files/books.txt");
}


void BookShop::displayBooks(){
	system("cls");
	fstream books;
	int total_books;
	string book_name, author_name, book_id;
	books.open("files/books.txt", ios::in);
	if(!books){
		cout<<"\nFile opening error !";
	}
	else{
		cout<<"\n\n\t\t\t ---------------------------------------------------------------------";
		cout<<"\n\t\t\t *************************** BOOKS DETAILS ***************************"<<endl;
		cout<<"\t\t\t ---------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t"<<setw(15)<<"BOOK ID"<<setw(15)<<"BOOK NAME"<<setw(15)<<"AUTHOR NAME"<<setw(15)<<"QUANTITY"<<endl;
		cout<<"\t\t\t ---------------------------------------------------------------------"<<endl;
		books>>book_id>>book_name>>author_name>>total_books;
		while(!books.eof()){
			cout<<"\n\t\t\t"<<setw(15)<<book_id<<setw(15)<<book_name<<setw(15)<<author_name<<setw(15)<<total_books<<endl;
			books>>book_id>>book_name>>author_name>>total_books;
		}
	}
	books.close();
}

void BookShop::updateBook(){
	fstream books, newfile;
	bool flag=0;
	system("cls");
	int total_books;
	string book_name, author_name, book_id, check_id;
	books.open("files/books.txt", ios::in);
	if(!books){
		cout<<"\nFile opening error !";
	}
	else{
		newfile.open("files/newfile.txt",ios::out | ios::app);
		cout<<"\n\n\t\t--------------------------------------------------";
		cout<<"\n\t\t*************** UPDATE A BOOK ********************"<<endl;
		cout<<"\n\t\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tEnter ID of a book you want to update : ";
		cin>>check_id;
		books>>book_id>>book_name>>author_name>>total_books;
		while(!books.eof()){
			
			if(book_id == check_id){
				system("cls");
				cout<<"\n\t\t*************** UPDATE A BOOK ********************"<<endl;
				cout<<"\t\t--------------------------------------------------"<<endl;
				cout<<"\t\tEnter updated name of a book : ";
				cin>>book_name;
				cout<<"\t\tEnter updated name of author : ";
				cin>>author_name;
				cout<<"\t\tEnter updated quantity of books : ";
				cin>>total_books;
				newfile<<"\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<total_books<<"\n";
				flag=1;
			}
			else{
				newfile<<"\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<total_books<<"\n";	
			}
			books>>book_id>>book_name>>author_name>>total_books;
		}
		if(!flag){
			cout<<"\n\n\n\n\t\t\t\t\t******** BOOK ID NOT FOUND ! **********"<<endl;
		}
	}
	newfile.close();
	books.close();
	remove("files/books.txt");
	rename("files/newfile.txt", "files/books.txt");
}

void BookShop::searchBook(){
	string book_name, author_name, book_id, check_id;
	bool flag=0;
	int total_books;
	system("cls");
	fstream books;
	books.open("files/books.txt", ios::in);
	if(!books){
		cout<<"\n\t\tFile opening error !";
	}
	else{
		cout<<"\n\n\n\n\t\t\t-------------------------------------------------------------"<<endl;
		cout<<"\t\t\t*************** SEARCH A BOOK BY IT'S ID ********************"<<endl;
		cout<<"\t\t\t-------------------------------------------------------------"<<endl;
		cout<<"\n\t\t\tEnter ID of a book you want to check : ";
		cin>>check_id;
		while(!books.eof()){
			books>>book_id>>book_name>>author_name>>total_books;
			if(check_id == book_id){
				system("cls");
				cout<<"\n\n\n\n\t\t\t\t\t******** BOOK FOUND ! ********";
				flag = 1;
				cout<<"\n\n\t\t\t\t\tBook ID :"<<book_id<<"\n\t\t\t\t\tBook Name : "<<book_name<<"\n\t\t\t\t\tAuthor Name : "<<author_name<<"\n\t\t\t\t\tTotal Books : "<<total_books<<endl;
			}
		}
	}
	books.close();
	if(!flag){
		cout<<"\n\n\n\n\t\t\t\t\t***** BOOK DOES NOT EXIST ! *****"<<endl;
	}
}
