#pragma once
#include"Person.h"
#include"Login.h"

class Teacher_Eval
{
public:
	Teacher_Eval();
	void EvalutionCritria();
	void Entermarks();
	void ViewStudentPer();
	void A_Q_Mark(string);
	void View_A_Q_Mark(string, string);
private:
	float* arr;
};
