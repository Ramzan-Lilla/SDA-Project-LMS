#include"Stud_View.h"

Stud_View::Stud_View()
{
	
	//P = nullptr;
	arr = new float[130];
	for (int i = 0; i < 130; i++)
	{
		arr[i] = '\0';
	}
}

void Stud_View::setperson(Person ps)
{
	P = ps;
}

string Stud_View::GETperson()
{
	return UN;
}

void Stud_View::Performance()
{
	char choice;
	Again:
	cout << "\n Press G or g if You Want to view Grade Sheet:";
	cout << "\n Press Q or q if You Want to view Quiz Marks:";
	cout << "\n Press A or a if You Want to view Assignment Marks:";
	cout << "\n Press R or r if You Want to Register in new Course:";
	cout << "\n E or e if You want to Exit:\n ";
	cout << "\n\t\t What YOU Want To Do: = ";
	cin >> choice;

	if (choice == 'G' || choice == 'g')
	{
		system("cls");
		cout << "\n Marks in Final and grade: \n";
		cout << "Uname\tCourse\tmarks\tGrade\tGPA\n";
		string filename = "Final_Grade_Sheet.txt";
		Gradesheet(P.getUserName(), filename);
		goto Again;
	}

	else if (choice == 'Q' || choice == 'q')
	{
		system("cls");
		cout << "\n Marks in Quiz: \n";
		cout << " Uname\tCourse\tmarks\n";
		string filename = "Quiz_Mark.txt";
		Q_A_Marks(P.getUserName(),filename);
		goto Again;
	}

	else if (choice == 'A' || choice == 'a')
	{
		system("cls");
		cout << "\n Marks in Assignment: \n";
		cout << " Uuname\tCourse\tmarks\n";
		string filename = "Assignment_mark.txt";
		Q_A_Marks(P.getUserName(),filename);
		goto Again;
	}

	else if (choice == 'R' || choice == 'r')
	{
		system("cls");
		string filename = "Register_Course.txt";
		RegisterCourse(P.getUserName(), filename);
		goto Again;
	}

	else if (choice == 'E' || choice == 'e')
	{
		return;
	}

	else
	{
		system("cls");
		cout << "\n Please Enter The Correct Opetion:\n ";
		goto Again;
	}
}

void Stud_View::Gradesheet(string name, string filename)
{
	ifstream file;	string uname, cn, marks, grade, gpa;
	file.open(filename.c_str());
	if (!file.is_open() ) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{		
		int i = 0;float sum = 0;
		while (!file.eof())
		{
			file >> uname >> cn >> marks >> grade >> gpa;
			if (name == uname)
			{
				cout << uname << "\t" << cn << "\t" << marks << "\t" << grade << "\t" << gpa << "\n";
				arr[i]= stof(gpa);
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
		cout << "\n CGPA is = " << sum << "\n";
		file.close();
	}
}

void Stud_View::Q_A_Marks(string name, string filename)
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

void Stud_View::RegisterCourse(string name, string filename)
{
again:
	ifstream rfile;	string course, sec, teacher,fname = "Section_Info.txt";
	ofstream file;
	file.open(filename, ios::app);
	rfile.open(fname.c_str());
	if (!file.is_open() || !rfile.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{
		string CC, sect; int flag = 0;
		cout << "\n Enter Course You want to Register: = ";
		cin >> CC;
		cout << "\n Enter Course You want to Register: = ";
		cin >> sect;

		while (!rfile.eof())
		{
			rfile >> course >> sec >> teacher;
			if (CC == course && sec == sect)
			{
				file << name << "\t" << course << "\t" << sec << "\n";
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			char c;
			cout << "\n Sorry This Course in this Section Not Offer ";
			cout << "\n Want to Register in Other Section Y for yes:";
			cin >> c;
			if (c == 'Y' || c == 'y')
			{
				goto again;
			}		
		}

		file.close();
	}
}


Stud_View::~Stud_View()
{
	//delete P;
}