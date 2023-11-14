#include <iostream>
using namespace std;
class Date
{
public:
	Date(int day, int month, int year);
	Date() = default;
	Date(int day);
	Date(int day, int month);
	Date(const Date& date);
	Date(const Date&& date) noexcept;
	~Date();

	Date& setDay(int day);
	Date& setMonth(int month);
	Date& setYear(int year);

	int getDay();
	int getMonth();
	int getYear();

	void PrintDate() {
		cout << day << "." << month << "." << year;
	}
	void IncreaseDay() {
		day++;
		if (day > dayArr[month-1])
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
	}

	Date& operator++() {
		++day;
		if (day > dayArr[month - 1])
		{
			day = day - dayArr[month - 1];
			++month;
		}
		++month;
		if (month > 12)
		{
			month = month - 12;
			++year;

		}
		++year;
		return *this;
	}
	Date operator++(int) {
		Date temp{*this};
		++(*this);
		return temp;
	}
	Date& operator--() {
		--day;
		if (day < 1)
		{
			--month;
			day = dayArr[month - 1] - day;

		}
		--month;
		if (month < 1)
		{
			--year;
			month = 12 - month;

		}
		--year;
		return *this;
	}
	Date operator--(int) {
		Date temp{ *this };
		--(*this);
		return temp;
	}
	friend bool operator!=(const Date& object1, const Date& object2);
	friend bool operator==(const Date& object1, const Date& object2);
	friend bool operator>(const Date& object1, const Date& object2);
	friend bool operator<(const Date& object1, const Date& object2);
	friend ostream& operator<<(ostream& output, const Date& object);
	friend istream& operator>>(istream& input, Date& object);
	Date& operator=(const Date& object) {
		if (this == &object)
		{
			return *this;
		}
		day = object.day;
		month = object.month;
		year = object.year;
		for (size_t i = 0; i < 12; i++)
		{
			dayArr[i] = object.dayArr[i];
		}
		return *this;

	}
	Date& operator+=(const Date& object) {
		day += object.day;
		if (day > dayArr[month - 1])
		{
			day = day - dayArr[month-1];
			month++;
		}
		month += object.month;
		if (month > 12)
		{
			month = month - 12;
			year++;
			
		}
		year += object.year;
		return *this;
	}
	Date& operator-=(const Date& object) {
		day -= object.day;
		if (day < 1)
		{
			month--;
			day = dayArr[month - 1] - day;
			
		}
		month -= object.month;
		if (month < 1)
		{
			year--;
			month = 12 - month;
			
		}
		year -= object.year;
		return *this;
	}
	Date& operator()() {
		IncreaseDay();
		return *this;
	}
private:
	int day;
	int month;
	int year;
	int dayArr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
};

Date::Date(int day, int month, int year){
	
	if (year != 0)
	{
		dayArr[1] += (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
	}
	if (day >= 1 && day <= dayArr[month-1])
	{
		this->day = day;
	}
	else
	{
		cout << "Невозможно установить день с текущим значением: " << day << ". Будет установлено значение по умолчанию(0)." << endl;
		this->day = 0;
	}
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		cout << "Невозможно установить месяц с текущим значением: " << month << ". Будет установлено значение по умолчанию(0)." << endl;
		this->month = 0;
	}
	if (year >= 0)
	{
		this->year = year;
	}
	else
	{
		cout << "Невозможно установить год с текущим значением: " << year << ". Будет установлено значение по умолчанию(0)." << endl;
		this->year = 0;
	}

}
Date::Date(int day) : Date{ day, 0, 0 } {}
Date::Date(int day, int month) : Date{ day, month, 0 } {}
Date::Date(const Date& date) {
	day = date.day;
	month = date.month;
	year = date.year;
}
Date::Date(const Date&& date) noexcept {
	day = date.day;
	month = date.month;
	year = date.year;
	for (size_t i = 0; i < 12; i++)
	{
		dayArr[i] = date.dayArr[i];
	}
}
Date::~Date()
{
}

Date& Date::setDay(int day) {

	if (day >= 0 && day <= dayArr[month-1])
	{
		this->day = day;
	}
	else
	{
		cout << "Невозможно установить текущую дату." << endl;
	}
	return *this;
 }
Date& Date::setMonth(int month) {
	if (month >= 0 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		cout << "Невозможно установить текущую дату." << endl;
	}
	return *this;
}
Date& Date::setYear(int year) {
	if (year >= 0)
	{
		this->year = year;
	}
	else
	{
		cout << "Невозможно установить текущую дату." << endl;
	}
	return *this;
}

int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}

bool operator!=(const Date& object1, const Date& object2) {
	return !(object1.day == object2.day &&
		object1.month == object2.month &&
		object1.year == object2.year);
}
bool operator==(const Date& object1, const Date& object2) {
	return object1.day == object2.day &&
		object1.month == object2.month &&
		object1.year == object2.year;
}
bool operator>(const Date& object1, const Date& object2) {
	return (object1.year > object2.year) ||
		(object1.year == object2.year && object1.month > object2.month) ||
		(object1.year == object2.year && object1.month == object2.month && object1.day > object2.day);
}
bool operator<(const Date& object1, const Date& object2) {
	return (object1.year < object2.year) ||
		(object1.year == object2.year && object1.month < object2.month) ||
		(object1.year == object2.year && object1.month == object2.month && object1.day < object2.day);
}
ostream& operator<<(ostream& output, const Date& object) {
	output << object.day << "." << object.month << "." << object.year;
	return output;
}
istream& operator>>(istream& input, Date& object) {
	input >> object.day;
	input >> object.month;
	input >> object.year;
	return input;
}

int main()
{
	setlocale(LC_ALL, "");
    std::cout << "Домашнее задание ООП10\n";
	Date date1(29, 2, 2012);
	Date date2(28, 2,2013);
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date2): " << date2 << endl;
	cout << "Функция, которая увеличивает день на 1." << endl;
	for (size_t i = 0; i < 4; i++)
	{
		date1.IncreaseDay();
		cout << date1 << endl;
	}
	cout << endl << "date1++: " << date1++ << endl;
	cout << "date1: " << date1 << endl;
	cout << "++date1: " << ++date1 << endl;
	cout << endl << "date1--: " << date1-- << endl;
	cout << "date1: " << date1 << endl;
	cout << "--date1: " << --date1 << endl;
	
	cout << endl << "date1 != date2: " << (date1 != date2 ? "Да." : "Нет.") << endl;
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date2): " << date2 << endl;
	Date date3(date1);

	cout << endl << "date1 == date3: " << (date1 == date3 ? "Да." : "Нет.") << endl;
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date3): " << date3 << endl;

	cout << endl << "date1 > date2: " << (date1 > date2 ? "Да." : "Нет.") << endl;
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date2): " << date2 << endl;

	cout << endl << "date1 < date2: " << (date1 < date2 ? "Да." : "Нет.") << endl;
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date2): " << date2 << endl;

	date2 = date1;
	cout << endl << "date2 = date1: " << date2 << endl;
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date2): " << date2 << endl;

	date2 += date1;
	cout << endl << "date2 += date1: " << date2 << endl;
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date2): " << date2 << endl;

	date2 -= date1;
	cout << endl << "date2 -= date1: " << date2 << endl;
	cout << "Дата(date1): " << date1 << endl;
	cout << "Дата(date2): " << date2 << endl;

	cout << endl << "date2: " << date2 << endl;
	cout << "date2(): " << date2() << endl;
	
}


