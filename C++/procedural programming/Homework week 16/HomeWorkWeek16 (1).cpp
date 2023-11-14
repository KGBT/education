#include <iostream>
#include <windows.h>
using namespace std;
int mystrcmp(const char*, const char*);
int StringToNumber(const char*);
char* NumberToString(const int);
char* Uppercase(char*); //возвращает указатель на строку
char* Lowercase(char*); //возвращает указатель на строку
char* mystrrev(char*);

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Домашнее задание 16.1" << endl;
	char str1[255] = { '\0' };
	char str2[255] = { '\0' };
	int num;
	cout << "Введите строку: ";
	cin >> str1;
	cout << "Введите строку: ";
	cin >> str2;
  	cout << "Измененная строка в верхнем регистре: " << Uppercase(str1) << endl;
	cout << "Измененная строка в нижнем регистре: " << Lowercase(str1) << endl;
	//cout << "Измененная строка: " << mystrrev(str1) << endl;
	
	cout << "Результат функции mystrcmp: " << mystrcmp(str1, str2) << endl;
	cout << "Результат функции strcmp: " << strcmp(str1, str2) << endl;
	cout << "Конвертированная строка " << str1 << " в число: " << StringToNumber(str1) << endl;
	cout << "Введите число: ";
	cin >> num;
	cout << "Конвертированное число " << num << " в строку: " << NumberToString(num) << endl;
}

int mystrcmp(const char* str1, const char* str2) {
	int i = 0;
	while ((*(str1+i) != '\0') || (*(str2 + i) != '\0'))
	{
		if (*(str1+i) > *(str2+i))
		{
			return 1;
		}
		else if(*(str1 + i) < *(str2 + i))
		{
			return -1;
		}
		i++;
	}
	return 0;
}

int StringToNumber(const char* str) {

	int number = 0;
	int razryad = 1;
	int lengthStr = strlen(str);

	for (int i = 0; i < lengthStr; i++)
	{
		if (*(str+i)<48 || *(str+i)>57)
		{
			return 0;
		}
	}

	for (int i = 0; i < lengthStr; i++)
	{
		
		number = number + (*(str + lengthStr - 1 - i) - 48) * razryad;
		razryad *= 10;
			
	}

	return number;
}

char* NumberToString(const int number) {

	int copyNumber = number;
	int count = 0, i = 0;
	int buffer = 0;
	while (copyNumber != 0)
	{
		count++;
		copyNumber /= 10;
	}
	copyNumber = number;
	char* str = new char[count] {};
	
	while (copyNumber != 0)
	{
		buffer = copyNumber % 10 + 48;
		*(str + count - 1 - i) = (char)buffer;
		copyNumber /= 10;
		i++;
		
	}
	*(str + count) = '\0';
	return str;
}

char* Uppercase(char* str) {

	for (int i = 0; i < strlen(str); i++)
	{
		
		if ((*(str+i)>=97 && *(str+i)<=122)) //для перевода строки на английском
		{
			*(str + i) = (int)*(str + i) - 32;
		}
		else if ((*(str + i) >= -32 && *(str + i) <= -1)) { //для перевода строки на русском
		
			*(str + i) = (int)*(str + i) - 32;

		}
		
	}
	return str;
}

char* Lowercase(char* str) {

	for (int i = 0; i < strlen(str); i++)
	{

		if ((*(str + i) >= 65 && *(str + i) <= 90)) //для перевода строки на английском
		{
			*(str + i) = (int)*(str + i) + 32;
		}
		else if ((*(str + i) >= -64 && *(str + i) <= -33)) { //для перевода строки на русском

			*(str + i) = (int)*(str + i) + 32;

		}

	}
	return str;


}

char* mystrrev(char* str) {

	char buffer;
	int leng = strlen(str);
	for (int i = 0; i < leng / 2; i++)
	{
		buffer = *(str + i);
		*(str + i) = *(str + leng - i - 1);
		*(str + leng - i - 1) = buffer;
	}
	return str;
}
