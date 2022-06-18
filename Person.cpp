#include"Person.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Person Class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Person::Person()
{
	User_Name = '\0';
	Password = '\0';
	flag = false;
}


void Person::SetUserName(string un)
{
	User_Name = un;
}

void Person::SetPassWord(string pw)
{
	Password = pw;
}

string Person::getUserName()
{
	return User_Name;
}

string  Person::GetPassWord()
{
	return Password;
}

bool Person::login()
{
	cout << "\n hello\n";
	return flag;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Admin Class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Admin::Admin()
{
	flag = false;
}

bool Admin::login()
{
	string U_N, P_W, filename;
	fstream file;
	filename = "Cred_Admin.txt";
	file.open(filename.c_str());
	
	if (!file.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else {
		while (file >> U_N)
		{
			
			file >> P_W;
			if (P_W == GetPassWord() && U_N == getUserName())
			{
				flag = true;
			}
		}
		file.close();
	}

	return flag;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Teacher Class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Teacher::Teacher()
{
	flag = false;
}

bool Teacher::login()
{
	string U_N, P_W, filename;
	fstream file;
	filename = "Cred_Teah.txt";
	file.open(filename.c_str());

	if (!file.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else {
		while (file >> U_N)
		{
			file >> P_W;
			if (P_W == GetPassWord() && U_N == getUserName())
			{
				flag = true;
			}
		}
		file.close();
	}

	return flag;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Student Class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

Student::Student()
{
	flag = false;
}

bool Student::login()
{
	string U_N, P_W, filename;
	fstream file;
	filename = "Cred_Stud.txt";
	file.open(filename.c_str());
	
	if (!file.is_open()) {
		cout << "\n Error in Opening File:\n";
	}

	else {
		while (file >> U_N)
		{
			file >> P_W;
			if (P_W == GetPassWord() && U_N == getUserName())
			{
				flag = true;
			}
		}
		file.close();
	}

	if (flag == true)
	{

	}
	return flag;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END HERE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//