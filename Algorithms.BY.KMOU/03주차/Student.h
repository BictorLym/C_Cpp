///////////////////////////////////////////////////////////////////////////////
// Student.h
// ===========

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

using namespace std;

class Student{
public:
	Student();
	Student(string _name_, string _telno_);
	string get_name() const;
	string get_telno() const;
	void set_name(string _name_);
	void set_telno(string _telno_);
/*	template <typename T>
	void swap(T& x, T& y, T& temp)*/;
private:
	string name;
	string telno;
};

bool operator<(const Student& left, const Student& right) ;
bool operator<=(const Student& left, const Student& right);
bool operator>(const Student& left, const Student& right);
bool operator>=(const Student& left, const Student& right);
#endif