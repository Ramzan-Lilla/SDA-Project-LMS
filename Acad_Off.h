#pragma once
#include"Login.h"

class Acad_off
{
public:
	Acad_off();
	void Operations();
	void Remove_Course();
	void Update_Course();
	void Add_Course();
	void Add_section();
private:
	string course_name;
	string course_code;
	int Credit_hour;
	string preReq;
};