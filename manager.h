#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public Identity
{
public:
	Manager();
	Manager(string name,string pwd);

	void openMenu();

	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();
	void initVector();

	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;
	bool checkRepeat(int id,int type);

};