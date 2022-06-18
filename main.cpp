#include"Login.h"
#include"Acad_Off.h"
#include"Stud_View.h"
#include"Teacher_Eval.h"

int main()
{
	Again:
	char type = '\0'; bool flag = false;
	credential_info log;
	tie(type, flag) = log.Login();
	
	//cout << "\n Type is:- " << type;
	/*Person p;	p = log.getPerson();	cout << endl << endl;*/

	if (!flag)
	{
		cout << "\n UserName or PassWord InCorrect! Login Failed:- ";
		exit(0);
	}
	
	if (type == 'A' || type == 'a')
	{
		Acad_off A;
		A.Operations();
	}

	if (type == 'S' || type == 's')
	{	
		Stud_View s;
		s.setperson(log.getPerson());
		s.Performance();
	}

	if (type == 't' || type == 'T')
	{
		Teacher_Eval t;
		t.EvalutionCritria();
	}

	system("cls"); char c;
	cout << "\n Do Want to Exit (Y) for yes (N) For No!: = ";
	cin >> c;

	if (c == 'Y' || c == 'y')
	{
		exit(0);
	}

	else if (c == 'N' || c == 'n')
	{
		system("cls");
		goto Again;
	}

	else
	{
		cout << "\n You Type Incorrect! Your are Robot:\n ";
	}
	system("pause");
}