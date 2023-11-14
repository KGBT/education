#include <iostream>
#include <io.h>
#include <fstream>
using namespace std;

class Reservoir
{
public:
	//конструкторы
	Reservoir(const char*, const char*, float, float, float);
	explicit Reservoir();
	explicit Reservoir(const char* name);
	Reservoir(const char* name, const char* type);
	Reservoir(const char* name, const char* type, float width);
	Reservoir(const char* name, const char* type, float width, float length);
	
	//конструктор копирования
	Reservoir(const Reservoir&);

	//деструктор
	~Reservoir();

	//сеттеры
	Reservoir& setName(const char* name) {
		if (this->name == nullptr)
		{
			this->name = new char[strlen(name) + 1];
			
		}
		strcpy_s(this->name, strlen(name) + 1, name);
		return *this;
	}
	Reservoir& setType(const char* type) {
		if (this->type == nullptr)
		{
			this->type = new char[strlen(type) + 1];

		}
		strcpy_s(this->type, strlen(type) + 1, type);
		return *this;
	}
	Reservoir& setWidth(float width) {
		this->width = width;
		return *this;
	}
	Reservoir& setLength(float length) {
		this->length = length;
		return *this;
	}
	Reservoir& setDepth(float depth) {
		this->depth = depth;
		return *this;
	}

	//геттеры константные
	char* getName() const {
		return name;
	}
	char* getType() const {
		return type;
	}
	float getWidth() const {
		return width;
	}
	float getLength() const {
		return length;
	}
	float getDepth() const {
		return depth;
	}
	//геттеры неконстантные
	char* getName()  {
		return name;
	}
	char* getType()  {
		return type;
	}
	float getWidth()  {
		return width;
	}
	float getLength()  {
		return length;
	}
	float getDepth()  {
		return depth;
	}

	//методы класса
	float DefineVolume() const {
		return width * length * depth;
	}
	float DefineSquare() const {
		return width * length;
	}
	void Print() const {
		cout << "Название: " << (name != nullptr ? name : "Неизвестно")<< endl;
		cout << "Тип: " << (type != nullptr ? type : "Неизвестно") << endl;
		cout << "Ширина: " << width << endl;
		cout << "Длина: " << length << endl;
		cout << "Глубина: " << depth << endl;
	}
	float DefineVolume()  {
		return width * length * depth;
	}
	float DefineSquare()  {
		return width * length;
	}
	void Print() {
		cout << "Название: " << (name != nullptr ? name : "Неизвестно") << endl;
		cout << "Тип: " << (type != nullptr ? type : "Неизвестно") << endl;
		cout << "Ширина: " << width << endl;
		cout << "Длина: " << length << endl;
		cout << "Глубина: " << depth << endl;
	}
	static bool EqualType(Reservoir& ob1, Reservoir& ob2) {
		if (strcmp(ob1.type,ob2.type) == 0)
		{
			return true;
		}
		return false;
	}
	static int CompareSquare(Reservoir& ob1, Reservoir& ob2) {
		if (EqualType(ob1,ob2))
		{
			if (ob1.DefineSquare() == ob2.DefineSquare())
			{
				return 0;
			}
			if (ob1.DefineSquare() > ob2.DefineSquare())
			{
				return 1;
			}
			if (ob1.DefineSquare() < ob2.DefineSquare())
			{
				return -1;
			}
		}
		return -2; //если тип водоемов не совпадает, то возвращает -2
	}

private:
	char* name;
	char* type;
	float width; 
	float length;
	float depth;
};

//конструкторы
Reservoir::Reservoir(const char* name, const char* type, float width, float length, float depth) : name{ name ? new char[strlen(name) + 1] : nullptr }, 
type{ type ? new char[strlen(type) + 1] : nullptr }, width{ width }, length{ length }, depth{depth}
{
	if (name != nullptr)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	if (type != nullptr)
	{
		strcpy_s(this->type, strlen(type) + 1, type);
	}
}
Reservoir::Reservoir() : Reservoir(nullptr, nullptr, 0, 0, 0) {}
Reservoir::Reservoir(const char* name) : Reservoir(name, nullptr, 0, 0, 0) {}
Reservoir::Reservoir(const char* name, const char* type) : Reservoir(name, type, 0, 0, 0) {}
Reservoir::Reservoir(const char* name, const char* type, float width) : Reservoir(name, type, width, 0, 0) {}
Reservoir::Reservoir(const char* name, const char* type, float width, float length) : Reservoir(name, type, width, length, 0) {}

//конструктор копирования
Reservoir::Reservoir(const Reservoir& object) : name { object.name ? new char[strlen(object.name) + 1] : nullptr },
type{ object.type ? new char[strlen(object.type) + 1] : nullptr }, width{ object.width }, length{ object.length }, depth{ object.depth }
{
	if (name != nullptr)
	{
		strcpy_s(this->name, strlen(object.name) + 1, object.name);
	}
	if (type != nullptr)
	{
		strcpy_s(this->type, strlen(object.type) + 1, object.type);
	}
}

//деструктор
Reservoir::~Reservoir()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (type != nullptr)
	{
		delete[] type;
	}
}

void AddRes(Reservoir*& res, int& numb) {
	
	cout << "Добавление водоема." << endl;
	Reservoir* buf = new Reservoir[numb + 1];
	for (int i = 0; i < numb; i++)
	{
		buf[i].setName(res[i].getName());
		buf[i].setType(res[i].getType());
		buf[i].setWidth(res[i].getWidth());
		buf[i].setLength(res[i].getLength());
		buf[i].setDepth(res[i].getDepth());
	}
	delete[] res;
	res = buf;
	numb++;
	char str[100];
	float b;
	
	cout << "Введите название." << endl;
	gets_s(str);
	res[numb - 1].setName(str);
	cout << "Введите тип водоема." << endl;
	gets_s(str);
	res[numb - 1].setType(str);
	cout << "Введите ширину." << endl;
	cin >> b;
	cin.get();
	res[numb - 1].setWidth(b);
	cout << "Введите длину." << endl;
	cin >> b;
	cin.get();
	res[numb - 1].setLength(b);
	cout << "Введите глубину." << endl;
	cin >> b;
	cin.get();
	res[numb - 1].setDepth(b);
}
void PrintRes(Reservoir* res, int numb) {
	for (int i = 0; i < numb; i++)
	{
		cout << endl;
		res[i].Print();
	}
}
void DelRes(Reservoir*& res, int& numb) {
	
	cout << "Удаление водоема." << endl;

	Reservoir* buf = new Reservoir[numb - 1];
	int j = 0;
	char str[100]{};
	cout << "Введите название водоема: " << endl;
	gets_s(str);
	for (int i = 0; i < numb; i++)
	{
		if (strcmp(res[i].getName(), str) != 0)
		{
			buf[j] = res[i];
			j++;
		}
	}
	delete[] res;
	res = buf;
	numb--;

}
void SaveTxtRes(Reservoir* res, int numb) {
	
	FILE* file;
	char path[200] = "C:\\1\\";
	char str[100]{};
	cout << "Введите имя файла: " << endl;
	gets_s(str);
	if (strstr(str, "*.txt") == NULL)
	{
		
		strcat_s(path, strlen(path) + strlen(str) + 1, str);
		strcat_s(path, strlen(path) + strlen(".txt") + 1, ".txt");
	}
	else
	{
		strcat_s(path, strlen(str) + 1, str);
	}
	fopen_s(&file, path, "w");
	if (file == nullptr)
	{
		cout << "Не удалось создать файл." << endl;
	}
	else
	{
		for (int i = 0; i < numb; i++)
		{
			fputs(res[i].getName(), file);
			fputs("\n", file);
			fputs(res[i].getType(), file);
			fputs("\n", file);
			fprintf(file, "%f", res[i].getWidth());
			fputs("\n", file);
			fprintf(file, "%f", res[i].getLength());
			fputs("\n", file);
			fprintf(file, "%f", res[i].getDepth());
			fputs("\n", file);
			
		}
		cout << "Файл сохранен." << endl;
	}
	if (fclose(file) == EOF)
	{
		cout << "Не удалось закрыть файл." << endl;
	}
	else
	{
		cout << "Файл закрыт." << endl;
	}
}
void SaveBeRes(Reservoir* res, int numb) {

	ofstream fout;
	char path[200] = "C:\\1\\";
	char str[100]{};
	cout << "Введите имя файла: " << endl;
	gets_s(str);

	strcat_s(path, strlen(path) + strlen(str) + 1, str);

	fout.open(path, ofstream::binary);
					
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{
		for (int i = 0; i < numb; i++)
		{
			fout << res[i].getName();
			fout << "\n";
			fout << res[i].getType();
			fout << "\n";
			fout << res[i].getWidth();
			fout << "\n";
			fout << res[i].getLength();
			fout << "\n";
			fout << res[i].getDepth();
			fout << "\n";
		}
		cout << "Файл сохранен." << endl;
	}
	
	fout.close();
	
}
void Menu() {
	
	int numb = 0;
	Reservoir* res = new Reservoir[numb];
	int choice;
	do
	{
		cout << "Меню." << endl;
		cout << "1 - Добавить водоем." << endl;
		cout << "2 - Удалить водоем." << endl;
		cout << "3 - Запись в текстовый файл." << endl;
		cout << "4 - Запись в бинарный файл." << endl;
		cout << "5 - Вывод списка водоемов." << endl;
		cout << "6 - Выход." << endl;
		cin >> choice;
		cin.get();
		switch (choice)
		{
		case 1:
			AddRes(res, numb);
			break;
		case 2:
			DelRes(res, numb);
			break;
		case 3:
			SaveTxtRes(res, numb);
			break;
		case 4:
			SaveBeRes(res, numb);
			break;
		case 5:
			PrintRes(res, numb);
			break;
		case 6:
			break;
		default:
			cout << "Ошибка! Повторите ввод." << endl;
			break;
		}
	} while (choice != 6);
}

int main()
{
	setlocale(LC_ALL, "ru");
	Reservoir res1("Ивановское", "Озеро");
	res1.Print();
	Reservoir res2(res1);
	res2.Print();
	
	Reservoir res3("Петровское", "Море");
	res3.Print();
	cout << Reservoir::CompareSquare(res1, res2) << endl;
	cout << Reservoir::EqualType(res1, res2) << endl;
	cout << Reservoir::CompareSquare(res1, res3) << endl;
	cout << Reservoir::EqualType(res1, res3) << endl; 
	
	Menu();
}
