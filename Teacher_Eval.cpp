#include"Teacher_Eval.h"

Teacher_Eval::Teacher_Eval()
{
	arr = new float[130];
	for (int i = 0; i < 130; i++)
	{
		arr[i] = '\0';
	}
}

void Teacher_Eval::EvalutionCritria()
{
Again:
	char choice;
	cout << "\n Enter P to View Student Performance:";
	cout << "\n Press M to Enter Student Marks:";
	cout << "\n Press E to exit\n ";
	cout << "\n\t\t What YOU Want To Do: = ";
	cin >> choice;

	if (choice == 'P' || choice == 'p')
	{
		ViewStudentPer();
		goto Again;
	}

	else if (choice == 'M' || choice == 'm')
	{
		system("cls"); char choice;
		begun:
		cout << "\n Press (A) to Enter Assignment Marks:";
		cout << "\n Press (Q) to Enter Quiz Marks:";
		cout << "\n Press (F) to Enter Final Marks:";
		cout << "\n Press E to exit\n ";
		cout << "\n\t\t What YOU Want To Do: = ";
		cin >> choice;

		if (choice == 'F' || choice == 'f')
		{
			Entermarks();
			goto begun;
		}

		else if (choice == 'A' || choice == 'a')
		{
			string filename = "Assignment_mark.txt";
			A_Q_Mark(filename);
			goto begun;
		}

		else if (choice == 'Q' || choice == 'q')
		{
			string filename = "Quiz_Mark.txt";
			A_Q_Mark(filename);
			goto begun;
		}

		else if (choice == 'e' || choice == 'E')
		{
			goto Again;
		}

		else
		{
			system("cls");
			cout << "\n Please Enter Valid Input:";
			goto begun;
		}
	}

	else if (choice == 'e' || choice == 'E')
	{
		return;
	}

	else
	{
		system("cls");
		cout << "\n Please Enter Valid Input:";
		goto Again;
	}
}

void Teacher_Eval::Entermarks()
{
	system("cls");
	string uname, cn, marks, grade, gpa;
	string filename = "Final_Grade_Sheet.txt";
	ofstream file;	file.open(filename, ios::app);
	
	if (!file.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{
		cout << "\n Enter Student name: = "; cin >> uname;
		cout << "\n Enter Course name: = "; cin >> cn;
		cout << "\n Enter Student Marks: = "; cin >> marks;
		
		if (stoi(marks) < 50)
		{
			grade = 'F';
			gpa = '0';
		}

		else if (stoi(marks) > 49 && stoi(marks) < 60)
		{
			grade = 'C';
			gpa = '2';
		}

		else if (stoi(marks) > 59 && stoi(marks) < 70)
		{
			grade = 'B';
			gpa = '3';
		}

		else if (stoi(marks) >= 70)
		{
			grade = 'A';
			gpa = '4';
		}

		file << "\n" << uname << "\t\t" << cn << "\t" << marks << "/100\t" << grade << "\t" << gpa;
		file.close();
	}
	
}

void Teacher_Eval::A_Q_Mark(string filename)
{
	system("cls");
	string uname, cn, marks;
	ofstream file;	file.open(filename, ios::app);

	if (!file.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{
		cout << "\n Enter Student name: = "; cin >> uname;
		cout << "\n Enter Course name: = "; cin >> cn;
		cout << "\n Enter Student Marks: = "; cin >> marks;
		file << "\n" << uname << "\t\t" << cn << "\t" << marks << "/20";
		file.close();
	}
}

void Teacher_Eval::ViewStudentPer()
{
	system("cls");
	string name;
	cout << "\n Enter student Name Whose Marks you want to View: = ";
	cin >> name;
	cout << "\n Marks in Assignment: \n";
	cout << " Uuname\tCourse\tmarks\n";
	string filename = "Assignment_mark.txt";
	View_A_Q_Mark(filename, name);

	cout << "\n Marks in Quiz: \n";
	cout << " Uname\tCourse\tmarks\n";
	filename = "Quiz_Mark.txt";
	View_A_Q_Mark(filename, name);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	cout << "\n Marks in Final and grade: \n";
	cout << "Uname\tCourse\tmarks\tGrade\tGPA\n";
	filename = "Final_Grade_Sheet.txt";
	ifstream file;
	string uname, cn, marks, grade, gpa;
	file.open(filename.c_str());
	if (!file.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{
		int i = 0; float sum = 0;
		while (!file.eof())
		{
			file >> uname >> cn >> marks >> grade >> gpa;
			if (name == uname)
			{
				cout << uname << "\t" << cn << "\t" << marks << "\t" << grade << "\t" << gpa << "\n";
				arr[i] = stof(gpa);
				i = i + 1;
			}
		}

		file.close();
		i = 0;
		while (arr[i] != '\0')
		{
			sum = sum + arr[i];
			i = i + 1;
		}

		sum = sum / i;
		cout << "\nStudent CGPA is = " << sum << "\n";
		file.close();
	}
	
}


void Teacher_Eval::View_A_Q_Mark(string filename,string name)
{
	ifstream file;	string uname, cn, marks;

	file.open(filename.c_str());
	if (!file.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{
		while (!file.eof())
		{
			file >> uname >> cn >> marks;
			if (name == uname)
			{
				cout << uname << "\t" << cn << "\t" << marks << "\n";
			}
		}
		file.close();
	}
}