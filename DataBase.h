#ifndef DATABASE_H
#define DATABASE_H

#include "tokenlib.h"
#include "StudentRecord.h"
#include <list>

namespace whnkud001
{
	class DataBase
	{
		public :
			// constructor
			DataBase() ;
			// 2 - destructor
			~DataBase();
			// 3 - copy constructor
			DataBase(const DataBase & other);
			// 4 - copy assignment operator
			DataBase & operator=(const DataBase & other);
			// 5 - move constructor
			DataBase(DataBase&& other) ;
			// 6- move operator
			DataBase& operator=(DataBase&& other) ;
			// getter :
			std::list<StudentRecord> getStudents() ;
			// insert student into DB
			void insertStd(StudentRecord newStd) ;
			// delete student from DB
			void deleteStd(std::string stdNum) ;
			//std::string currentCompare ;
			// check if student is unique
			bool checkUnique(std::string stdNum) ;
			// display student data
			void printStudent(std::string stdNum) ;
			// grade a student
			void gradeStudent(std::string stdNum) ;
			// display all student data
			void displayAll(void) ;
			// write to DB file
			bool save(std::string filename ) ;
			bool read(std::string filename ) ;
		private :
			std::list<StudentRecord> Students ;
			//std::string dbTxtName ;
	};
}

#endif
