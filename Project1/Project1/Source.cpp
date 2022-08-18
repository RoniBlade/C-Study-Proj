
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
Films fi[10];
arrs myarr[100];
arrs timearr[100];
arrs chararr[100];
arrs chararrr[100];
arrs raiting[100];

//сортировка пузырьком для кода направления
void sortByCode(int max)
{


	string list[10] = {};
	for (int i = 0; i < max; i++)
	{
		
		list[i] = fi[i].getDirectionCode();
		
	}

	int listLength = max;

	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}

	cout << "\nКод направления\n";
	for (int i = 0; i < max; i++)
	{
		cout << i + 1 << ") " << list[i] << endl;
	}
	int answ;
	cout << "\n Выберите: ";
	cin >> answ;
	for (int i = 0; i < max; i++)
	{

		if (list[i] == fi[answ - 1].getDirectionCode())
		{
			fi[i].outdata();
		}

	}

}
	//по дисциплинам		
void sortByNameDiscipline(int max)
{

	string list[10] = {};
	for (int i = 0; i < max; i++)
	{

		list[i] = fi[i].getNameDiscipline();

	}

	int listLength = max;
	
	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
	cout << "\nДисциплина\n";
	for (int i = 0; i < max; i++)
	{
		cout << i + 1 << ") " << list[i] << endl;
	}
	int answ;
	cout << "\n Выберите: ";
	cin >> answ;
	for (int i = 0; i < max; i++)
	{

		if (list[i] == fi[answ - 1].getNameDiscipline())
		{
			fi[i].outdata();
		}

	}


}
//Сортировка по зачетам
void sortByTest(int max)
{


	int list[10] = {};
	for (int i = 0; i < max; i++)
	{

		list[i] = fi[i].getTest();

	}

	int listLength = max;

	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
	cout << "\nКоличество зачетов\n";
	for (int i = 0; i < max; i++)
	{
		cout << i + 1 << ") " << list[i] << endl;
	}
	int answ;
	cout << "\n Выберите: ";
	cin >> answ;
	for (int i = 0; i < max; i++)
	{

		if (list[i] == fi[answ - 1].getTest())
		{
			fi[i].outdata();
		}

	}

}

//по преподавателям	
void sortByNameTeacher(int max)
{

	string list[10] = {};
	for (int i = 0; i < max; i++)
	{

		list[i] = fi[i].getTeacherName();

	}

	int listLength = max;

	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}

	cout << "\nФИО Преподавателя\n";
	for (int i = 0; i < max; i++)
	{
		cout << i + 1 << ") " << list[i] << endl;
	}
	int answ;
	cout << "\n Выберите: ";
	cin >> answ;
	for (int i = 0; i < max; i++)
	{

			if(list[i] == fi[answ - 1].getTeacherName())
			{
				fi[i].outdata();
			}
	
	}
	

}

//Сортировка по количеству часов
void sortByCountHours(int max)
{


	int list[10] = {};
	for (int i = 0; i < max; i++)
	{

		list[i] = fi[i].getListOfNumberHoursTotalHours();

	}

	int listLength = max;

	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				swap(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
	cout << "\nКоличество часов\n";
	for (int i = 0; i < max; i++)
	{
		cout << i + 1 << ") " << list[i] << endl;
	}
	int answ;
	cout << "\n Выберите: ";
	cin >> answ;
	for (int i = 0; i < max; i++)
	{

		if (list[i] == fi[answ - 1].getListOfNumberHoursTotalHours())
		{
			fi[i].outdata();
		}

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
				cout << i << ") " << fi[i - 1].getDirectionCode() << endl;
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

			cout << "1) Сортировка по кодам направления" << endl;
			cout << "2) Сортировка по названиям дисциплины" << endl;
			cout << "3) Сортировка по признакам отчетности" << endl;
			cout << "4) Сортировка по преподавателям" << endl;
			cout << "5) Сортировка по количеству часов" << endl;


			cin >> answ;

			if (answ == 1)
			{
				sortByCode(max);

			}

			if (answ == 2)
			{
				sortByNameDiscipline(max);
			}

			if (answ == 3)
			{
				sortByTest(max);
			}

			if (answ == 4)
			{
				sortByNameTeacher(max);
			}
			if (answ == 5)
			{
				sortByCountHours(max);
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