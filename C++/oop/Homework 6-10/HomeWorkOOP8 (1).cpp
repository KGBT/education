#include <iostream>
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
		this->str = new char[strlen(str.str)+1];
		strcpy_s(this->str, strlen(str.str) + 1, str.str);
		this->length = str.length;
	}
	String(String&& str) noexcept : str{ str.str }, length{str.length} {
		str.str = nullptr;
		str.length = 0;
		cout << "Отработал конструктор перемещения." << endl;
	}
	~String();

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
		cout << "Деструктор" << endl;
	}


}
int String::countStr{ 0 };
String StringFactory(int strSize) {
	String str{ strSize };
	str.InputStr();
	return str;
}


class DynArray
{
private:
	int* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP } {
		cout << "Массив создан для " << this << " размером " << size << endl;

	}
	DynArray() :DynArray(5) {}
	DynArray(const DynArray& object) : arr{ new int[object.size] }, size{ object.size } {
		for (int i = 0; i < object.size; i++)
		{
			*(arr + i) = *(object.arr + i);
		}
		cout << "Массив скопирован с помощью конструктора для " << this << " размером " << size << endl;
	}

	DynArray(DynArray&& object) noexcept : arr{ object.arr }, size{ object.size } {
		object.arr = nullptr;
		object.size = 0;
		cout << "Массив перемещен консруктором для " << this << " размером " << size << endl;
	}

	DynArray& operator=(const DynArray& object) {
		if (this != &object)
		{
			if (size != object.size)
			{
				delete[]arr;
				arr = new int[object.size];

			}
			size = object.size;
			int* dest{ arr }; //указатель на начало массива назначения, то есть куда
			int* src{ object.arr }; //указатель на массив откуда копировать 
			int* const end{ arr + size }; //указатель на конец массива
			while (dest < end)
			{
				*dest++ = *src++; //копирует элементы

			}

		}
		cout << "Массив скопирован с помощью = для " << this << " размером " << size << endl;
		return *this; //проверить на dest
	}
	int getElement(int idx) {
		return *(arr + idx);
	}
	void setElement(int idx, int el) {
		*(arr + idx) = el;
	}
	void print() {
		for (int i = 0; i < size; i++)
		{
			cout << *(arr + i) << " ";
		}
	}
	void random() {
		for (int i = 0; i < size; i++)
		{
			*(arr + i) = rand() % 10;
		}
	}
	~DynArray();

private:

};

DynArray::~DynArray()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}

DynArray ArrayFactory(int arrSize) {
	DynArray arr{ arrSize };
	arr.random();
	return arr;
}


int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "Домашнее задание ООП 8.1\n";
	String str1;
	cout << (str1.getStr() != nullptr ? str1.getStr() : "nullptr") << endl;
	str1.setStr("Абракадабра");
	cout << (str1.getStr() != nullptr ? str1.getStr() : "nullptr") << endl;
	String str2{ StringFactory(10) };
	cout << "Строка str2: " << str2.getStr() << endl;
	std::cout << endl << "Домашнее задание ООП 8.2\n";
	DynArray ar1{ ArrayFactory(10) };
	cout << "Массив arr1 элементы: " << endl;
	ar1.print();
	DynArray ar2;
	ar2 = ar1;
	cout << "Массив arr2 элементы: " << endl;
	ar2.print();
	DynArray ar3(ar2);
	cout << "Массив arr3 элементы: " << endl;
	ar3.print();
}
