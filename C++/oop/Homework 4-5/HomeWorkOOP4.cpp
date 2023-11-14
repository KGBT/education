#include <iostream>
using namespace std;

class Human
{
private:
	char* fio;
	
public:
	Human(const char*);
	//делегирование конструктора
	Human() : Human{ nullptr } {} 

	//конструктор копирования
	Human(const Human& object) : fio{ new char [ strlen(object.fio) + 1 ] } {
		strcpy_s(fio, strlen(object.fio) + 1, object.fio);
	}  

	//деструктор
	~Human(); 

	//сеттеры
	void setFio(const char* fio){
		this->fio = new char[strlen(fio)];
		this->fio = new char[strlen(fio) + 1];
		strcpy_s(this->fio, strlen(fio) + 1, fio);
	}

	//геттеры
	char* getFio() {
		return fio;
	}
};
Human::Human(const char* fio) {
		
}
Human::~Human()
{
	cout << "Удаление из Human" << endl;
	if (fio != nullptr)
	{
		delete[] fio;
		
	}
}


class Apartment
{
private:
		
	int floor;
	int numberAp; //номер квартиры
	int countPeople;
	Human* people;
public:
	Apartment(int, int, int);
	//делегирование конструктора
	Apartment() : Apartment{ 0, 0, 0} {}
	Apartment(int floor) : Apartment{ floor, 0, 0} {}
	Apartment(int floor, int countPeople) : Apartment{ floor, 0, countPeople } {}
		
	//конструктор копирования
	Apartment(const Apartment& object) : floor{ object.floor }, numberAp{ object.numberAp }, countPeople{ object.countPeople }, people{new Human[object.countPeople]} {
		for (int i = 0; i < countPeople; i++)
		{
			people[i] = object.people[i];
		}
	}

	//деструктор
	~Apartment();

	//сеттеры
	Apartment& setFloor(int floor) {
		this->floor = floor;
		return *this;
	}
	Apartment& setNumberAp(int numberAp) {
		this->numberAp = numberAp;
		return *this;
	}
	Apartment& setCountPeople(int countPeople) {
		delete[] people;
		people = new Human[countPeople];
		this->countPeople = countPeople;
		return *this;
	}
	Apartment& setHuman(int i, char* fio) {
		
		this->people[i].setFio(fio);
		return *this;
	}

	//геттеры
	int getFloor() {
		return floor;
	}
	int getNumberAp() {
		return numberAp;

	}
	int getCountPeople() {
		return countPeople;
	}
	Human& getHuman(int i) {
		return *(people+i);
	}
};
Apartment::Apartment(int floor, int numberAp, int countPeople) : floor{ floor }, numberAp{ numberAp }, countPeople{ countPeople }, people{ new Human[countPeople] } {
}
Apartment::~Apartment()
{
	cout << "Удаление из Apartment" << endl;
	if (people != nullptr)
	{
		delete[] people;
	}
}


class House
{
private:
	char* adress;
	int countAp;
	Apartment* ap;
public:
	House(const char*, int);
	//делегирование конструктора
	House() : House{ nullptr, 0} {}
	House(const char* adress) : House{ adress, 0} {}
	
	//конструктор копирования
	House(const House& object) : adress{ new char[strlen(object.adress)+1]}, countAp{object.countAp}, ap{new Apartment[object.countAp]} {
		strcpy_s(adress, strlen(object.adress) + 1, object.adress);
		for (int i = 0; i < countAp; i++)
		{
			ap[i] = object.ap[i];
		}
	}

	//деструктор
	~House();

	//сеттеры
	House& setAdress(const char* adress) {
		
		if (this->adress == nullptr)
		{
			this->adress = new char[strlen(adress) + 1];
			strcpy_s(this->adress, strlen(adress) + 1, adress);
		}
		else
		{
			strcpy_s(this->adress, strlen(adress) + 1, adress);
		}
		
		return *this;
	}
	House& setCountAp(int countAp) {

		delete[] ap;
		this->countAp = countAp;
		ap = new Apartment[countAp];
		return *this;
	}
	House& setAp(int floor, int numberAp, int countPeople) {
		
		ap[numberAp].setFloor(floor);
		ap[numberAp].setNumberAp(numberAp+1);
		ap[numberAp].setCountPeople(countPeople);
		return *this;
	}

	//геттеры
	char* getAdress() {
		return adress;
	}
	int getCountAp() {
		return countAp;
	}
	Apartment& getAp(int i) {
		return *(ap+i);
	}
};
House::House(const char* adress, int countAp) : adress{ adress ? new char[strlen(adress) + 1] : nullptr }, countAp{ countAp }, ap{ new Apartment[countAp] } {
	if (adress != nullptr)
	{
		strcpy_s(this->adress, strlen(adress) + 1, adress);
	}
}
House::~House()
{
	cout << "Удаление из House" << endl;
	if (adress != nullptr)
	{
		delete[]adress;
	}
	if (ap != nullptr)
	{
		delete[] ap;
	}
}


int main()
{
    setlocale(LC_ALL, "ru");
	int fl, countP;
	char fio[100];
	House h1;
	h1.setAdress("Пичугина 12");
	h1.setCountAp(2);
	cout << "Адрес дома: " << h1.getAdress() << endl;
	cout << "Количество квартир: " << h1.getCountAp() << endl;
	cout << "Введите данные квартир: " << endl;
	for (int i = 0; i < h1.getCountAp(); i++)
	{
		cout << "Введите этаж: " << endl;
	    cin >> fl;
		cout << "Введите количество людей в квартире номер " << i + 1 << ": " << endl;
		cin >> countP;
		gets_s(fio);
		h1.setAp(fl, i, countP);
		for (int j = 0; j < h1.getAp(i).getCountPeople(); j++)
		{
			cout << "Введите ФИО: ";
			gets_s(fio);
			h1.getAp(i).setHuman(j, fio);

		}
	}


	cout << endl << "Адрес дома: " << h1.getAdress() << endl;
	cout << "Количество квартир в доме: " << h1.getCountAp() << endl;
	cout << "Данные по квартирам: " << endl;

	for (int i = 0; i < h1.getCountAp(); i++)
	{
		cout << endl << "Этаж: " << h1.getAp(i).getFloor() << endl;
		cout << "Номер квартиры: " << h1.getAp(i).getNumberAp() << endl;
		cout << "Количество людей: " << h1.getAp(i).getCountPeople() << endl;
		for (int j = 0; j < h1.getAp(i).getCountPeople(); j++)
		{
			cout << "ФИО жильца: " << h1.getAp(i).getHuman(j).getFio() << endl;
			
			
		}
	}
	
	cout << "Скопированный дом: " << endl;
	House h2(h1);
	cout << endl << "Адрес дома: " << h1.getAdress() << endl;
	cout << "Количество квартир в доме: " << h1.getCountAp() << endl;
	cout << "Данные по квартирам: " << endl;

	for (int i = 0; i < h1.getCountAp(); i++)
	{
		cout << endl << "Этаж: " << h1.getAp(i).getFloor() << endl;
		cout << "Номер квартиры: " << h1.getAp(i).getNumberAp() << endl;
		cout << "Количество людей: " << h1.getAp(i).getCountPeople() << endl;
		for (int j = 0; j < h1.getAp(i).getCountPeople(); j++)
		{
			cout << "ФИО жильца: " << h1.getAp(i).getHuman(j).getFio() << endl;


		}
	}

}
