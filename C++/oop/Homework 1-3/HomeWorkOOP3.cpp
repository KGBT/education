
#include <iostream>
using namespace std;

class String
{
private:
	static int countStr;
	char* str;
	int length;
public:
	String(const char* str1, int length) : str{ str1 ? new char[strlen(str1)+1] : nullptr}, length{length} {
		setCountStr();
		if (str)
		{
			strcpy_s(str, strlen(str1)+1, str1);
		}
	}
	String() : String{ nullptr, 80 } {}
	String(int length) : String{ nullptr, length } {}
	String(const char* str) : String{ str, strlen(str)} {}
	

	~String();

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
			strcpy_s(str, strlen(st) + 1, st);
		}
		else
		{
			str = new char[strlen(st)+1];
			
			strcpy_s(str, strlen(st) + 1, st);
			length = strlen(str);
		}
		
	}

private:
	static void setCountStr(){
		countStr++;
	}
};



String::~String()
{
	if (str != NULL)
	{
		delete[]str;
		cout << "Деструктор" << endl;
	}
		
	
}
int String::countStr { 0 };


int main()
{
	setlocale(LC_ALL, "ru");
    std::cout << "Hello World!\n";
	
	
	
	cout << "Объектов строк: " << String::getCountStr() << endl;
	cout << endl;
	String str1; //по умолчанию 80 символов
	str1.PrintLeng();
	cout << endl;
	str1.InputStr(); //вводим строку 
	cout << "Введенная строка: " << endl;
	str1.PrintStr(); //выводим строку
	cout << " ";
	str1.PrintLeng(); //выводим длину строки
	cout << endl << endl;

	String str2(3); // строка произвольной длины
	str2.PrintLeng();
	cout << endl;
	str2.InputStr(); //вводим строку 
	cout << "Введенная строка: " << endl;
	str2.PrintStr(); //выводим строку
	cout << " ";
	str2.PrintLeng(); //выводим длину строки
	cout << endl << endl;

	String str3("Хихихи");
	str3.PrintLeng();
	cout << " ";
	str3.PrintStr();
	cout << endl;
	cout << "Объектов строк: " << String::getCountStr() << endl;
}
