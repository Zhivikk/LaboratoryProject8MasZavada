// LaboratoryProject8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

//Глобальні змінні


int MinFromMax; // Мінімальне число з максимальних чисел 
const int M = 20; // Розміри Матриць
const int N = 20; 
const int N3 = 7;
int mas33[N3] /*= { 2, 3, -3, 8, 9, 3, 91 }*/;
int menu; // меню
int realM; // реальні розміри матриці
int realN; // реальні розміри матриці
int matr[M][N]; // оголошення матриці
const int MasN = 7;// реальні розміри матриці
int task1Arr[M];

//Глобальні Функції
int MaxFromColumn(int  in_matr[M][N], int column, int realM); // Максимальне Значення ЗІ всіх Колонок
void task1(void);  // Завдання 1
void task2(void);  // Завдання 2
void task3(void);  // Завдання 3
void task3Sort(int out_arr[], int n3);  // Сортування Завдання 1
void get_mas(string Filename, int in_mas[N], int& in_n);  // Массив З Файлу
void show_mas(string Filename, const int out_mas[N], const int out_n);  // Файл З Массиву
void get_matrix(string Filename, int in_mx[M][N], int& in_M, int& in_N);  // Матриця З Файлу
void show_matrix(string Filename, const int out_mx[M][N], const int m, const int n);  // Файл З Матриці
void show_variable(string Filename, int var);
int MinFMax(int in_mx[M][N], int realM, int realN);
void reverse_number(int in_out_mas[N], const int n);



void get_mas(string Filename, int in_mas[N], int& in_n)
{
	ifstream fin(Filename);
	if (fin.is_open())
	{
		fin >> in_n;
		for (int i = 0; i < in_n; i++)
		{
			fin >> in_mas[i];
		}
		fin.close();
	}
	else
	{
		cout << "Error Filereading!" << endl;
	}
}
void show_mas(string Filename, const int out_mas[N], const int out_n)
{
	ofstream fout(Filename);
	if (!fout.bad())
	{
		for (int i = 0; i < out_n; i++)
		{
			fout << out_mas[i] << " ";
		}
		fout << endl;
		fout.close();
	}
	else
	{
		cout << "Error Filereading!" << endl;
	}
}

void get_matrix(string Filename, int in_mx[M][N], int& in_M, int& in_N)
{
	ifstream fin(Filename);
	if (fin.is_open())
	{
		fin >> in_M;
		fin >> in_N;
		for (int i = 0; i < in_M; i++)
		{
			for (int j = 0; j < in_N; j++)
			{
				fin >> in_mx[i][j];
			}
		}
	}
	else
	{
		cout << "Error Filereading!" << endl;
	}
	
}

void show_variable(string Filename, int var)
{
	//cout << endl << "Matrix: " << endl;
	ofstream fout(Filename);
	if (!fout.bad())
	{
		fout << var;
		fout.close();
	}
	else
	{
		cout << "Error Filereading!" << endl;
	}
}


void reverse_number(int in_out_mas[N], const int n)
{
	
	int K, L;
	int i, j;
	restart:
	cout << "Enter K:"; // Введення K
	cin >> K;
	cout << endl;
	cout << "Enter L:"; // Введення L
	cin >> L;
	cout << endl;

	if ((K >= 1) && (K < L) && (L <= n))
	{

	}
	else
	{
		cout << "wrong number! Type Again." << endl;
		goto restart;
	}

	for (i = K + 1, j = L - 1; i < j; i++, j--)
	{

		int temp;
		temp = in_out_mas[j];
		in_out_mas[j] = in_out_mas[i];
		in_out_mas[i] = temp;
	}


}






void task1()
{
	// Декларація змінних
	int size1task;
	string inputFileName;
	string outFileName = "array_out_73.txt";
	cout << "Enter File Name: " << endl;
	cin >> inputFileName;
	get_mas(inputFileName, task1Arr, size1task);
	reverse_number(task1Arr, size1task);
	show_mas(outFileName, task1Arr, size1task);
}





int MaxFromColumn(int  in_matr[M][N], int column, int realM) // Функція знаходження максимального з колонки
{
	int max = in_matr[0][column];
	for (int rowNumber = 0; rowNumber < realM; rowNumber++)
	{
		if (in_matr[rowNumber][column] > max)
		{
			max = in_matr[rowNumber][column];
		}
	}
	return max;
}

int MinFMax(int in_mx[M][N], int realM, int realN )
{
	MinFromMax = MaxFromColumn(in_mx, 0, realM);
	int minColumn;
	for (int columnCounter = 0; columnCounter < realN; columnCounter++) // Ц
	{
		minColumn = MaxFromColumn(in_mx, columnCounter, realM);
		if (MinFromMax > minColumn)
		{
			MinFromMax = minColumn;
		}
	}
	return MinFromMax;
}

void task2() // Функція Першого Завдання
{
	// Декларація змінних
	int in_M;
	int in_N;
	int output;
	string inputFileName;
	string outFileName = "matr_in_28.txt";
	cout << "Enter File Name: " << endl;
	cin >> inputFileName;
	get_matrix(inputFileName, matr, in_M, in_N);
	output = MinFMax(matr, in_M, in_N);
	show_variable(outFileName, output);
}







void array_input(int in_arr[MasN], int& in_n)
{
	cout << "Count of elements: ";
	cin >> in_n;
	if (in_n > MasN)
	{
		cout << "Wrong number! Maximum is 50." << endl;

	}
	else
	{
		for (int i = 0; i < in_n; i++)
		{
			cin >> in_arr[i];
		}
	}
}

void task3Sort(int out_arr[], int n3)
{
	for (int i = 0; i < n3 - 1; ++i) 
	{
		for (int MasN = 0; MasN < n3 - i - 1; ++MasN) 
		{
			if (out_arr[MasN] > out_arr[MasN + 1]) 
			{
				// Обмін елементів
				int temp = out_arr[MasN];
				out_arr[MasN] = out_arr[MasN + 1];
				out_arr[MasN + 1] = temp;
			}
		}
	}	
}
void array_output(const int out_arr[], const int n3)
{
	cout << "Array elements: " << endl;
	for (int i = 0; i < n3; i++)
	{
		cout << out_arr[i] << " ";
	}
	cout << endl;
}
void task3()
{	
	int size3task;
	string inputFileName;
	string outFileName = "array_out_73.txt";
	cout << "Enter File Name: " << endl;
	cin >> inputFileName;
	get_mas(inputFileName, mas33, size3task);


	array_output(mas33, N3);
	task3Sort(mas33, size3task);
	array_output(mas33, N3);

}
int main()
{
	while (true)
	{


		cout << "Choose task:1,2 or 3:::";
		cin >> menu;
		switch (menu)
		{ // перемикання між завданнями
		case 1:
		{
			task1(); break; // Завдання 1
		}
		case 2:
		{
			task2(); break; // Завдання 2
		}
		case 3:
		{
			task3(); break; // Завдання 3
		}
		default: cout << "Wrong task! (Only 1,2,3)" << endl; //повідомлення про помилку
		}
		system("pause");

	}
	return 0;
}


