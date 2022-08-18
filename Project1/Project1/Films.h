#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class Films
{

public:

	ofstream fout;
	ifstream fin;

	//struct kino
	//{
	//	int sell;
	//	string nameis;
	//	string date;
	//};

	
	struct teacher
	{
		int numberHours;
		string teacherName;
		string department;
		string title;
		string degree;
		string discipline;
		string date;
	};

	struct numberHours
	{
		int numberLectureHours;
		int numberPracticalHours;
		int numberHoursLaboratoryWork;
		int totalHours;
	};


	teacher teachers;
	numberHours listOfNumberHours;
	int c;
	string help;

	//counter
	int count = 0;

	//new data
	int directionCodeInt;
	string directionCode;
	string nameDiscipline;
	string discipline;
	int course;
	int term;
	int test;
	int exam;
	int courseWork;
	int courseProject;
	//teacher data
	string tmp;
	string tmp_str;
	string tmp3;

	void intodata()
	{
		cin.ignore();
		cout << "��� �����������" << endl;
		cin >> directionCode;
		tmp = getDirectionCode();
		tmp3 = getDirectionCode();
		int a = getDirectionCode().length();
		//�������� ��� ������� ����� ����� � ���������� �� � ����� ������
		for (int j = 0; j < a; j++)
		{
			if (tmp[j] != '.')
				tmp_str += (tmp[j]);
		}
		//����������� � �����
		directionCodeInt = stoi(tmp_str);

		cout << "�������� ����������:" << endl;
		cin >> nameDiscipline;
		cout << "����������:" << endl;
		cin >> discipline;
		cout << "����:" << endl;
		cin >> course;
		cout << "�������:" << endl;
		cin >> term;
		cout << "������� ���������� :\n1)�����:" << endl;
		cin >> test;
		cout << "2)�������:" << endl;
		cin >> exam;
		cout << "2)�������� ������:" << endl;
		cin >> courseWork;
		cout << "4)�������� ������:" << endl;
		cin >> courseProject;
		cout << "�������������\n1) ���:" << endl;
		cin >> teachers.teacherName;
		cout << "2) �������:" << endl;
		cin >> teachers.department;
		cout << "3) ������:" << endl;
		cin >> teachers.title;
		cout << "4) �������:" << endl;
		cin >> teachers.degree;
		cout << "5) ����������:" << endl;
		cin >> teachers.discipline;
		cout << "���������� �����:\n1) ���������� ���������� �����: " << endl;
		cin >> listOfNumberHours.numberLectureHours;
		cout << "2) ���������� ������������ �����:" << endl;
		cin >> listOfNumberHours.numberPracticalHours;
		cout << "3) ���������� ����� �� ������������ ������: " << endl;
		cin >> listOfNumberHours.numberHoursLaboratoryWork;
		cout << "4) ����� �����:" << endl;
		cin >> listOfNumberHours.totalHours;
		system("cls");
		cout << "����� ����������� ������� ���������!";

	}

	void outdata()
	{
		cin.ignore();
		cout << "��� �����������: " << directionCode << endl;
		cout << "�������� ����������: " << nameDiscipline << endl;
		cout << "����������: " << discipline << endl;
		cout << "����: " << course << endl;
		cout << "�������: " << term << endl;
		cout << "������� ���������� :\n1)�����:" << test << endl;
		cout << "2)�������: " << exam << endl;
		cout << "2)�������� ������: " << courseWork << endl;
		cout << "4)�������� ������: " << courseProject << endl;
		cout << "�������������\n1) ���: " << teachers.teacherName << endl;
		cout << "2) �������: " << teachers.department << endl;
		cout << "3) ������: " << teachers.title << endl;
		cout << "4) �������: " << teachers.degree << endl;
		cout << "5) ����������: " << teachers.discipline << endl;
		cout << "���������� �����:\n1) ���������� ���������� �����: " << listOfNumberHours.numberLectureHours << endl;
		cout << "2) ���������� ������������ �����: " << listOfNumberHours.numberPracticalHours << endl;
		cout << "3) ���������� ����� �� ������������ ������: " << listOfNumberHours.numberHoursLaboratoryWork << endl;
		cout << "4) ����� �����: " << listOfNumberHours.totalHours << endl;
		//system("cls");
		cout << "\n������� ����� ��� �����������...";
	}
	void clrtxt()
	{
		fout.open("kino.txt", ios_base::trunc);
		fout.close();
	}

	void foutdata(int id1, int max)
	{
		fout.open("kino.txt", ios_base::app);
		fout << max << endl;
		fout << "#" << id1 << endl;
		fout << directionCode << endl;
		fout << nameDiscipline << endl;
		fout << discipline << endl;
		fout << course << endl;
		fout << term << endl;
		fout << test << endl;
		fout << exam << endl;
		fout << courseWork << endl;
		fout << courseProject << endl;
		fout << teachers.teacherName << endl;
		fout << teachers.department << endl;
		fout << teachers.title << endl;
		fout << teachers.degree << endl;
		fout << teachers.discipline << endl;
		fout << listOfNumberHours.numberLectureHours << endl;
		fout << listOfNumberHours.numberPracticalHours << endl;
		fout << listOfNumberHours.numberHoursLaboratoryWork << endl;
		fout << listOfNumberHours.totalHours << endl;
		fout.close();
		system("cls");
		cout << "�� ������� ���������!";
	}

	int findata()
	{
		int q;
		fin.open("kino.txt");
		fin >> q;
		fin.close();
		return q;
	}

	void findata(int id1)
	{
		string helper;
		int ihelp;
		string line;
		fin.open("kino.txt");
		while (getline(fin, line))
		{
			if (line[0] == '#' && line[1] == (char)(id1 + 48))
			{
				fin >> directionCode;
				fin >> nameDiscipline;
				fin >> discipline;
				fin >> course;
				fin >> term;
				fin >> test;
				fin >> exam;
				fin >> courseWork;
				fin >> courseProject;
				fin >> teachers.teacherName;
				fin >> teachers.department;
				fin >> teachers.title;
				fin >> teachers.degree;
				fin >> teachers.discipline;
				fin >> listOfNumberHours.numberLectureHours;
				fin >> listOfNumberHours.numberPracticalHours;
				fin >> listOfNumberHours.numberHoursLaboratoryWork;
				fin >> listOfNumberHours.totalHours;
			}
		}
		fin.close();
	}





	string getDirectionCode()
	{
		return directionCode;
	}
	int getDirectionCodeInt()
	{
		return directionCodeInt;
	}

	string getNameDiscipline()
	{
		return nameDiscipline;
	}

	int getTest() 
	{
		return test;
	}

	int getListOfNumberHoursTotalHours()
	{
		return listOfNumberHours.totalHours;
	}

	string getTeacherName() {

		return teachers.teacherName;
	}

};


