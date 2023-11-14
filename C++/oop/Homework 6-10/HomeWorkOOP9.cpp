#include <iostream>
#include <cassert>
using namespace std;

class String
{
private:
	static int countStr;
	char* str;
	int length;
public:
	String(const char* str1, int length) : str{ str1 ? new char[strlen(str1) + 1] : nullptr }, length{ length } {
		setCountStr();
		setStr(str1);
	}
	String() : String{ nullptr, 80 } {}
	String(int length) : String{ nullptr, length } {}
	String(const char* str) : String{ str, strlen(str) } {}
	String(const String& str) {
		this->str = new char[strlen(str.str) + 1];
		strcpy_s(this->str, strlen(str.str) + 1, str.str);
		this->length = str.length;
	}
	String(String&& str) noexcept : str{ str.str }, length{ str.length } {
		str.str = nullptr;
		str.length = 0;
		cout << "Отработал конструктор перемещения." << endl;
	}
	~String();

	char operator[](int inx) const {
		assert(inx >= 0 && inx <= length && "Выход за длину строки");
		return str[inx];
	}
	char& operator[](int inx) {
		assert(inx >= 0 && inx <= length && "Выход за длину строки");
		return str[inx];
	}
	String& operator= (String object) {
		if (!(this == &object))
		{
			delete[] str;
			str = object.str;
			length = object.length;

			object.str = nullptr;
			object.length = 0;
		}
		return *this;
	}
	int operator() (char sym) const {
		for (int i = 0; i < length; i++)
		{
			if (*(str+i) == sym)
			{
				return i;
			}
		}
		return -1;
	}

	int getLength() {
		return length;
	}
	char* getStr() {
		return str;
	}

	String& setStr(const char* str1) {
		if (str1 != nullptr)
		{
			delete[] str;
			str = new char[strlen(str1) + 1];
			strcpy_s(str, strlen(str1) + 1, str1);
			length = strlen(str1);
		}

		return *this;
	}

	static int getCountStr() {
		return countStr;
	}

	void PrintStr() {
		cout << str;
	}
	void PrintLeng() {
		cout << length;
	}
	void InputStr() {

		cout << "Введите строку: " << endl;
		char st[200];
		gets_s(st, 200);
		if (str != nullptr)
		{
			delete[] str;

		}
		str = new char[strlen(st) + 1];
		strcpy_s(str, strlen(st) + 1, st);
		length = strlen(str);

	}

private:
	static void setCountStr() {
		countStr++;
	}
};
String::~String()
{
	if (str != NULL)
	{
		delete[]str;
		
	}


}
int String::countStr{ 0 };
String StringFactory(int strSize) {
	String str{ strSize };
	str.InputStr();
	return str;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Домашнее задание ООП 9." << endl;
	String str1("Абракадабра");
	String str2("Утка");
	cout << "Строка str1: ";
	for (int i = 0; i < str1.getLength(); i++)
	{
		cout << str1[i];
	}
	cout << endl;
	cout << "Строка str2: ";
	str2.PrintStr();
	cout << endl;
	for (int i = 0; i < str2.getLength(); i++)
	{
		str1[i] = str2[i];
	}
	cout << "Измененная строка str1: ";
	for (int i = 0; i < str1.getLength(); i++)
	{
		cout << str1[i];
	}
	cout << endl;
	cout << "Искомый символ \"а\": " << str1('а') << endl;
	cout << "Искомый символ \"f\": " << str1('f') << endl;
}
