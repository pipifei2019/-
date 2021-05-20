#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"globalFile.h"
#include<map>
#include<string>


class OrderFile
{
public:
	OrderFile();
	void updateOrder();

	int m_Size;

	map<int, map<string, string>>m_orderData;

};
