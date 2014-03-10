#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <string>
#include "tokenlib.h"
#include "counter.h"


namespace whnkud001
{
class StudentRecord : public sjp::counter<StudentRecord>
{
	public :
		// 1 - constructor
		StudentRecord( std::string nm, std::string snm, std::string stdnum, std::string rec ) ;
		// 2 - destructor
		~StudentRecord();
		// 3 - copy constructor
		StudentRecord(const StudentRecord & other);
		// 4 - copy assignment operator
		StudentRecord & operator=(const StudentRecord & other);
		// 5 - move constructor
		StudentRecord(StudentRecord && other) ;
		// 6- move operator
		StudentRecord& operator=(StudentRecord&& other) ;
		// equality
		bool operator==(const StudentRecord& other) const;
		// non-equality
		bool operator!=(const StudentRecord& other) const;
		//class methods	
		
		// getter functions
		std::string getName(void); 
		std::string getSurname(void) ;
		std::string getStudentNumber(void) ; 
		std::string getClassRecord(void) ;
		int getToken(void) ;
		
		// toString :
		std::string toString() ;
		
		// grading
		double grade(void) ;
		
		//gradedString
		std::string gradedString() ;
		
	private :
		std::string Name; std::string Surname; std::string StudentNumber; std::string ClassRecord ;
		int token;
		
};
}

#endif
