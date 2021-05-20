#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<string>
#include"orderFile.h"
#include<vector>

class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);
	void openMenu();

	void showAllOrder();
	void validOrder();

	int m_EmpId;

};