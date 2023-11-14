#include <iostream>
#include <time.h>
using namespace std;

void InitArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		*arr++ = rand() % 10 + 1;
	}
}

void ShowMass(int* arr, int size) {

	for (int i = 0; i < size; i++)
	{
		cout << *arr++ << " ";
	}
	cout << endl;
}

void CopyMass(int* arr1, int* arr2, int size) {

	for (int i = 0; i < size; i++)
	{
		*arr2++ = *arr1++;
	}
}

void ReverseMass(int* arr, int size) {
	int temp = 0;
	for (int i = 0; i < size/2; i++)
	{
		temp = *(arr + i);
		*(arr + i) = *(arr + size-1 - i);
		*(arr + size-1 - i) = temp;
	}
}

void CopyRevMass(int* mass1, int* mass2, int size) {

	for (int i = 0; i < size; i++)
	{
		*mass2++ = *(mass1 + size - 1 - i);
	}


}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
    cout << "Домашнее задание 13.1" << endl;
	const int size = 10;
	int arr[size], mass[size];
	InitArr(arr, size); // инициализация массива
	cout << "Первый массив: " << endl;
	ShowMass(arr, size); //вывод массива
	CopyMass(arr, mass, size); //копирование массива
	cout << "Второй массив: " << endl;
	ShowMass(mass, size);
	
	cout << endl <<"Домашнее задание 13.2" << endl;
	int arr2[size];
	InitArr(arr2, size);
	cout << "Массив до преобразования: " << endl;
	ShowMass(arr2, size);
	ReverseMass(arr2, size); // обратный порядок
	cout << "Массив после преобразования: " << endl;
	ShowMass(arr2, size);

	cout << endl << "Домашнее задание 13.3" << endl;
	int massive1[size], massive2[size];
	InitArr(massive1, size);
	cout << "Первый массив: " << endl;
	ShowMass(massive1, size);
	CopyRevMass(massive1, massive2, size);
	cout << "Скопированный во второй массив массив: " << endl;
	ShowMass(massive2, size);
}
