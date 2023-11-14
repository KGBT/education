#include <iostream>
#include <time.h>
using namespace std;
#define sleshN ("\n")



void ArrayCreation(int* &mass , int size) {
	mass = new int[size];
	
}


void InitArray(int* arr, int size) {

	for (int i = 0; i < size; i++)
	{
		*arr++ =  rand() % 40 - 20;
	}
}


void PrintArray(int* arr, int size) {
	
	for (int i = 0; i < size; i++)
	{
		cout << *arr++ << " ";
	}
	cout << sleshN;
}



void AddElement(int* &arr, int &size,int el) {
	size++;

	int* buffer = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(buffer + i) = *(arr + i);
	}
	*(buffer + size - 1) = el;

	delete[] arr;

	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(buffer + i);
	}
	delete[] buffer;
	
	
}

void AddElement(int* &arr, int& size, int el, int key) {

	size++;

	int* buffer = new int[size];

	for (int i = 0; i <= size - key; i++)
	{
		*(buffer+size-i) = *(arr+size-1-i);
		
	}

	*(buffer + key - 1) = el;

	for (int i = 0; i < key-1; i++)
	{
		*(buffer + i) = *(arr + i);
	}

	delete[] arr;

	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(buffer + i);
	}
	
	delete[] buffer;
	
}
void DeleteElement(int* &arr, int& size, int key) {

	size--;

	int* buf = new int[size];

	for (int i = 0; i < key-1; i++)
	{
		*(buf + i) = *(arr + i);
	}
	
	for (int i = key-1; i < size; i++)
	{
		*(buf + i) = *(arr + i + 1);
	}
	
	delete[] arr;

	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(buf + i);
	}
	
	delete[] buf;

}

void ArrayDelete(int* arr) {

	delete[] arr;

}


void DeleteSimple(int*& arr, int &size) {

	int k = 0; //количество простых чисел
	bool flag;

	for (int i = 0; i < size; i++) //считаем количество простых чисел + 0 
	{

		flag = true;

		
		for (int j = 2; j < abs(*(arr + i)); j++)
		{
			if (*(arr + i) % j == 0)
			{
				flag = false;
				break;
			}
		}
				

		if (flag)
		{
			k++;
		}
	}
	
	int* buffer = new int[k];
	int j = 0;

	for (int i = 0; i < size; i++) //переносим составные числа
	{

		flag = false;

		
		for (int j = 2; j < abs(*(arr + i)); j++)
		{
			if (*(arr + i) % j == 0)
			{
				flag = true;
				break;
			}
		}
		
		

		if (flag)
		{
			*(buffer + j) = *(arr + i);
			j++;
		}
	}

	delete[] arr;

	size -= k;
	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(buffer + i);
	}

	delete[] buffer; // иногда при запуске программы вылазит ошибка, связанная с удалением массива
}




void Raspredelenie(int* arr, int size, int* &pPlus, int &k1, int* &pMinus, int &k2, int* &pZero, int &k3) {

	

	for (int i = 0; i < size; i++) //считаем количество элементов
	{
		if (*(arr+i) > 0)
		{
			k1++;
		}
		else if (*(arr + i) < 0) {
			
			k2++;
		}
		else
			k3++;
	}
	
	delete[] pPlus;
	delete[] pMinus;
	delete[] pZero;

	pPlus = new int[k1];
	pMinus = new int[k2];
	pZero = new int[k3];

	int j1 = 0, j2 = 0, j3 = 0;

	for (int i = 0; i < size; i++) //записываем элементы в новые массивы
	{
		if (*(arr + i) > 0)
		{
			*(pPlus + j1) = *(arr + i);
			j1++;
		}
		else if (*(arr + i) < 0) {

			*(pMinus + j2) = *(arr + i);
			j2++;
		}
		else
		{
			*(pZero + j3) = *(arr + i);
			j3++;
		}
	}
	
	
}





int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	/*
	int size = 10;
	int* mass;
	* cout << "Домашнее задание 14.1" << endl;
	ArrayCreation(mass, size); // функция создания массива
	cout << "Инициализация массива" << endl;
	InitArray(mass, size); // инициализация массива
	PrintArray(mass, size); // вывод массива
	cout << "Добавление элемента в конец массива" << endl;
	AddElement(mass, size, 100); // добавление элемента в конец массива
	PrintArray(mass, size);
	cout << "Добавление элемента по указанному индексу" << endl;
	AddElement(mass, size, 999, 3); // перегрузка метода, добавление по указанному индексу
	PrintArray(mass, size);
	cout << "Удаление элемента по указанному индексу" << endl;
	DeleteElement(mass, size, 5); // удаление элемента по указанному индексу
	PrintArray(mass, size);
	cout << "Удаление массива" << endl;
	ArrayDelete(mass); // удаление динамического массива
	PrintArray(mass, size);
	*/
	/*
	cout << "Домашнее задание 14.2" << endl;
	int size1 = 20;
	int* array = new int[size1];
	cout << "Массив до удаления простых чисел: " << endl;
	InitArray(array, size1);
	PrintArray(array, size1);
	cout << "Массив после удаления:" << endl;
	DeleteSimple(array, size1);
	PrintArray(array, size1);
	*/
	
	cout << "Домашнее задание 14.3" << endl;
	const int size = 40;
	int massive[size];
	int size1 = 0, size2 = 0, size3 = 0;
	int* pPlus = new int[size1];
	int* pMinus = new int[size2];
	int* pZero = new int[size3];
	
	cout << "Инициализация массива: " << endl;
	InitArray(massive, size);
	PrintArray(massive, size);
	cout << "Распределенные элементы: " << endl;
	Raspredelenie(massive, size, pPlus, size1, pMinus, size2, pZero, size3);
	
	
	PrintArray(pPlus, size1);
	PrintArray(pMinus, size2);
	PrintArray(pZero, size3);
}

