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
		cout << "Код направления" << endl;
		cin >> directionCode;
		tmp = getDirectionCode();
		tmp3 = getDirectionCode();
		int a = getDirectionCode().length();
		//Получаем все символы кроме точек и записываем их в новую строку
		for (int j = 0; j < a; j++)
		{
			if (tmp[j] != '.')
				tmp_str += (tmp[j]);
		}
		//Преобразуем в число
		directionCodeInt = stoi(tmp_str);

		cout << "Название дисциплины:" << endl;
		cin >> nameDiscipline;
		cout << "Дисциплина:" << endl;
		cin >> discipline;
		cout << "Курс:" << endl;
		cin >> course;
		cout << "Семестр:" << endl;
		cin >> term;
		cout << "Признак отчетности :\n1)Зачет:" << endl;
		cin >> test;
		cout << "2)Экзамен:" << endl;
		cin >> exam;
		cout << "2)Курсовая работа:" << endl;
		cin >> courseWork;
		cout << "4)Курсовой проект:" << endl;
		cin >> courseProject;
		cout << "Преподаватель\n1) ФИО:" << endl;
		cin >> teachers.teacherName;
		cout << "2) Кафедра:" << endl;
		cin >> teachers.department;
		cout << "3) Звание:" << endl;
		cin >> teachers.title;
		cout << "4) Степень:" << endl;
		cin >> teachers.degree;
		cout << "5) Дисциплина:" << endl;
		cin >> teachers.discipline;
		cout << "Количество часов:\n1) Количество лекционных часов: " << endl;
		cin >> listOfNumberHours.numberLectureHours;
		cout << "2) Количество практических часов:" << endl;
		cin >> listOfNumberHours.numberPracticalHours;
		cout << "3) Количество часов на лабораторные работы: " << endl;
		cin >> listOfNumberHours.numberHoursLaboratoryWork;
		cout << "4) Всего часов:" << endl;
		cin >> listOfNumberHours.totalHours;
		system("cls");
		cout << "Новое направление успешно добавлено!";

	}

	void outdata()
	{
		cin.ignore();
		cout << "Код направления: " << directionCode << endl;
		cout << "Название дисциплины: " << nameDiscipline << endl;
		cout << "Дисциплина: " << discipline << endl;
		cout << "Курс: " << course << endl;
		cout << "Семестр: " << term << endl;
		cout << "Признак отчетности :\n1)Зачет:" << test << endl;
		cout << "2)Экзамен: " << exam << endl;
		cout << "2)Курсовая работа: " << courseWork << endl;
		cout << "4)Курсовой проект: " << courseProject << endl;
		cout << "Преподаватель\n1) ФИО: " << teachers.teacherName << endl;
		cout << "2) Кафедра: " << teachers.department << endl;
		cout << "3) Звание: " << teachers.title << endl;
		cout << "4) Степень: " << teachers.degree << endl;
		cout << "5) Дисциплина: " << teachers.discipline << endl;
		cout << "Количество часов:\n1) Количество лекционных часов: " << listOfNumberHours.numberLectureHours << endl;
		cout << "2) Количество практических часов: " << listOfNumberHours.numberPracticalHours << endl;
		cout << "3) Количество часов на лабораторные работы: " << listOfNumberHours.numberHoursLaboratoryWork << endl;
		cout << "4) Всего часов: " << listOfNumberHours.totalHours << endl;
		//system("cls");
		cout << "\nНажмите любую для продолжения...";
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
		cout << "Вы успешно сохранили!";
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


