#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

class Student :public Identity
{
public:

	Student();

	Student(int id, string name, string pwd);

	void openMenu();
	
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();
	int m_Id;

	vector<ComputerRoom>vCom;

};
