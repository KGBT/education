#include <iostream>
using namespace std;

class Overcoat
{
public:
	Overcoat(const char*, const char*, float);
	Overcoat();
	Overcoat(const char*);
	Overcoat(const char*, const char*);
	Overcoat(const char*, float);
	Overcoat(const Overcoat& object);
	~Overcoat();

	Overcoat& setType(const char* type) {
		
		if (this->type == nullptr)
		{
			this->type = new char[strlen(type) + 1];
		}
		strcpy_s(this->type, strlen(type) + 1, type);
		return *this;
	}
	Overcoat& setMatherial(const char* matherial) {
		if (this->matherial == nullptr)
		{
			this->matherial = new char[strlen(matherial) + 1];
		}
		strcpy_s(this->matherial, strlen(matherial) + 1, matherial);
		return *this;
	}
	Overcoat& setCost(float cost) {
		this->cost = cost;
		return *this;
	}

	char* getType() {
		return type;
	}
	char* getMatherial() {
		return matherial;
	}
	float getCost() {
		return cost;
	}

	friend bool operator==(const Overcoat& object1, const Overcoat& object2) {
		return !strcmp(object1.type, object2.type);
	}
	Overcoat& operator= (const Overcoat& object) {
		if (this == &object)
		{
			return *this;
		}
				
		if (type != nullptr)
		{
			delete[] type;
		}
		if (matherial != nullptr)
		{
			delete[] matherial;
		}

		if (object.type != nullptr)
		{
			type = new char[strlen(object.type) + 1];
			strcpy_s(type, strlen(object.type) + 1, object.type);
		}
		if (object.matherial != nullptr)
		{
			matherial = new char[strlen(object.matherial) + 1];
			strcpy_s(matherial, strlen(object.matherial) + 1, object.matherial);
		}
		cost = object.cost;
		return *this;
	}
	friend bool operator>(const Overcoat& ob1, const Overcoat& ob2) {
		return ob1.cost > ob2.cost;
	}

	void Print() {
		cout << "Тип одежды: " << (type == nullptr ? "Неизвестно." : type) << endl;
		cout << "Тип материала: " << (matherial == nullptr ? "Неизвестно." : matherial) << endl;
		cout << "Цена: " << cost << endl;
	}

private:
	char* type;
	char* matherial;
	float cost;

};
Overcoat::Overcoat(const char* type, const char* matherial, float cost) : type{ type ? new char[strlen(type) + 1] : nullptr },
matherial{ matherial ? new char[strlen(matherial) + 1] : nullptr }, cost{ cost } {
	
	if (type != nullptr)
	{
		setType(type);
	}
	if (matherial != nullptr)
	{
		setMatherial(matherial);
	}
}
Overcoat:: Overcoat() : Overcoat(nullptr, nullptr, 0){}
Overcoat::Overcoat(const char* type) : Overcoat(type, nullptr, 0) {}
Overcoat::Overcoat(const char* type, const char* matherial) : Overcoat(type, matherial, 0) {}
Overcoat::Overcoat(const char* type, float cost) : Overcoat(type, nullptr, cost) {}
Overcoat::Overcoat(const Overcoat& object) {
	setType(object.type);
	setMatherial(object.matherial);
	setCost(object.cost);
}
Overcoat::~Overcoat()
{
	if (type != nullptr)
	{
		delete[] type;
	}
	if (matherial != nullptr)
	{
		delete[] matherial;
	}
}


class Flat
{
public:
	Flat(float square, float cost) {
		setSquare(square);
		setCost(cost);
	}
	Flat() : Flat(0, 0) {}
	Flat(float square) : Flat(square, 0) {}
	Flat(const Flat& fl) {
		square = fl.square;
		cost = fl.cost;
	}
	~Flat() {}

	Flat& setSquare(float square) {
		this->square = square;
		return *this;
	}
	Flat& setCost(float cost) {
		this->cost = cost;
		return *this;
	}

	float getSquare() {
		return square;
	}
	float getCost() {
		return cost;
	}

	void Display() {
		cout << "Площадь квартиры: " << square << endl;
		cout << "Цена: " << cost << endl;
	}

	friend bool operator==(const Flat& ob1, const Flat& ob2) {
		return ob1.square == ob2.square;
	}
	friend bool operator> (const Flat& ob1, const Flat& ob2){
		return ob1.cost > ob2.cost;
	}
	Flat& operator=(const Flat& ob) {
		square = ob.square;
		cost = ob.cost;
		return *this;
	}
private:
	float square;
	float cost;
};

int main()
{
	setlocale(LC_ALL, "ru");
    std::cout << "Домашняя работа ООП 7.1\n";
	Overcoat ov;
	ov.setType("Пальто");
	Overcoat ov2("Рубаха", "Хлопок", 2000);
	Overcoat ov3(ov2);
	cout << "Проверка на равенство типов одежды (операция ==)." << endl;
	cout << "Объект ov2 и ov3: " << (ov2 == ov3 ? "типы равны." : "типы одежды не равны." )<< endl;
	cout << "Объект ov и ov2: " << (ov == ov2 ? "типы равны." : "типы одежды не равны.") << endl;
	cout << "Операцию присваивания одного объекта в другой(операция = )." << endl;
	Overcoat ov4;
	ov4 = ov;
	ov4.Print();
	ov4 = ov2;
	ov4.Print();
	cout << "Сравнение по цене двух пальто одного типа (операция>)." << endl;
	cout << "Объект ov и ov2: " << (ov > ov2 ? "стоимость первого объекта больше." : "стоимость второго объекта больше.") << endl;
	ov.setCost(3000);
	cout << "Объект ov и ov2: " << (ov > ov2 ? "стоимость первого объекта больше." : "стоимость второго объекта больше.") << endl;

	cout << endl;
	std::cout << "Домашняя работа ООП 7.2\n";
	Flat fl1;
	Flat fl2(26, 333333);
	fl1.Display();
	fl2.Display();
	cout << "Операцию присваивания одного объекта в другой (операция = )." << endl;
	fl1 = fl2;
	fl1.Display();
	fl2.Display();
	cout << "Проверка на равенство площадей квартир (операция == )." << endl;
	cout << "fl1 == fl2 " << (fl1 == fl2 ? "Площади квартир равны." : "Площади квартир не равны.") << endl;
	Flat fl3(33, 1500000);
	cout << "Сравнение двух квартир по цене (операция>)." << endl;
	cout << "fl1 > fl2 " << (fl1 > fl2 ? "Цена квартиры fl1 > fl2." : "Цена квартиры fl1 < fl2.") << endl;
}
