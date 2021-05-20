#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->openMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;


		}
	}
}

//��ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;

		int select = 0;

		cin >> select;
		if (select == 1)
		{
			
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}
//����Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->openMenu();

		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//��¼����
void LoginIn(string filename, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "������ѧ�ţ�" << endl;
		cin >> id;

	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;

	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}

		}

	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "admin��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "================��ӭ��������ԤԼϵͳ================"
			<< endl;
		cout << endl << "������������" << endl;
		cout << "\t\t-------------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         1.ѧ������          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         2.��    ʦ          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         3.�� �� Ա          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         0.��    ��          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t-------------------------------\n";
		cout << "���������ѡ��";

		cin >> select;
		switch (select)
		{ 
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}	