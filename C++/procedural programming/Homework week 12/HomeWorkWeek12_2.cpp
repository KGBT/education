#include <iostream>
using namespace std;

void InitMatrix(int arr[][5], const int rows, const int col) {
    
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 9 + 1;
		}
	}

}

void InitMatrix(char arr[][5], const int rows, const int col) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = (char)(rand() % (90-65) + 65);
		}
	}

}

void InitMatrix(double arr[][5], const int rows, const int col) {

	int low = 1;
	int high = 10;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
		}
	}

}

void PrintMatrix(int arr[][5], const int rows, const int col) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void PrintMatrix(char arr[][5], const int rows, const int col) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void PrintMatrix(double arr[][5], const int rows, const int col) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Maximum(int arr[][5], const int rows, const int col) {

	int max = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == j) && (max < arr[i][j]))
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

int Minimum(int arr[][5], const int rows, const int col) {

	int min = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == j) && (min > arr[i][j]))
			{
				min = arr[i][j];
			}
		}
	}
	return min;
}

char Maximum(char arr[][5], const int rows, const int col) {

	char max = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == j) && (max < arr[i][j]))
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

char Minimum(char arr[][5], const int rows, const int col) {

	char min = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == j) && (min > arr[i][j]))
			{
				min = arr[i][j];
			}
		}
	}
	return min;
}


double Maximum(double arr[][5], const int rows, const int col) {

	double max = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == j) && (max < arr[i][j]))
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

double Minimum(double arr[][5], const int rows, const int col) {

	double min = arr[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i == j) && (min > arr[i][j]))
			{
				min = arr[i][j];
			}
		}
	}
	return min;
}


void Sort(int arr[][5], const int rows, const int col) {

	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{

			for (int k = j + 1; k < col; k++)
			{
				if (arr[i][j] > arr[i][k])
				{
					int buffer = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = buffer;
				}
			}

		}
		
		
	}

}


void Sort(char arr[][5], const int rows, const int col) {


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{

			for (int k = j + 1; k < col; k++)
			{
				if (arr[i][j] > arr[i][k])
				{
					char buffer = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = buffer;
				}
			}

		}


	}

}


void Sort(double arr[][5], const int rows, const int col) {


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{

			for (int k = j + 1; k < col; k++)
			{
				if (arr[i][j] > arr[i][k])
				{
					double buffer = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = buffer;
				}
			}

		}


	}

}


int Delitel(int n, int m);
int Game(int number);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	/*
    cout << "Домашнее задание 12.1" << endl << endl;
	const int rows = 5;
	const int col = 5;
	int matx1[rows][col];
	char matx2[rows][col];
	double matx3[rows][col];


	cout << "Инициализация матриц: " << endl << endl;
	InitMatrix(matx1, rows, col);
	InitMatrix(matx2, rows, col);
	InitMatrix(matx3, rows, col);

	cout << "Вывод матриц: " << endl;
	PrintMatrix(matx1, rows, col);
	PrintMatrix(matx2, rows, col);
	PrintMatrix(matx3, rows, col);

	cout << "Максимальный элемент на главной диагонали: " << Maximum(matx1, rows, col) << endl;
	cout << "Минимальный элемент на главной диагонали: " << Minimum(matx1, rows, col) << endl;
	cout << "Максимальный элемент на главной диагонали: " << Maximum(matx2, rows, col) << endl;
	cout << "Минимальный элемент на главной диагонали: " << Minimum(matx2, rows, col) << endl;
	cout << "Максимальный элемент на главной диагонали: " << Maximum(matx3, rows, col) << endl;
	cout << "Минимальный элемент на главной диагонали: " << Minimum(matx3, rows, col) << endl << endl;

	Sort(matx1, rows, col);
	Sort(matx2, rows, col);
	Sort(matx3, rows, col);
	cout << "Отсортированные массивы: " << endl;
	PrintMatrix(matx1, rows, col);
	PrintMatrix(matx2, rows, col);
	PrintMatrix(matx3, rows, col);
	

	cout << "Домашнее задание 12.2" << endl << endl;
	cout << "Наибольший делитель: " << Delitel(4, 10) << endl;
	cout << "Наибольший делитель: " << Delitel(15, 60) << endl;
	cout << "Наибольший делитель: " << Delitel(100, 25) << endl;
	*/

	cout << "Домашнее задание 12.2" << endl << endl;
	int number = 1000 + rand() % (10000-1000+1);
	//cout << number << endl;
	cout << Game(number) << endl;

}


int Delitel(int n, int m) {

	if (n==m)
	{
		return n;
	}

	if (n>m)
	{
		return Delitel(n - m, m);
	}

	if (m>n)
	{
		return Delitel(n, m - n);
	}

}

int Game(int number) {

	int i = 1;
	int numUser;
	cout << "Введите четырехзначное число: ";
	cin >> numUser;

	int copyNumUs;
	int copyNumComp = number;
	int bufferComp;
	int bufferUser;

	int bull = 0;
	int cow = 0;

	if (numUser==number)
	{
		return i;
	}

	while (copyNumComp!=0)
	{
		copyNumUs = numUser;
		bufferComp = copyNumComp % 10;
		

		while (copyNumUs != 0)
		{
			bufferUser = copyNumUs % 10;
			
			if (bufferUser == bufferComp)
			{
				bull++;
				copyNumUs /= 10;
			}

			copyNumUs /= 10;
		}

		copyNumComp /= 10;
	}

	cout << "Количество быков: " << bull << endl;

	copyNumUs = numUser;
	copyNumComp = number;

	while (copyNumComp != 0)
	{
		bufferComp = copyNumComp % 10;
		bufferUser = copyNumUs % 10;

		if (bufferComp == bufferUser)
		{
			cow++;
			copyNumComp /= 10;
			copyNumUs /= 10;

		}

		copyNumComp /= 10;
		copyNumUs /= 10;

	}

	cout << "Количество коров: " << cow << endl;

	return i + Game(number);
}