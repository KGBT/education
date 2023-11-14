
#include <iostream>
using namespace std;

void DeleteNum(char*, int);
void DeleteSym(char*, char);
void InsertSym(char*, char, int);
void ReplaceDots(char*);
int FindSym(char*, char);
void InfoStr(char*);
int main()
{
	setlocale(LC_ALL, "rus");
	/*
	cout << "Домашнее задание 15.1" << endl;
	char str[255];
	int number = 0;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Введите номер для удаления символа: ";
	cin >> number;
	DeleteNum(str, number);
	cout << "Строка после преобразования: " << str << endl;
	*/
	/*
	cout << "Домашнее задание 15.2" << endl;
	char str[255];
	char sym;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Введите символ для удаления: ";
	cin >> sym;
	DeleteSym(str, sym);
	cout << "Строка после преобразования: " << str << endl;
	*/

	/*
	cout << "Домашнее задание 15.3" << endl;
	char str[255];
	char sym;
	int num = 0;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Введите символ для вставки: ";
	cin >> sym;
	cout << "Введите номер позиции для вставки: ";
	cin >> num;
	InsertSym(str, sym, num);
	cout << "Строка после преобразования: " << str << endl;
	*/
	/*
	cout << "Домашнее задание 15.4" << endl;
	char str[255];
	cout << "Введите строку: ";
	cin >> str;
	ReplaceDots(str);
	cout << "Строка после преобразования: " << str << endl;
	*/
	/*
	cout << "Домашнее задание 15.5" << endl;
	char str[255];
	int counter = 0;
	char sym;
	cout << "Введите строку: ";
	cin >> str;
	cout << "Введите символ для поиска: ";
	cin >> sym;
	counter = FindSym(str, sym);
	cout << "Количество вхождений символа " << sym <<": " << counter<< endl;
	*/

	cout << "Домашнее задание 15.6" << endl;
	char str[255];
	cout << "Введите строку на английском: ";
	cin >> str;
	InfoStr(str);
	
}

void DeleteNum(char* str, int number) {
	
	char* remember = new char[strlen(str) - number] {'\0'};
	remember = (str + number);
	*(str + number - 1) = NULL;
	strcat_s(str, (strlen(str)-number), remember);
	
	//delete[] remember; //не удаляет массив, т к изменяет размер строки remember. Не знаю почему так происходит.
	
}

void DeleteSym(char* str, char sym) {

	char* remember = new char[(strlen(str))] {};
	int j = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (*(str+i) != sym)
		{
			*(remember + j) = *(str + i);
			j++;
		}
	}
	strcpy_s(str, 255, remember);
	delete[] remember;
}

void InsertSym(char* str, char sym, int position) {
	
	char* rem = new char[strlen(str)+2] {'\0'};
	int j = 0;

	for (int i = 0; i <= strlen(str)+1; i++)
	{
		if (i == position-1)
		{
			*(rem + i) = sym;
			
		}else{

			*(rem + i) = *(str + j++);
			
		}
	}

	cout << rem << endl;
	strcpy_s(str, 255, rem);
	delete[]rem;
}

void ReplaceDots(char* str) {
	char* pstr;
	for (int i = 0; i < strlen(str); i++)
	{
		if (pstr = strchr(str, '.'))
		{
			*pstr = '!';
		}
		else
			break;
	}
	
	
}

int FindSym(char* str, char sym) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (*(str+i) == sym)
		{
			count++;
		}
	}
	
	return count;
}

void InfoStr(char* str) {

	int countLetter = 0;
	int countNum = 0;
	int other = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if ((int)*(str+i) >= 48 && (int)*(str + i) <= 57)
		{
			countNum++;
		} else if (((int)*(str + i) >= 65 && (int)*(str + i) <= 90) || ((int)*(str + i) >= 97 && (int)*(str + i) <= 122))
		{
			countLetter++;
		}
		else
			other++;
					
	}

	cout << "Количество символов в строке: " << countLetter << endl;
	cout << "Количество цифр в строке: " << countNum << endl;
	cout << "Количество остальных символов в строке: " << other << endl << endl;

}