#include <iostream>
#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <istream>  // Needed for string stream objects
#include <sstream>   // Needed for strings
#include <iterator>  // iteration through streams and lists
#include <list>
#include "StudentRecord.h"
#include "DataBase.h"
#include "dbDriver.h"

namespace whnkud001
{
	// clear method to clear the screen...
	void clear(void) 
	{
		std::cout << std::string(100,'\n');
	}
	// add a student with the given data to the database
	void addStudent(std::string name, std::string surname, std::string stdnum, std::string rec)
	{
		if ( myDB.checkUnique(stdnum) )
		{ /* do nothing*/}
		else
		{
			// first delete the old student
			myDB.deleteStd(stdnum) ;
		}
		// create new student with new token and insert into DB
		StudentRecord newStd(name, surname, stdnum, rec) ;
		myDB.insertStd(newStd) ;
	}
	
	void deleteStudent(std::string stdnum)
	{
		myDB.deleteStd(stdnum) ;
	}
	
	void readStudentData(std::string stdnum)
	{
		myDB.printStudent(stdnum) ;
	}
	
	void gradeStudent(std::string stdnum)
	{
		std::cout << stdnum << " : " ;
		myDB.gradeStudent(stdnum) ;
	}
	/*
	void exit()
	{
		std::string ans ;
		std::cin >> ans ;
		
		if ( 
	}
	*/
}

int main(void)
{	
	using namespace std ;
	using namespace whnkud001 ;
	
	// implement command line parsing and extract filename
	string filename = "records.txt";

	// Open file with a file stream. ifstream constructor
	// wants a C char * string, so call c_str() method.
	ifstream in(filename.c_str());

	if(!in)
		{ cout << "Couldn't open " << filename << endl; }
	
	
	// Extract the lines from the file
	string aline;
	
	while ( getline(in, aline) )
	{
		istringstream myStream(aline) ; // create a stringStream with the current line as it's element
		
		while(!myStream.eof())
		{
			// Code to retrieve data on textfile and place it in a list...
		}		
	}
	
	bool running = true ;
	
	// while the program runs
	while ( running == true )
	{
		cout << "1: Add Student" << endl << "2: Delete student" << endl;
		cout << "3: Read database" << endl << "4: Save database" << endl;
		cout << "5: Display student data" << endl << "6: Grade student" << endl;
		cout << "7: Display all student data" << endl;
		cout << "8: Find winning student" << endl << "q: Quit" << endl ;
		cout << "Enter a number (or q to quit) and press return..." << endl;
		
		string query; // string to represent users choice
		cin >> query; // extraction of user choice from stream to query variable
		
		if ( query.compare("q") == 0 || query.compare("Q") == 0 )
		{
			running = false;
			break ;
		}
		else if ( query.compare("1") == 0 )
		{
			string nm, snm, stdnum, rec;
			
			cout << "enter name : \n" ; cin >> nm ;
			cout << "enter surname : \n" ; cin >> snm ;
			cout << "enter student number : \n" ; cin >> stdnum ;
			cout << "enter student record : \n" ; cin >> rec ;
			
			addStudent(nm, snm, stdnum, rec) ;
		}
		else if ( query.compare("2") == 0 )
		{
			string stdnum;
			cout << "enter student number : \n" ; cin >> stdnum ;
			
			deleteStudent(stdnum) ;
		}
		else if ( query.compare("3") == 0 )
		{
			string stdnum;
			cout << "enter student number : \n" ; cin >> stdnum ;
			readStudentData(stdnum) ;
		}
		else if ( query.compare("4") == 0 )
		{
			if ( myDB.save(filename) )
			{
				cout << "   Saved ! " << endl ;
			}
			else
			{
				cout << "Error! Failed to open DataBase, files not saved ! " << endl ;
			}
		}
		else if ( query.compare("5") == 0 )
		{
			// read from textfile again to refresh values to last save
		}
		else if ( query.compare("6") == 0 )
		{
			string stdnum;
			cout << "enter student number : \n" ; cin >> stdnum ;
			
			gradeStudent(stdnum) ;
		}
		else if ( query.compare("7") == 0 )
		{
			myDB.displayAll() ;
		}
		else if ( query.compare("8") == 0 )
		{
			// winner
		}
		else
		{
			clear() ; // clear the screen
		}
	}
	
	in.close();
}
