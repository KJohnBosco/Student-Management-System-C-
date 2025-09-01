#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "SMS.h"
using namespace std;

class Student{
	public:
		string Name1, Name2, Reg_number, Course, Program;
		int Semester, Year;
		
};

//	Main menu function
void Menu(){
	int choice;
	system("cls");
	Start:
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\t|	STUDENT MANAGEMENT SYSTEM	|"<<endl;
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\t1. Add New Student"<<endl;
	cout<<"\t\t2. Search Student Details"<<endl;
	cout<<"\t\t3. Modify Student Details"<<endl;
	cout<<"\t\t4. Remove Student"<<endl;
	cout<<"\t\t5. Display All Students"<<endl;
	cout<<"\t\t6. Exit"<<endl;
	cout<<"\t\t___________________________________________"<<endl;
	cout<<"\t\t   Choose from the options:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t==========================================="<<endl;
	cout<<"\t\t";
	cin>>choice;
	
	// Error handling
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout<<"\t\tInvalid input! Choose from the provided options..."<<endl;
		goto Start;
	}
	
	switch(choice){
		case 1:
			// Case to add Student
			char input;
			do{
				Add_Student();
				Redirect1:
				cout<<"\n\t\tDo you want to add another student?[Y/N]"<<endl;
				cout<<"\t\t";
				cin>>input;
				
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"\t\tInvalid input!"<<endl;
					goto Redirect1;
				}
				
				if(input == 'N' || input == 'n'){
					Menu();
				}
				else if(input != 'Y' || input != 'y'){
					Add_Student();
				}
				else{
					cout<<"\t\tInvalid input!"<<endl;
					goto Redirect1;
				}
			}while(input == 'Y' || input == 'y');
			break;
		case 2:
			// Case to search for student
			do{
				Search_Student_Details();
				Redirect2:
				cout<<"\n\t\tDo you want to search for another student?[Y/N]"<<endl;
				cout<<"\t\t";
				cin>>input;
				
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Invalid input!"<<endl;
					goto Redirect2;
				}
				
				if(input == 'N' || input == 'n'){
					Menu();
				}
				else if(input != 'Y' || input != 'y'){
					Search_Student_Details();
				}
				else{
					cout<<"\t\tInvalid input!"<<endl;
					goto Redirect2;
				}
				
			}while(input == 'Y' || input == 'y');
			break;
		case 3:
			// Case to modify student details
			do{
				Modify_Student_Details();
				Redirect3:
				cout<<"\n\t\tDo you want to modify another student detail?[Y/N]"<<endl;
				cout<<"\t\t";
				cin>>input;
				
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Invalid input!"<<endl;
					goto Redirect3;
				}
				
				if(input == 'N' || input == 'n'){
					Menu();
				}
				else if(input != 'Y' || input != 'y'){
					cout<<"\t\tInvalid input!"<<endl;
					goto Redirect3;
				}
				
			}while(input == 'Y' || input == 'y');
			break;
		case 4:
			// Case to remove student from the record
			do{
				Remove_Student();
				Redirect4:
				cout<<"\n\t\tDo you want to remove another student?[Y/N]"<<endl;
				cout<<"\t\t";
				cin>>input;
				
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Invalid input!"<<endl;
					goto Redirect4;
				}
				
				if(input == 'N' || input == 'n'){
					Menu();
				}
				else if(input != 'Y' || input != 'y'){
					Remove_Student;
				}
				else{
					cout<<"\t\tInvalid input!"<<endl;
					goto Redirect4;
				}
				
			}while(input == 'Y' || input == 'y');
			break;
		case 5:
			// Case to display all students
			do{
				Reflesh:
				Display_Students();
				Redirect5:
				cout<<"\n\t\tDo you want to reflesh the above list?[Y/N]"<<endl;
				cout<<"\t\t";
				cin>>input;
				
				if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<"Invalid input!"<<endl;
					goto Redirect5;
				}
				
				if(input == 'N' || input == 'n'){
					Menu();
				}
				else if(input != 'Y' || input != 'y'){
					cout<<"\t\tRefleshing....."<<endl;
					goto Reflesh;
				}
				else{
					cout<<"\t\tInvalid input!"<<endl;
					goto Redirect5;
				}
				
			}while(input == 'Y' || input == 'y');
			break;
		case 6:
			// Case, exit opt
			system("cls");
			cout<<"\t\tExiting......"<<endl;
			exit(0);
			break;
		default:
			// Default case
			cout<<"\t\tInvalid input! Please retry"<<endl;
			Menu();
			break;
	}
	
}

// Add a new student record
void Add_Student(){
		Student student;
	system("cls");
	Add:
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\t|	ADD NEW STUDENT IN RECORD	|"<<endl;
	cout<<"\t\t========================================="<<endl;
	// Fetch Student details
	cout<<"\t\tEnter Student name:[Only two names allowed]\n\t\t";
	cin>>student.Name1>>student.Name2;
	cout<<"\n\t\tEnter Student Registration number:\n\t\t";
	cin>>student.Reg_number;
	cout<<"\n\t\tEnter Student's course:\n\t\t";
	cin>>student.Course;
	cout<<"\n\t\tEnter Student's program:[Day/Weekend]\n\t\t";
	cin>>student.Program;
	cout<<"\n\t\tEnter academic semester:\n\t\t";
	cin>>student.Semester;
	cout<<"\n\t\tEnter academic year:\n\t\t";
	cin>>student.Year;
	// Store student details
	fstream Record;
	Record.open("Student_Records.txt", ios::app | ios::out);
	if(Record.is_open()){
		Record<<student.Reg_number<<endl;
		Record<<student.Name1<<" "<<student.Name2<<endl;
		Record<<student.Course<<endl;
		Record<<student.Program<<endl;
		Record<<student.Semester<<endl;
		Record<<student.Year<<endl;
		Record<<"\n"<<endl;
		cout<<"\t\tAdded successfully"<<endl;
	}
	else{
		cout<<"\t\tFailed to add student!..."<<endl;
		cout<<"\t\tPlease try again..."<<endl;
		system("cls");
		goto Add;
	}
	Record.close();
}

// Delete student details from the record
void Remove_Student(){
	int iter = 0;
	bool Delete = false;
	bool Found = false;
	string RegNumber, line;
	Student student;
	system("cls");
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\t|	REMOVE STUDENT FROM RECORD	|"<<endl;
	cout<<"\t\t========================================="<<endl;
	Remove:
	cout<<"\t\tEnter student registration number:"<<endl;
	cout<<"\t\t";
	cin>>RegNumber;
	cout<<endl;
	
//	Search and remove student record from the system
	ifstream Record("Student_Records.txt");
	ofstream Temp("Temp.txt");
		if(Record.is_open()){
		while(getline(Record, line)/* && iter != 6*/){
			if(line != RegNumber && Delete != true){
				Temp<<line<<endl;
			}
			else if(line == RegNumber && Delete != true){
				iter+=1;
				Delete = true;
				Found = true;
				continue;
			}
			else if(line != RegNumber && Delete != false && iter != 6){
				iter+=1;
				Delete = true;
				continue;
			}
			
			if(iter == 6){
				Delete = false;
			}
		}
		/* When Registration number was not found*/
		if(Found != true){
			cout<<"\n\t\tStudent Record not found!!"<<endl;
			cout<<"\t\tCheck your registration number and try again!!"<<endl;
		}
		else{
			cout<<"\t\tRecord removed successfully!!"<<endl;
		}
	}

	else{
		cout<<"\t\tFailed to access the database!"<<endl;
		cout<<"\t\tPlease try again!"<<endl;
		system("cls");
		goto Remove;
	}
	Record.close();
	Temp.close();
	remove("Student_Records.txt");
	rename("Temp.txt", "Student_Records.txt");
}

// Search for a student in the record
void Search_Student_Details(){
	Student student;
	int iter = 0;
	bool print = false;
	string FindStudent_RegNo, line;
	system("cls");
	Find:
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\t|	SEARCH STUDENT IN RECORD	 |"<<endl;
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\tEnter student registration number:"<<endl;
	cout<<"\t\t";
	cin>>FindStudent_RegNo;
	cout<<endl;
	
//	Search for the record
	fstream Record;
	Record.open("Student_Records.txt", ios::in);
	if(Record.is_open()){
		while(getline(Record, line) && iter != 6){
			if(line == FindStudent_RegNo){
				print = true;
			}
			else if(line != FindStudent_RegNo && print != true){
				continue;
			}
			
			if(print = true){
				cout<<"\t\t"<<line<<endl;
				iter+=1;
			}
			else{
				continue;
			}
		}
		/* When Registration number was not found*/
		if(print != true){
			cout<<"\n\t\tRegistration number not found!!"<<endl;
			cout<<"\t\tCheck your registration number and try again!!"<<endl;
		}
	}
	else{
		cout<<"\t\tFailed to access the database!"<<endl;
		cout<<"\t\tPlease try again!"<<endl;
		system("cls");
		goto Find;
	}
}

// Change student details in the record
void Modify_Student_Details(){
	Student student;
	int iter = 0;
	bool Delete = false;
	bool Found = false;
	string line;
	system("cls");
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\t|    MODIFY STUDENT'S DETAIL RECORDS   |"<<endl;
	cout<<"\t\t========================================="<<endl;
	MODIFY:
	cout<<"\t\tEnter student Registration Number:\n\t\t";
	cin>>student.Reg_number;
	
//	Search for the record. If not found, report error. If found, delete it for replacement
	ifstream Record("Student_Records.txt");
	ofstream Temp("Temp.txt");
		if(Record.is_open()){
		while(getline(Record, line)/* && iter != 6*/){
			if(line != student.Reg_number && Delete != true){
				Temp<<line<<endl;
			}
			else if(line == student.Reg_number && Delete != true){
				iter+=1;
				Delete = true;
				Found = true;
				continue;
			}
			else if(line != student.Reg_number && Delete != false && iter != 6){
				iter+=1;
				Delete = true;
				continue;
			}
			
			if(iter == 6){
				Delete = false;
				iter = 0;
			}
		}
		/* When Registration number was not found*/
		if(Found != true){
			cout<<"\n\t\tStudent Record not found!!"<<endl;
			cout<<"\t\tCheck your registration number and try again!!"<<endl;
			goto MODIFY;
		}
		else{
			cout<<"\t\tRecord found..."<<endl;
		}
	}

	else{
		cout<<"\t\tFailed to access the database!"<<endl;
		cout<<"\t\tPlease try again!"<<endl;
		system("cls");
		goto MODIFY;
	}
	Record.close();
	Temp.close();
	remove("Student_Records.txt");
	rename("Temp.txt", "Student_Records.txt");
	
//	Add new record(replacing the deleted record)
	cout<<"\t\tConfirm Student Registration number:\n\t\t";
	cin>>student.Reg_number;
	cout<<"\n\t\tEnter Student name:[Only two names allowed]\n\t\t";
	cin>>student.Name1>>student.Name2;
	cout<<"\n\t\tEnter Student's course:\n\t\t";
	cin>>student.Course;
	cout<<"\n\t\tEnter Student's program:[Day/Weekend]\n\t\t";
	cin>>student.Program;
	cout<<"\n\t\tEnter academic semester:\n\t\t";
	cin>>student.Semester;
	cout<<"\n\t\tEnter academic year:\n\t\t";
	cin>>student.Year;
	
	fstream RECORD;
	RECORD.open("Student_Records.txt", ios::out | ios::app);
		RECORD<<student.Reg_number<<endl;
		RECORD<<student.Name1<<" "<<student.Name2<<endl;
		RECORD<<student.Course<<endl;
		RECORD<<student.Program<<endl;
		RECORD<<student.Semester<<endl;
		RECORD<<student.Year<<endl;
		RECORD<<"\n"<<endl;
		cout<<"\t\tDetails modified successfully!..."<<endl;
		
	Record.close();
}

// View all student details in the record
void Display_Students(){
	Student student;
	string line;
	system("cls");
	cout<<"\t\t========================================="<<endl;
	cout<<"\t\t|	ALL STUDENTS' DETAILS IN RECORD |"<<endl;
	cout<<"\t\t========================================="<<endl;
	fstream Record;
	Record.open("Student_Records.txt", ios::in);
	if(Record.is_open()){
		while(getline(Record, line)){
				cout<<"\t\t"<<line<<endl;
		}
	}
	else{
		cout<<"\t\tFailed to access the records!..."<<endl;
	}

}