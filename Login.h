#pragma once
#include"Person.h"
#include<tuple>

class credential_info
{
public:
	credential_info();
	std::tuple<char, bool> Login();
	Person getPerson();
private:
	Person per;
	bool flag;
};