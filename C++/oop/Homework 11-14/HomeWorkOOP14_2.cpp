#include <iostream>
#include <time.h>
#include <string>
using namespace std;

class QueuePrinter
{
public:
	QueuePrinter() = delete;
	QueuePrinter(const QueuePrinter&) = delete;
	QueuePrinter(const QueuePrinter&&) = delete;
	explicit QueuePrinter(int);
	~QueuePrinter();

	bool isFull();
	bool isEmpty();
	void add(string);
	void add(string, int);
	string extract();
	int getCount();
	void clear();
	void printQueue();

private:
	const int FULL;
	string* fullName;
	int* priority;
	int queueLength;
};

QueuePrinter::QueuePrinter(const int FULL) : FULL{ FULL }, fullName{ new string[FULL] },
priority{ new int[FULL]}, queueLength{0} {}
QueuePrinter::~QueuePrinter()
{
	delete[] fullName;
	delete[] priority;
}

bool QueuePrinter::isFull() {
	return queueLength == FULL;
}
bool QueuePrinter::isEmpty() {
	return queueLength == 0;
}
void QueuePrinter::add(string fullName) {
	if (!isFull())
	{
		this->fullName[queueLength] = fullName;
		priority[queueLength] = rand() % 10 + 1;
		queueLength++;
	}
	else
	{
		cout << "Очередь заполнена." << endl;
	}
}
void QueuePrinter::add(string fullName, int priority) {
	if (!isFull())
	{
		this->fullName[queueLength] = fullName;
		this->priority[queueLength] = priority;
		queueLength++;
	}
	else
	{
		cout << "Очередь заполнена." << endl;
	}
}
string QueuePrinter::extract() {
	if (!isEmpty())
	{
		string temp = {};
		int el = 0;
		int max = priority[el];

		for (size_t i = 0; i < queueLength; i++)
		{
			if (max<priority[i])
			{
				el = i;
				max = priority[el];
			}
		}

		temp = fullName[el];

		for (size_t i = el; i < queueLength - 1; i++)
		{
			fullName[i] = fullName[i + 1];
			priority[i] = priority[i + 1];
		}
		queueLength--;
		return temp;
	}
	return "Очередь пуста.";
}
int QueuePrinter::getCount() {
	return queueLength;
}
void QueuePrinter::clear() {
	queueLength = 0;
}
void QueuePrinter::printQueue() {
	
	if (!isEmpty())
	{
		for (size_t i = 0; i < queueLength; i++)
		{
			cout << fullName[i] << " " << priority[i] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Очередь пуста." << endl;
	}
}






class QueueStatistic
{
public:
	QueueStatistic() = delete;
	QueueStatistic(const QueueStatistic&) = delete;
	QueueStatistic(const QueueStatistic&&) = delete;
	explicit QueueStatistic(int);
	~QueueStatistic();

	bool isFull();
	bool isEmpty();
	void add(string);
	void add(string, string);
	string extract();
	int getCount();
	void clear();
	void printQueue();

private:
	const int FULL;
	int queLength;
	string* fullName;
	string* time;
	
};

QueueStatistic::QueueStatistic(const int FULL) : FULL{ FULL }, queLength{ 0 }, fullName{ new string[FULL] }, time{ new string[FULL] } {}
QueueStatistic::~QueueStatistic()
{
	delete[] fullName;
	delete[] time;
}

bool QueueStatistic::isFull() {
	return queLength == FULL;
}
bool QueueStatistic::isEmpty() {
	return queLength == 0;
}
void QueueStatistic::add(string fullName) {
	if (!isFull())
	{
		this->fullName[queLength] = fullName;
		time[queLength] = std::to_string(rand() % 9 + 8) +
			":"+ std::to_string(rand() % 6)+ std::to_string(rand() % 9);
		queLength++;
	}
	else
	{
		cout << "Очередь пуста.";
	}
}
void QueueStatistic::add(string fullName, string time) {
	if (!isFull())
	{
		this->fullName[queLength] = fullName;
		this->time[queLength] = time;
		queLength++;
	}
}
string QueueStatistic::extract() {
	if (!isEmpty())
	{
		string temp = fullName[0];
		for (size_t i = 0; i < queLength - 1; i++)
		{
			fullName[i] = fullName[i + 1];
			time[i] = time[i + 1];
		}
		queLength--;
		return temp;
	}
	return "Очередь пуста.";
}
int QueueStatistic::getCount() {
	return queLength;
}
void QueueStatistic::clear() {
	queLength = 0;
}
void QueueStatistic::printQueue() {
	for (size_t i = 0; i < queLength; i++)
	{
		cout << fullName[i] << " " << time[i] << endl;
	}
}








int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
    std::cout << "Домашнее задание ООП14_2\n";
	QueuePrinter printer(9);
	QueueStatistic stat(9);
	string fullName;
	int priority;
	cout << "Введите трех заказчиков и приоритет: " << endl;
	for (size_t i = 0; i < 3; i++)
	{
		getline(cin, fullName);
		cin >> priority;
		cin.get();
		printer.add(fullName, priority);
	}
	printer.add("Василий", 6);
	printer.add("Иван");
	printer.add("Георгий", 4);
	printer.add("Никсон");
	printer.add("Артем");
	printer.add("Геннадий", 5);
	cout << endl;
	printer.printQueue();
	for (size_t i = 0; i < 9; i++)
	{
		stat.add(printer.extract());
	}
	//время генерирую через rand()
	cout << "Статистика печати: " << endl;
	stat.printQueue();
}
