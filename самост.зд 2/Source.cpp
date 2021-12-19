#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

int* inputArray(int*, int);
void printArray(int*, int);
void Num(int*, int);
int inputInt();
void NumLessThanDifference(int*, int);
void MaxLength(int*, int);
int menu();

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введите размер массива" << endl;
	int size = inputInt();
	int* Arr = new int[size];
	Arr = inputArray(Arr, size);
	printArray(Arr, size);
	while (true) {
		switch (menu())
		{
		case 1:
			Num(Arr, size);
			break;
		case 2:
			NumLessThanDifference(Arr, size);
			break;
		case 3:
	       MaxLength(Arr, size);
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
	return 0;
}

int* inputArray(int* arr, int size) 
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 - 5;
	}
	return arr;
}

void printArray(int* arr, int size) 
{
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i << "]=" << arr[i] << endl;
	}
}

void Num(int* arr, int size)
{
	cout << "Введите число для поиска в массиве" << endl;
	int num = inputInt();
	int flag = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num) 
		{
			flag = i;
			break;
		}
	}
	if (flag == -1)
	{
		cout << "Таких чисел нет" << endl;
	}
	else
	{
		cout << "Первое вхождение числа под индексом:" << flag << endl;
	}
}

void NumLessThanDifference(int* arr, int size) 
{
	cout << "Элементы массива, которые меньше разности двух предыдущих элементов" << endl;
	int flag = 0;
	for (int i = 2; i < size; i++)
	{
		if (arr[i] < (arr[i - 2] - arr[i - 1])) 
		{
			cout << "a[" << i << "]=" << arr[i] << endl;
		}
	}
	if (flag == 0) 
	{
		cout << "Таких элементов нет" << endl;
	}
}

void MaxLength(int* arr, int size) 
{
	int sequence = 0;
	int NowSequence = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			NowSequence++;
		}
		else 
		{
			sequence = NowSequence;
			NowSequence = 0;
		}
	}
	cout << "Длина максимальной последовательности одинаковых чисел в массиве: " << sequence << endl;
}

int inputInt()
{
	cout << "Введите число int" << endl;
	int num;
	while (!scanf_s("%d", &num))
	{
		system("cls");
		rewind(stdin);
		cout << "Введите целое число" << endl;
	}
	return num;
}

int menu()
{
	cout << "1)Поиск первого вхождения числа" << endl;
	cout << "2)Поиск всех чисел в массиве, которые меньше разности двух предыдущих " << endl;
	cout << "3)Поиск длины наибольшей последовательносии одинаковых чисел, идущих подряд" << endl;
	cout << "4)Выход из программы" << endl;
	int choice = inputInt();
	return choice;
}