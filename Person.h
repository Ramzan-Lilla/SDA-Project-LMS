#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

	class Person
	{
	public:
		Person();
		string getUserName();
		string GetPassWord();
		void SetUserName(string);
		void SetPassWord(string);
		virtual bool login();

	private:
		string User_Name;
		string Password;
		bool flag;
	};

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Admin Class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	class Admin :public Person
	{
	public:
		Admin();
		bool login();

	private:
		bool flag;
	};

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Teacher Class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	class Teacher :public Person
	{
	public:
		Teacher();
		bool login();

	private:
		bool flag;
	};

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Student Class~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	class Student :public Person
	{
	public:
		Student();
		bool login();

	private:
		bool flag;
	};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END HERE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//	