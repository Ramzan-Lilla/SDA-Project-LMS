#include"Acad_Off.h"

Acad_off::Acad_off()
{
	course_name ='\0';
	course_code = '\0';
	Credit_hour = 0;
	preReq = '\0';
}

void Acad_off::Operations()
{
Again:
	system("cls");
	char choice;
	cout << "\n U or u if You want to Update Course:";
	cout << "\n R or r if You want to Remove Course:";
	cout << "\n A or a if You want to Add new Course:";
	cout << "\n S or s if You want to Add new Course:";
	cout << "\n E or e if You want to Exit:\n ";
	cout << "\n\t\t What YOU Want To Do: = ";
	cin >> choice;

	if (choice == 'u' || choice == 'U')
	{		
		Update_Course();
		goto Again;
	}

	else if (choice == 'R' || choice == 'r')
	{
		Remove_Course();
		goto Again;
	}

	else if (choice == 'A' || choice == 'a')
	{
		Add_Course();
		goto Again;
	}

	else if (choice == 'S' || choice == 's')
	{
		Add_section();
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Remove_Course~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Acad_off::Remove_Course()
{
	system("cls");
	string filename = "Course_Records.txt",tempfile = "temp.txt";
	string CC, fcc, fcn, fch, fpreReq;
Again:
	cout << "\n Enter The code of Course That you wnat to remove: = ";
	cin >> CC;

	ifstream file; ofstream tfile;
	file.open(filename.c_str());

	tfile.open(tempfile, ios::app);

	if (!file.is_open() || !tfile.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{
		while (!file.eof())
		{
			file >> fcc >> fcn >> fch >> fpreReq;
			if (CC != fcc)
			{
				tfile << "\n" << fcc << "\t" << fcn << "\t" << fch << "\t" << fpreReq;
			}
		}

		tfile.close();
		file.close();
		remove("Course_Records.txt");
		if (rename("temp.txt", "Course_Records.txt") != NULL) { return; };

		char choice;
		cout << "\n want To Remove More Courses (N) for No! (Y) for Yes!: = ";
		cin >> choice;

		if (choice == 'n' || choice == 'N')
		{
			return;
		}

		else
		{
			goto Again;
		}
	}

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Update_Course~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Acad_off::Update_Course()
{
	system("cls");
	string filename = "Course_Records.txt", tempfile = "temp.txt";
	string CC, fcc, fcn, fch, fpreReq;
Again:
	cout << "\n Enter The code of Course That you wnat to UPdate: = ";
	cin >> CC;

	ifstream file; ofstream tfile;
	file.open(filename.c_str());

	tfile.open(tempfile, ios::app);

	if (!file.is_open() || !tfile.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else
	{
		while (!file.eof())
		{
			file >> fcc >> fcn >> fch >> fpreReq;
			if (CC != fcc)
			{
				tfile << "\n" << fcc << "\t" << fcn << "\t" << fch << "\t" << fpreReq;
			}

			else
			{
				cout << "\n Enter New Code for Course: = ";
				cin >> fcc;
				cout << "\n Enter New Name for Course: = ";
				cin >> fcn;
				cout << "\n Enter New Credit hour for Course: = ";
				cin >> fch;
				cout << "\n Enter New PreReq for Course: = ";
				cin >> fpreReq;
				tfile << "\n" << fcc << "\t" << fcn << "\t" << fch << "\t" << fpreReq;
			}
		}

		tfile.close();
		file.close();
		remove("Course_Records.txt");
		if (rename("temp.txt", "Course_Records.txt") != NULL) { return; };

		char choice;
		cout << "\n want To UPdate More Course (N) for No! (Y) for Yes!: = ";
		cin >> choice;

		if (choice == 'n' || choice == 'N')
		{
			return;
		}

		else
		{
			goto Again;
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Add_Course~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Acad_off::Add_Course()
{

	system("cls");
	Again:
	cout << "\n Enter The Course code: = ";
	cin >> course_code;
	cout << "\n Enter The Course Name: = ";
	cin >> course_name;
	cout << "\n Enter The Course Pre-Requisite: = ";
	cin >> preReq;
	cout << "\n Enter The Course Chr: = ";
	cin >>Credit_hour;

	fstream file;
	file.open("Course_Records.txt", ios::app);	// Opening file in append mode
	if (!file.is_open())
	{
		cout << "\n Something Wrong in opening the file ";
	}

	else
	{
		file << "\n" << course_code << "\t" << course_name << "\t" << Credit_hour << "\t" << preReq;
		file.close();
		
		char choice;
		cout << "\n want To Add More Course (N) for No! (Y) for Yes!: = ";
		cin >> choice;

		if (choice == 'n' || choice == 'N')
		{
			return;
		}

		else
		{
			goto Again;
		}
	}
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Add_Section~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Acad_off::Add_section()
{
	string course, section, teacher;
	system("cls");
Again:
	cout << "\n Enter The Course Name: = ";
	cin >> course;
	cout << "\n Enter The Section: = ";
	cin >> section;
	cout << "\n Enter The teacher Name: = ";
	cin >> teacher;

	fstream file;
	file.open("Section_Info.txt", ios::app);	// Opening file in append mode
	if (!file.is_open())
	{
		cout << "\n Something Wrong in opening the file ";
	}

	else
	{
		file << "\n" << course << "\t" << section << "\t" << teacher;
		file.close();

		char choice;
		cout << "\n want To Add More Course (N) for No! (Y) for Yes!: = ";
		cin >> choice;

		if (choice == 'n' || choice == 'N')
		{
			return;
		}

		else
		{
			goto Again;
		}
	}
}