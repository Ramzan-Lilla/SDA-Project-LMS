#include"Login.h"

credential_info::credential_info()
{
	flag = false;
}

std::tuple<char, bool> credential_info::Login()
{	
	char type; string un = "hi", pw = "hi";
	cout << "\n Enter S or s if you are a Student:";
	cout << "\n Enter A or a if you are a Academic officer:";
	cout << "\n Enter T or t if you are a Teacher:";
	cout << "\n\t\t You Want to login As: = ";

	Person* P;	Admin ad;	Student sd; Teacher th;

	cin >> type;

	if (type == 'S' || type == 's')
	{
		
		cout << "\n Enter User Name:";
		cin >> un;
		cout << "\n Enter Password: = ";
		cin >> pw;
		P = &sd;
		P->SetPassWord(pw);
		P->SetUserName(un);
		per.SetUserName(un);
		per.SetPassWord(pw);
		flag = P->login();

		if (flag)
		{
			system("cls");
			cout << "\n Login Successfully:- ";
		}

		return  std::make_tuple(type, flag);
	}

	else if (type == 'T' || type == 't')
	{
		
		cout << "\n Enter User Name:";
		cin >> un;
		cout << "\n Enter Password: = ";
		cin >> pw;
		P = &th;
		P->SetPassWord(pw);
		P->SetUserName(un);
		per.SetUserName(un);
		per.SetPassWord(pw);
		flag = P->login();

		if (flag)
		{
			system("cls");
			cout << "\n Login Successfully:- ";
		}

		return  std::make_tuple(type, flag);
	}

	else if (type == 'A' || type == 'a')
	{
		cout << "\n Enter User Name:";
		cin >> un;
		cout << "\n Enter Password: = ";
		cin >> pw;
		P = &ad;
		P->SetPassWord(pw);
		P->SetUserName(un);
		per.SetUserName(un);
		per.SetPassWord(pw);
		flag = P->login();

		if (flag)
		{
			system("cls");
			cout << "\n Login Successfully:- ";
		}

		return  std::make_tuple(type, flag);
	}

	cout << "\n Please Enter Correct Field: - ";
	return  std::make_tuple(type, flag);
}

Person credential_info::getPerson()
{
	return per;
}
