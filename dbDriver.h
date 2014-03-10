#ifndef DBDRIVER_H
#define DBDRIVER_H

//using namespace std ;
//#include <string>

namespace whnkud001
{
	void clear(void);
	//std::list::list<whnkud001::StudentRecord> rcd() ;
	void addStudent(std::string name, std::string surname, std::string stdnum, std::string rec) ;
	void deleteStudent(std::string stdnum) ;
	void readStudentData(std::string stdnum) ;
	void gradeStudent(std::string stdnum) ;
	void writeDB(void) ;
	void readDB(void) ;
	void displayStudent(std::string stdnum) ;
	
	DataBase myDB ;
}

#endif
