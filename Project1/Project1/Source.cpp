
#include <iostream>
#include <conio.h>
#include <fstream>
#include "Films.h"

using namespace std;

struct arrs
{
	int i;
	int arr;
	string name;
	float fl;
	bool bb = false;
};

Films fi[100];
arrs myarr[100];
arrs timearr[100];
arrs chararr[100];
arrs chararrr[100];
arrs raiting[100];

void sortf(int s)
{
	for (int i = 0; i < s - 1; i++)
	{
		int small = i;

		for (int j = i + 1; j < s; j++)
		{
			if (raiting[j].fl < raiting[small].fl)
				small = j;
		}
		swap(raiting[i].fl, raiting[small].fl);
		swap(raiting[i].i, raiting[small].i);
	}
	system("cls");
	cout << "   Название рейса | Номер самолета | Кол-во мест" << endl << endl;
	for (int i = 0; i < s; i++)
	{

		cout << raiting[i].i + 1 << ") ";
		int t = raiting[i].i;
		cout << fi[t].getname() << " | ";
		cout << fi[t].gettime() << " ";
		cout << " | " << fi[t].getraiting() << endl;
	}
	int answ;
	cout << "\n Введите найденый рейс: ";
	cin >> answ;
	fi[answ - 1].outdata();
}

void sortcc(int s)
{
	for (int i = 0; i < s - 1; i++)
		for (int j = i; j >= 0; j--)
			if (chararrr[j].name > chararrr[j + 1].name)
			{
				swap(chararrr[j].name, chararrr[j + 1].name);
				swap(chararrr[j].i, chararrr[j + 1].i);
			}

	system("cls");
	cout << "   Класс | Название рейса | Номер самолета | Кол-во мест" << endl << endl;
	for (int i = 0; i < s; i++)
	{

		cout << chararrr[i].i + 1 << ") ";
		int t = chararrr[i].i;
		cout << chararrr[i].name << " | ";
		cout << fi[t].getname();
		cout << " | " << fi[t].gettime() << " ";
		cout << " | " << fi[t].getraiting() << endl;
	}
}

void sortc(int s)
{
	for (int i = 0; i < s - 1; i++)
		for (int j = i; j >= 0; j--)
			if (chararr[j].name > chararr[j + 1].name)
			{
				swap(chararr[j].name, chararr[j + 1].name);
				swap(chararr[j].i, chararr[j + 1].i);
			}

	system("cls");
	cout << "   Название рейса | Номер самолета | кол-во мест" << endl << endl;
	for (int i = 0; i < s; i++)
	{

		cout << chararr[i].i + 1 << ") ";
		int t = chararr[i].i;
		cout << chararr[i].name << " | ";
		cout << fi[t].gettime() << " ";
		cout << " | " << fi[t].getraiting() << endl;
	}
	int answ;
	cout << "\n Введите найденый маршрут: ";
	cin >> answ;
	fi[answ - 1].outdata();
}

void sortl(int s)
{
	for (int i = 0; i < s - 1; i++)
	{
		int small = i;

		for (int j = i + 1; j < s; j++)
		{
			if (timearr[j].arr < timearr[small].arr)
				small = j;
		}
		swap(timearr[i].arr, timearr[small].arr);
		swap(timearr[i].i, timearr[small].i);
	}
	system("cls");
	cout << "   Название рейса | Номер самолета | Кол-во мест" << endl << endl;
	for (int i = 0; i < s; i++)
	{

		cout << timearr[i].i + 1 << ") ";
		int t = timearr[i].i;
		cout << fi[t].getname() << " | ";
		cout << timearr[i].arr << " ";
		cout << " | " << fi[t].getraiting() << endl;
	}
	int answ;
	cout << "\n Введите найденый товар: ";
	cin >> answ;
	fi[answ - 1].outdata();
}

void sorts(int s)
{

	for (int i = 0; i < s - 1; i++)
	{
		int small = i;

		for (int j = i + 1; j < s; j++)
		{
			if (myarr[j].arr < myarr[small].arr)
				small = j;
		}
		swap(myarr[i].arr, myarr[small].arr);
		swap(myarr[i].i, myarr[small].i);
	}
	system("cls");
	cout << "   Название рейса | Классы | Цена | Кол-во мест" << endl << endl;
	for (int i = 0; i < s; i++)
	{

		cout << myarr[i].i + 1 << ") ";
		int t = myarr[i].i;
		cout << fi[t].getname() << " | ";
		cout << fi[t].getkinosnameis(myarr[i].arr);
		cout << " | " << myarr[i].arr;
		cout << " | " << fi[t].getraiting() << endl;


	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int answ;
	int max = 0;
	bool start = false;

	for (;;)
	{
		system("cls");
		cout << "1) Посмотреть список направлений" << endl;
		cout << "2) Добавить новое направление" << endl;
		cout << "3) Загрузить файл" << endl;
		cout << "4) Сохранить файл" << endl;
		cout << "5) Искать направления по параметрам" << endl;
		cout << "0) Выход" << endl;

		cin >> answ;
		system("cls");

		if (answ == 1)
		{
			for (int i = 1; i < max + 1; i++)
				cout << i << ") " << fi[i - 1].getname() << endl;
			if (max == 0)
				cout << "Нет информации" << endl;
			else
			{
				cout << "Выберите для уточнения: ";
				cin >> answ;
				fi[answ - 1].outdata();
			}
			_getch();
			continue;
		}
		if (answ == 2)
		{
			fi[max].intodata();
			max++;
		}
		if (answ == 3 && start == false)
		{
			start = true;
			int localmax = fi[0].findata();
			for (int i = 0; i < localmax; i++)
			{
				fi[i + max].findata(i);
			}
			max = max + localmax;
			cout << "Успешно загружено!";
		}
		else {
			if (answ == 3)
			{
				system("cls");
				cout << "Вы уже загрузили!";
			}
		}
		if (answ == 4)
		{
			fi[0].clrtxt();
			for (int i = 0; i < max; i++)
			{
				fi[i].foutdata(i, max);
			}
		}
		if (answ == 5)
		{

			cout << "1) Сортировка по классам" << endl;
			cout << "2) Сортировка по рейсам" << endl;
			cout << "3) Сортировка по номеру самолета" << endl;
			cout << "4) Сортировка по ценам" << endl;
			cout << "5) Сортировка по количество мест" << endl;
			cout << "6) Поиск названия" << endl;

			cin >> answ;

			if (answ == 1)
			{
				int s = 0;
				for (int i = 0; i < max; i++)
				{
					int c;

					c = fi[i].getc();
					for (int j = 0; j < c; j++)
					{
						chararrr[s].name = fi[i].getkino(j);
						chararrr[s].i = i;
						s++;
					}

				}
				sortcc(s);
			}

			if (answ == 2)
			{
				for (int i = 0; i < max; i++)
				{
					chararr[i].name = fi[i].getname();
					chararr[i].i = i;
				}
				sortc(max);
			}

			if (answ == 3)
			{
				for (int i = 0; i < max; i++)
				{
					timearr[i].arr = fi[i].gettime();
					timearr[i].i = i;
				}
				sortl(max);
			}

			if (answ == 4)
			{
				int c;
				int s = 0;

				for (int i = 0; i < max; i++)
				{
					c = fi[i].getc();
					for (int j = 0; j < c; j++)
					{
						myarr[s].arr = fi[i].getsell(j);
						myarr[s].i = i;
						s++;
					}

				}
				sorts(s);
			}
			if (answ == 5)
			{
				for (int i = 0; i < max; i++)
				{
					raiting[i].fl = fi[i].getraiting();
					raiting[i].i = i;
				}
				sortf(max);
			}
			if (answ == 6)
			{
				string poisk;
				system("cls");
				cout << "Ввод в поисковик: ";
				cin.ignore();
				getline(cin, poisk);

				setlocale(LC_ALL, "Russian");

				for (int i = 0; i < max; i++)
				{
					chararr[i].name = fi[i].getname();
					chararr[i].i = i;
				}

				for (int i = 0; i < max; i++)
				{
					for (int j = 0; j < poisk.length(); j++)
					{
						if (chararr[i].name[j] != poisk[j])
							break;
						else
							if (j == poisk.length() - 1)
								chararr[i].bb = true;

					}
				}
				bool su = false;
				system("cls");
				cout << "   Название техники | Телефон | Скидка" << endl << endl;
				for (int i = 0; i < max; i++)
				{
					if (chararr[i].bb)
					{
						cout << chararr[i].i + 1 << ") ";
						int t = chararr[i].i;
						cout << fi[t].getname() << " | ";
						cout << fi[t].gettime() << " ";
						cout << " | " << fi[t].getraiting() << endl;
						su = true;
						chararr[i].bb = false;
					}
				}
				if (su)
				{
					cout << "\n Введите найденый рейс: ";
					cin >> answ;
					fi[answ - 1].outdata();
					su = false;
				}
				else
				{
					system("cls");
					cout << "Увы! Ничего не найдено";
				}
			}


		}
		if (answ == 0)
		{
			return 0;
		}
		_getch();
	}



	_getch();
	return 0;
}