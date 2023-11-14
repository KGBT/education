#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
void PrintArr(int** Arr, const int rows, const int col) {
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void InitArr(int** Arr, const int rows, const int col) {
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Arr[i][j] = rand() % 10;
		}
	}

}
void AddCol(int**& Arr, const int rows, int& col, int position) {
	
	int** buffArr = new int* [rows];
	int i1 = 0, j1 = 0;
	col++;
	for (int i = 0; i < rows; i++)
	{
		*(buffArr + i) = new int[col];
	}

	for (int i = 0; i < rows; i++)
	{
		j1 = 0;
		for (int j = 0; j < col; j++)
		{
			if ((j == position - 1))
			{
				buffArr[i][j] = 0;
			}
			else {
				buffArr[i][j] = Arr[i1][j1++];
			}

		}
		i1++;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] * (Arr + i);
	}delete[] Arr;

	Arr = buffArr;
	buffArr = NULL;
	

}
void DeleteCol(int**& Arr, const int rows, int& col, int position) {

	int** buffArr = new int* [rows];
	int i1 = 0, j1 = 0;
	col--;
	for (int i = 0; i < rows; i++)
	{
		*(buffArr + i) = new int[col];
	}

	for (int i = 0; i < rows; i++)
	{
		j1 = 0;
		for (int j = 0; j < col+1; j++)
		{
			if ((j == position - 1))
			{
				continue;
			}
			else {
				buffArr[i1][j1++] = Arr[i][j];
			}

		}
		i1++;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] * (Arr + i);
	}delete[] Arr;

	Arr = buffArr;
	buffArr = NULL;


}

void UpArr(int** Arr, const int rows, const int col, const int shift) {
	
	int remember;

	for (int k = 0; k < shift; k++)
	{
		for (int i = 0; i < rows - 1; i++)
		{
			for (int j = 0; j < col; j++)
			{
				remember = Arr[i][j];
				Arr[i][j] = Arr[i + 1][j];
				Arr[i + 1][j] = remember;
			}
		}
	}

}
void DownArr(int** Arr, const int rows, const int col, const int shift) {

	int* buff = new int[col];
	
	for (int k = 0; k < shift; k++)
	{
		for (int i = 0; i < col; i++)
		{
			buff[i] = Arr[rows - 1][i];
		}
		for (int i = 0; i < rows - 1; i++)
		{
			for (int j = 0; j < col; j++)
			{
				Arr[rows - 1 - i][j] = Arr[rows - 2 - i][j];
			}
		}
		for (int i = 0; i < col; i++)
		{
			Arr[0][i] = buff[i];
		}
	}
	delete[] buff;
}
void LeftArr(int** Arr, const int rows, const int col, const int shift) {

	int remember;

	for (int k = 0; k < shift; k++)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				remember = Arr[i][j];
				Arr[i][j] = Arr[i][j + 1];
				Arr[i][j + 1] = remember;
			}
		}
	}

}
void RightArr(int** Arr, const int rows, const int col, const int shift) {

	int remember;

	for (int k = 0; k < shift; k++)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				remember = Arr[i][col - 1 - j];
				Arr[i][col - 1 - j] = Arr[i][col - 2 - j];
				Arr[i][col - 2 - j] = remember;
			}
		}
	}

}
void (*Menu(int** Arr, const int rows, const int col, int& shift))(int**, const int, const int, const int){
	
	enum Options
	{
		PRINT = 1,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		EXIT
	};

	void (*functions[])(int**, const int, const int, const int) = {UpArr, DownArr, LeftArr, RightArr};
	
	int choice;
	do
	{
		cout << "\tMenu" << endl;
		cout << "1 - Вывод массива." << endl;
		cout << "2 - Сдвиг массива вверх." << endl;
		cout << "3 - Сдвиг массива вниз." << endl;
		cout << "4 - Сдвиг массива влево." << endl;
		cout << "5 - Сдвиг массива вправо." << endl;
		cout << "6 - Выход." << endl;
		cout << "Выберите пункт меню." << endl;
		cin >> choice;
		switch (choice)
		{
		case PRINT:
			cout << "Массив: " << endl;
			PrintArr(Arr, rows, col);
			break;
		case UP:
			cout << "Сдвиг массива вверх." << endl;
			cout << "Введите количество сдвигов: " << endl;
			cin >> shift;
			return functions[0];
			break;
		case DOWN:
			cout << "Сдвиг массива вниз." << endl;
			cout << "Введите количество сдвигов: " << endl;
			cin >> shift;
			return functions[1];
			break;
		case LEFT:
			cout << "Сдвиг массива влево." << endl;
			cout << "Введите количество сдвигов: " << endl;
			cin >> shift;
			return functions[2];
			break;
		case RIGHT:
			cout << "Сдвиг массива вправо." << endl;
			cout << "Введите количество сдвигов: " << endl;
			cin >> shift;
			return functions[3];
			break;
		case EXIT:
			return NULL;
			cout << "Пока!" << endl;
			break;
		default:
			cout << "Ошибка! Повторите ввод!" << endl;
			break;
		}
	} while (choice != EXIT);

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int rows, col;
	int position;
	cout << "Введите количество строк в массиве: ";
	cin >> rows;
	cout << "Введите количество столбцов в массиве: ";
	cin >> col;
	cout << endl;
	int** Arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(Arr+i) = new int[col];
	}
	InitArr(Arr, rows, col);
	/*
	cout << "\tДомашнее задание 17.1" << endl;
	cout << "Исходный массив: " << endl;
	PrintArr(Arr, rows, col);
	cout << "Введите позицию для добавления столбца: ";
	cin >> position;
	AddCol(Arr, rows, col, position);
	cout << "Измененный массив: " << endl;
	PrintArr(Arr, rows, col);
	*/
	/*
	cout << "\tДомашнее задание 17.2" << endl;
	cout << "Исходный массив: " << endl;
	PrintArr(Arr, rows, col);
	cout << "Введите позицию для удаления столбца: ";
	cin >> position;
	DeleteCol(Arr, rows, col, position);
	cout << "Измененный массив: " << endl;
	PrintArr(Arr, rows, col);
	*/
	cout << "\tДомашнее задание 17.3" << endl;
	int shift = 0;
	void (*pMenu)(int**, const int, const int, const int);
	while (true)
	{
		pMenu = Menu(Arr, rows, col, shift);
		if (pMenu == NULL)
		{
			break;
		}
		pMenu(Arr, rows, col, shift);
	}
	
	for (int i = 0; i < rows; i++)
	{
		delete[] * (Arr + i);
	}delete[] Arr;
}

