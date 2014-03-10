#include "StudentRecord.h"
#include <string>
#include "tokenlib.h"
#include "DataBase.h"
#include <list>
#include <iterator>
#include <iostream>
#include <sstream>   // Needed for strings
#include <fstream>

namespace whnkud001
{
	//std::string currentCompare ;
	// constructor
	DataBase::DataBase()
	{
		// init tokenLib
		//tokenlib::initialise_tokens();
		// init_Students 
	}
	
	// Destructor
	DataBase::~DataBase()
	{
		if ( !Students.empty() )
		{
			//release resources
			Students.clear() ;
		}
	}
	
	// Copy constructor
	DataBase::DataBase(const DataBase & other) : Students(other.Students)
	{
		
	}
	
	// Copy assignment operator
	DataBase& DataBase:: operator=(const DataBase & other)
	{
		if (this != &other)
		{
			Students = other.Students ;
		}
		return *this;
	}
	
	// Move Constructor
	DataBase::DataBase(DataBase&& other) : Students(other.Students) 
	{
		other.Students.clear() ;
	}
	// Move assignment operator
	DataBase& DataBase :: operator=(DataBase&& other)
	{
		if (this != &other)
		{	
			// Release resources
			Students.clear() ;
			// Get resources
			//Students = std::move(other.Students) ; ?????????????
			Students = other.Students ;
			// Set other's resources to default
			other.Students.clear() ;
		}
		return *this;
	}
	
	// getter
	std::list<StudentRecord> DataBase::getStudents() { return Students ;}
	// insert
	void DataBase::insertStd(StudentRecord newStd)
	{
		std::list<StudentRecord>::iterator addIt = Students.end() ;
		Students.list::insert(addIt, newStd);
	}
	// delete
	void DataBase::deleteStd(std::string stdNum)
	{
		for ( std::list<StudentRecord>::iterator delIt = Students.begin() ;
			delIt != Students.end() ; ++delIt )
		{
			StudentRecord temp = *delIt ;
			if ( temp.getStudentNumber() == stdNum )
			{
				Students.erase(delIt) ;
			}
		}
		
	}
	// unique
	bool DataBase::checkUnique(std::string stdNum)
	{
		for ( std::list<StudentRecord>::iterator uqIt = Students.begin() ; 
			uqIt != Students.end() ; ++uqIt )
		{
			StudentRecord temp = *uqIt ;
			if ( temp.getStudentNumber() == stdNum )
			{
				return false ;
			}
		}
		return true ;
	}
	// print student data
	void DataBase::printStudent(std::string stdNum)
	{
		for ( std::list<StudentRecord>::iterator pIt = Students.begin() ; 
			pIt != Students.end() ; ++pIt )
		{
			StudentRecord temp = *pIt ;
			if ( temp.getStudentNumber() == stdNum )
			{
				/*
				std::cout << "Name : " << temp.getName() << std::endl << "Surname : " << temp.getSurname() << std::endl ;
				std::cout << "Student Number : " << StudentNumber << "\nClass Record : " << temp.getClassRecord() << std::endl ;
				std::cout << "Token : " << temp.getToken() << std::endl ;*/
				
				std::cout << temp.toString() ;
			}
		}
	}
	// grade a student
	void DataBase::gradeStudent(std::string stdNum)
	{
		for ( std::list<StudentRecord>::iterator gIt = Students.begin() ; 
			gIt != Students.end() ; ++gIt )
		{
			StudentRecord temp = *gIt ;
			if ( temp.getStudentNumber() == stdNum )
			{
				
				std::cout << temp.grade() ;
			}
		}
	}
	
	// display all student data
	void DataBase::displayAll()
	{
		for ( std::list<StudentRecord>::iterator dIt = Students.begin() ; 
			dIt != Students.end() ; ++dIt )
		{
			StudentRecord temp = *dIt ;
			
			std::cout << temp.gradedString() << std::endl ;
		}
	}
	
	// save any changes made to DB
	bool DataBase::save(std::string filename )
	{
		// open with truncated option to write over current content
		std::ofstream out;
		out.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

		if(!out)
		{
			std::cout << "Couldn't open " << filename << std::endl;
			return false ;
		}
		
		for ( std::list<StudentRecord>::iterator dIt = Students.begin() ; 
			dIt != Students.end() ; ++dIt )
		{
			StudentRecord temp = *dIt ;
			out << temp.toString() << std::endl ;			
		}
		
		out.close();
		
		return true ;
	}
	
	// read from DB file into student list :
	bool read(std::string filename )
	{
		std::ifstream in(filename.c_str());

		if(!in)
		{
			std::cout << "Couldn't open " << filename << std::endl;
			return false ;
		}
		
		// Extract the lines from the file
		std::string aline;
		
		while ( getline(in, aline) )
		{
			std::istringstream myStream(aline) ; // create a stringStream with the current line as it's element
						
			while(!myStream.eof())
			{
				std::string aname, asurname, astdnum, arecord ;
				int atoken;
				
				getline(myStream, aname, ';') ;
				getline(myStream, asurname, ';') ;
				getline(myStream, astdnum, ';') ;
				getline(myStream, arecord, ';') ;
				myStream >> atoken ;
				
				// make constructor with five args for reading from DB :
			}
			
			std::cout << std::endl ;			
		}
		// Close file
		in.close();
		
		return true ;
	}
}
