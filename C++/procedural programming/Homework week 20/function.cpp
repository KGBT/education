
#include <iostream>
#include "function.h"
using namespace std;

void InitArrInt(int* arr, const int size) {
	
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 10 + 1;
	}

}
void InitArrFlo(float* arr, const int size) {

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = 1 + (10 - 1) * (float)rand() / (float)RAND_MAX;
	}

}
void InitArrCha(char* arr, const int size) {

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = (char)(rand() % (122-97) + 97);
	}
	*(arr + size) = '\0';
}

void PrintArrInt(int* arr, const int size) {
	
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
void PrintArrFlo(float* arr, const int size) {

	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
void PrintArrCha(char* arr) {

	cout << arr << endl;
}

int SearchArrIntMin(int* arr, const int size) {
	
	int min = *arr;

	for (int i = 0; i < size; i++)
	{
		if (min > *(arr+i))
		{
			min = *(arr + i);
		}
	}
	return min;
}
float SearchArrFloMin(float* arr, const int size) {

	float min = *arr;

	for (int i = 0; i < size; i++)
	{
		if (min > *(arr + i))
		{
			min = *(arr + i);
		}
	}
	return min;
}
char SearchArrChaMin(char* arr, const int size) {

	char min = *arr;

	for (int i = 0; i < size; i++)
	{
		if (min > *(arr + i))
		{
			min = *(arr + i);
		}
	}
	return min;
}

int SearchArrIntMax(int* arr, const int size) {

	int max = *arr;

	for (int i = 0; i < size; i++)
	{
		if (max < *(arr + i))
		{
			max = *(arr + i);
		}
	}
	return max;
}
float SearchArrFloMax(float* arr, const int size) {

	float max = *arr;

	for (int i = 0; i < size; i++)
	{
		if (max > *(arr + i))
		{
			max = *(arr + i);
		}
	}
	return max;
}
char SearchArrChaMax(char* arr, const int size) {

	char max = *arr;

	for (int i = 0; i < size; i++)
	{
		if (max < *(arr + i))
		{
			max = *(arr + i);
		}
	}
	return max;
}

void SortArrInt(int* arr, const int size) {

	int left = 0, rigth = size - 1;
	int buf;
	while (left <= rigth)
	{
		for (int i = rigth; i > left; --i)
		{
			if (arr[i - 1] > arr[i])
			{
				buf = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = buf;
			}
		}
		left++;
		for (int i = left; i < rigth; ++i)
		{
			if (arr[i + 1] < arr[i])
			{
				buf = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buf;
			}
		}
		rigth--;
	}

}
void SortArrFlo(float* arr, const int size) {

	float buff;
	int j;
	for (int i = 0; i < size; i++)
	{
		buff = *(arr + i);
		for (j = i - 1; j >= 0 && *(arr+j) > buff; j--)
		{
			*(arr + j + 1) = *(arr + j);
			
		}
		*(arr + j + 1) = buff;
	}

}
void SortArrCha(char* arr, const int size) {

	char buff;
	int k;
	for (int i = 0; i < size; i++)
	{
		buff = *(arr + i);
		k = i;
		for (int j = i + 1; j < size; j++)
		{
			if (buff > *(arr + j))
			{
				buff = *(arr + j);
				k = j;
			}
		}
		if (k!=i)
		{
			*(arr + k) = *(arr + i);
			*(arr + i) = buff;
		}
	}

}

void ChangeArrInt(int* arr, const int size) {
	
	int key;
	cout << "¬ведите позицию дл€ изменени€: ";
	cin >> key;
	cout << "¬ведите число: " << endl;
	cin >> *(arr + key - 1);
	cout << endl;
}
void ChangeArrFlo(float* arr, const int size) {

	int key;
	cout << "¬ведите позицию дл€ изменени€: ";
	cin >> key;
	cout << "¬ведите число: " << endl;
	cin >> *(arr + key - 1);
	cout << endl;
}
void ChangeArrCha(char* arr) {

	int key;
	char sym;
	cout << "¬ведите позицию дл€ изменени€: ";
	cin >> key;
	cout << "¬ведите символ: " << endl;
	cin >> sym;
	*(arr + key - 1) = sym;
	cout << endl;
}
