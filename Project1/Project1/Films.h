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

	struct kino
	{
		int sell;
		string nameis;
		string date;
	};

	int id;
	string name;
	string desc;
	string shanr;
	int time;
	float raiting;
	kino kinos[100];
	int c;
	string help;

	//new data
	int directionCode;
	string nameDiscipline;
	string discipline;
	int course;
	int term;
	string signReporting;
	string teacher;
	int numberHours;






	void intodata()
	{
		cin.ignore();
		cout << "Код направления" << endl;
		getline(cin, name);
		cout << "Название дисциплины:" << endl;
		getline(cin, desc);
		cout << "Дисциплина: " << endl;
		getline(cin, shanr);
		cout << "Курс:" << endl;
		cin >> time;
		cout << "Семестр:" << endl;
		cin >> raiting;
		cout << "признак отчетности :" << endl;
		cin >> c;
		for (int i = 0; i < c; i++)
		{
			cout << "Преподаватель:" << endl;
			cin.ignore();
			getline(cin, help);
			kinos[i].nameis = help;
			cout << "Количество часов :" << endl;
			cin >> kinos[i].sell;
			//cout << ":" << endl;
		}
		system("cls");
		cout << "Новый направление успешно добавлен!";
	}

	void outdata()
	{
		system("cls");
		cout << "\n\nНазвание маршрута: ";
		cout << name << endl;
		cout << "Описание маршрута: ";
		cout << desc << endl;
		cout << "Пересандка:" << endl;
		cout << shanr << endl;
		cout << "Номер рейса: ";
		cout << time << " " << endl;
		cout << "Количество мест: ";
		cout << raiting << endl;
		cout << "Количество классов: " << endl;
		for (int i = 0; i < c; i++)
		{
			cout << i + 1 << ") " << kinos[i].nameis << " Цена: " << kinos[i].sell << endl;
		}
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
		fout << name << endl;
		fout << desc << endl;
		fout << shanr << endl;
		fout << time << endl;
		fout << raiting << endl;
		fout << c << endl;
		for (int i = 0; i < c; i++)
		{
			fout << kinos[i].nameis << endl;
			fout << kinos[i].sell << endl;
		}
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
				getline(fin, name);
				getline(fin, desc);
				getline(fin, shanr);
				fin >> time;
				fin >> raiting;
				fin >> c;
				for (int i = 0; i < c; i++)
				{
					fin.ignore();
					getline(fin, helper);
					kinos[i].nameis = helper;
					fin >> ihelp;
					kinos[i].sell = ihelp;
				}
			}
		}
		fin.close();
	}

	float getraiting()
	{
		return raiting;
	}

	string getname()
	{
		return name;
	}

	string getkinosnameis(int f)
	{
		for (int i = 0; i < c; i++)
		{
			if (kinos[i].sell == f)
				return kinos[i].nameis;
		}
	}




	int gettime()
	{
		return time;
	}

	int getc()
	{
		return c;
	}

	int getsell(int i)
	{
		return kinos[i].sell;
	}

	string getkino(int i)
	{
		return kinos[i].nameis;
	}

};


