#include "StudentRecord.h"
#include <string>
#include "tokenlib.h"
#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <istream>  // Needed for string stream objects
#include <sstream>   // Needed for strings
#include <iterator>
#include "counter.h"

namespace whnkud001
{	
	//Constructor
	StudentRecord::StudentRecord(std::string nm, std::string snm, std::string stdnum, std::string rec )
		: Name(nm), Surname(snm), StudentNumber(stdnum), ClassRecord(rec)
	{
		token = tokenlib::acquire_token() ;
	}
		
	// Destructor
	StudentRecord::~StudentRecord()
	{
		if ( token != 0 )
		{
			//release resources
			tokenlib::release_token(token) ;
		}
	};
	
	// Copy constructor
	StudentRecord::StudentRecord(const StudentRecord & other) : 
		Name(other.Name) , Surname(other.Surname) , 
		StudentNumber(other.StudentNumber) , ClassRecord(other.ClassRecord) ,
		token(tokenlib::acquire_token()) 
	{
		
	}
	
	// Copy assignment operator
	StudentRecord& StudentRecord:: operator=(const StudentRecord & other)
	{
		if (this != &other)
		{
			Name = other.Name ; Surname = other.Surname ; 
			StudentNumber = other.StudentNumber ; ClassRecord = other.ClassRecord ;
			token = tokenlib::acquire_token() ;
		}
		return *this ;
	}
	
	// equality operator
	bool StudentRecord::operator==(const StudentRecord & other)const{
         return StudentNumber == other.StudentNumber ;
	}
	
	// non-equality operator
	bool StudentRecord::operator!=(const StudentRecord & other)const{
         return StudentNumber != other.StudentNumber ;
	}
	
	// Move Constructor
	StudentRecord::StudentRecord(StudentRecord && other) : 
		Name(std::move(other.Name)) , Surname(std::move(other.Surname)) , 
		StudentNumber(std::move(other.StudentNumber)) , ClassRecord(std::move(other.ClassRecord)) ,
		token(other.token)
		/*Name(other.Name) , Surname(other.Surname) , 
		StudentNumber(other.StudentNumber) , ClassRecord(other.ClassRecord) ,
		token(other.token) */
	{
		other.token = 0 ;
	}
	// Move assignment operator
	StudentRecord& StudentRecord :: operator=(StudentRecord&& other)
	{
		if (this != &other)
		{	
			/* Release resources
			delete[] Name; delete[]  Surname; delete[]  StudentNumber; delete[]  ClassRecord; token = 0;*/
			// Get resources
			Name = std::move(other.Name) ;
			Surname = std::move(other.Surname) ; 
			StudentNumber = std::move(other.StudentNumber) ;
			ClassRecord = std::move(other.ClassRecord) ;
			token = other.token ;
			// Set other's resources to default
			other.token = 0 ;
		}
		return *this;
	}
	// Getter Methods :
	std::string StudentRecord::getName(void) { return Name ; }
	
	std::string StudentRecord::getSurname(void) { return Surname ; }
	
	std::string StudentRecord::getStudentNumber(void) { return StudentNumber ; }
	
	std::string StudentRecord::getClassRecord(void) { return ClassRecord; }
	
	int StudentRecord::getToken(void) { return token ; }
	
	// toString
	std::string StudentRecord::toString()
	{
		std::string str = Name ;
		std::string rtnStr = str + ";" + Surname + ";" + 
			StudentNumber + ";" + ClassRecord + ";" + std::to_string(token) ; // to string problem
		return rtnStr ;
	}
	
	// gradedString
	std::string StudentRecord::gradedString()
	{
		std::string str = Name ;
		std::string rtnStr = str + " " + Surname + " " + StudentNumber + " " + 
			std::to_string(grade()) ;//+ "\tToken : " + std::to_string(token) ; // to string problem
		return rtnStr ;
	}
	
	// return student average grade
	double StudentRecord::grade(void)
	{
		std::istringstream myStream(ClassRecord) ; // create a stringStream with the ClassRecord as argument...
		
		int count = 0 ; int total = 0;
		while(!myStream.eof())
		{
			int current ;
			myStream >> current ;
			
			total = total + current ;
			++count ;
		}
		
		return total/count ;
	}
}
