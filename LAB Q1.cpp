// lab 3 Q1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<fstream>;
#include"gitHubUser.h";
#include<iostream>;
using namespace std;

void readDataFromFile(gitHubUser * &users, string filepath, int &user_count){
	ifstream fin("C:\\Users\\Moeed\\Desktop\\file.txt");
	if (fin.fail()){
		cout << "Could not open file!!" << endl;			//error message in case file is not accessible
	}
	else{
		char temp[50];
		fin.getline(temp, 50);
		user_count = temp[0] - 48;      //taking user count from file
		users = new gitHubUser[user_count];					//making a dynamic array of gitHubUser structs 
		for (int i = 0; i<user_count; i++){
			fin.getline(temp, 50);
			users[i].firstName = temp;
			fin.getline(temp, 50);
			users[i].userName = temp;
			fin.getline(temp, 50);
			users[i].email = temp;
			fin.getline(temp, 50);
			int files = atoi(temp);
			users[i].gitHubFolders = new string[files];
			for (int j = 0; j<files; j++){						//storing the file names from file
				fin.getline(temp, 50);
				users[i].gitHubFolders[j] = temp;
			}
		}
		for (int i = 0; i < user_count; i++){					//initializing the struct string pointers to null pointer
			users[i].institute_name = nullptr;
			users[i].qualification_level = nullptr;
		}
	}

}
void setEduBckGrnd(gitHubUser &user){
	cout << user.firstName << " enter your institution name : ";
	user.institute_name = new string[1];					//creating an array of strings of size 1
	cin >> user.institute_name[0];
	cout << user.firstName << " enter your level of qualification : ";
	user.qualification_level = new string[1];					//creating an array of strings of size 1
	cin >> user.qualification_level[0];
}
void print(gitHubUser &user){
	cout << " First Name : " << user.firstName << endl;
	cout << " User Name : " << user.userName << endl;
	cout << " E-mail : " << user.email << endl;
	if (user.institute_name != nullptr){
		cout << " Institution Name : " << user.institute_name[0] << endl;
	}
	if (user.qualification_level != nullptr){
		cout << " Level of Qualification : " << user.qualification_level[0] << endl;
	}
}
void Remove(gitHubUser &user){
	delete[]user.institute_name;
	user.institute_name = nullptr;
	delete[]user.qualification_level;
	user.qualification_level = nullptr;
}
void Backup(gitHubUser *originalArry, gitHubUser *&backupArry, int userCount){
	backupArry = new gitHubUser[userCount];
	for (int i = 0; i<userCount; i++){
		backupArry[i].firstName = originalArry[i].firstName;
		backupArry[i].userName = originalArry[i].userName;
		backupArry[i].email = originalArry[i].email;
		backupArry[i].password = originalArry[i].password;
		backupArry[i].institute_name = new string[0];
		backupArry[i].qualification_level = new string[0];
		backupArry[i].institute_name[0] = originalArry[i].institute_name[0];
		backupArry[i].qualification_level[0] = originalArry[i].qualification_level[0];
		backupArry[i].folderCount = originalArry[i].folderCount;
	}
}
void menu(gitHubUser* &users, gitHubUser* &backup, int &user_count){
	int temp;														//the function is in an infinite loop as it is being called in itself
	cout << "1 : set education background" << endl;
	cout << "2 : print user" << endl;
	cout << "3 : remove user" << endl;
	cout << "4 : back up user" << endl;
	cin >> temp;
	switch (temp){
	case(1) :
		setEduBckGrnd(users[0]);
		system("cls");
		menu(users, backup, user_count);
		break;
	case(2) :
		system("cls");
		print(users[0]);
		system("pause");
		system("cls");
		menu(users, backup, user_count);
		break;
	case(3) :
		system("cls");
		Remove(users[0]);
		menu(users, backup, user_count);
		break;
	case(4) :
		Backup(users, backup, user_count);
		system("cls");
		menu(users, backup, user_count);
		break;
	default:
		break;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	gitHubUser* users;
	gitHubUser* backup;
	string filepath;
	int user_count;
	readDataFromFile(users, filepath, user_count);
	menu(users, backup, user_count);
	return 0;
}

