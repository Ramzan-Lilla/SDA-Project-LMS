#pragma once
#include"Login.h"
#include"Person.h"

class Stud_View//:public Person
{
public:
	Stud_View();
	void Performance();
	void setperson(Person);
	string GETperson();
	void Gradesheet(string name, string filename);
	void Q_A_Marks(string name,string);
	void RegisterCourse(string name, string filename);
	~Stud_View();

private:
	Person P;
	float* arr;
	string UN;
};