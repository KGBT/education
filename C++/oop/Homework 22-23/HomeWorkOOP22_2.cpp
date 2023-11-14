#include <iostream>
#include<fstream>
using namespace std;
class Exeption
{
public:
	Exeption() : exept{"Ошибка: "} {}
	virtual ~Exeption() = 0 {}
	virtual string getExept() = 0;
protected:
	string exept;

};

class MathEx : public Exeption
{
public:
	MathEx() : mathExept{"деление на 0! "} {}
	~MathEx() {};
	virtual string getExept() override {
		return exept + mathExept;
	}

private:
	string mathExept;
};

class MemoryEx : public Exeption
{
public:
	MemoryEx() : memoryExept{ "ошибка выделения памяти " } {}
	~MemoryEx() {};
	virtual string getExept() override {
		return exept + memoryExept;
	}
private:
	string memoryExept;
};

class FileEx:public Exeption
{
public:
	FileEx() : fileEx{"ошибка открытия файла! "} {}
	~FileEx() {}
	virtual string getExept() override {
		return exept + fileEx;
	}
	

private:
	string fileEx;
};


int main()
{
	setlocale(LC_ALL, "Rus");
    std::cout << "Домашняя работа ООП22.2\n";
	int a, b;
	double result;
	try
	{
		cout << "Вседите первое число: " << endl;
		cin >> a;
		cout << "Введите второе число: " << endl;
		cin >> b;
		if (!b)
		{
			throw MathEx{};
		}
	}
	catch (MathEx& ex)
	{
		cout << ex.getExept() << endl;
	}

	try
	{
		cout << "Ошибка выделения памяти: " << endl;
		int* numbers = nullptr; //имитация ошибки
		if (!numbers)
		{
			throw MemoryEx();
		}
	}
	catch (MemoryEx& ex)
	{
		cout << ex.getExept() << endl;
	}
	cout << "Ошибка открытия файла: " << endl;
	try
	{
		
		fstream file("C:\\1\\abrakadabra", ios::in);
		if (file.is_open())
		{
			cout << "Выполняем операции с файлом!" << endl;
		}
		else
		{
			throw FileEx();
		}
	}
	catch (FileEx& ex)
	{
		cout << ex.getExept() << endl;
	}
	cout << "Открываем файл!" << endl;
	try
	{
		fstream file("C:\\1\\fil3.txt", ios::in);
		if (file.is_open())
		{
			string str;
			while (!file.eof())
			{
				file >> str;
				cout << str << endl;
			}
		}
		else
		{
			throw FileEx();
		}
	}
	catch (FileEx& ex)
	{
		cout << ex.getExept() << endl;
	}
}
