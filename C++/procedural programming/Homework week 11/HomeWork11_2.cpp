#include <iostream>
using namespace std;

template<typename data>
void InitArr(data arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101;
		
	}
}

template<typename data>
void ShowArr(data arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		
	}
}

template<typename data>
int LinearSearch(data arr[], int size, int key) {
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			return i;
		}
		
	}
	return -1;
}

template<typename data>
void SortArr(data arr[], int size) {
	
	int k;
	data min;
	for (int i = 0; i < size; i++)
	{
		k = i;
		min = arr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				k = j;
			}
		}
		if (k!=i)
		{
			arr[k] = arr[i];
			arr[i] = min;
		}
	}

}
template<typename data>
int Bin_search(data arr[], int size, int key) {

	int intermediate, lowInter = 0, upperInter = size - 1;
	while (true)
	{
		intermediate = (upperInter + lowInter) / 2;
		if (key == arr[intermediate])
		{
			return intermediate;
		}
		else if (lowInter > upperInter)
			return -1;
		else if (key > arr[intermediate])
			lowInter = intermediate + 1;
		else
			upperInter = intermediate - 1;
	}
}

int Dec(int numTwo) {
	int result = 0, i = 0;
	while (numTwo != 0)
	{

		result += numTwo % 10 * pow(2, i);
		i++;
		numTwo = numTwo / 10;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	/*
	const int size = 50;
	int key, element;
	int arr[size];
	cout << "Домашнее задание 11.1\n" << endl;
	InitArr(arr, size);
	ShowArr(arr, size);
	cout << endl;
	cout << "Введите искомый элемент: ";
	cin >> key;

	element = LinearSearch(arr, size, key);

	if (element != -1)
	{
		cout << "Искомый элемент найден! Номер элемента: " << element << endl;
	}
	else
		cout << "Искомый элемент не найден!" << endl;
	
	
	cout << "Домашнее задание 11.2\n" << endl;
	const int size = 50;
	int key, element;
	int arr[size];
	InitArr(arr, size);
	ShowArr(arr, size);
	cout << endl << endl;
	SortArr(arr, size);
	ShowArr(arr, size);
	cout << endl;
	cout << "Введите искомый элемент: ";
	cin >> key;
	element = Bin_search(arr, size, key);
	if (element != -1)
	{
		cout << "Искомый элемент найден! Номер элемента: " << element << endl;
	}
	else
		cout << "Искомый элемент не найден!" << endl;
	*/

	int numTwo = 0, numTen = 0;
	cout << "Домашнее задание 11.2\n" << endl;
	cout << "Введите число в двоичной системе счисления: ";
	cin >> numTwo;
	numTen = Dec(numTwo);
	cout << "Число " << numTwo << " в десятичной системе счисления " << numTen << endl;

}
