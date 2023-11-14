#include <iostream>
#define tab "\t"
using namespace std;

template <typename data>
void InitArr(data arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

template <typename data>
void OutArr(data arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	/*
	cout << "Домашнее задание 9.1" << endl;
	const int size = 10;
	int mass[size];
	int mass1[size / 2];
	int mass2[size / 2];
	int k = 0;
	InitArr(mass, size);
	OutArr(mass, size);
	for (int i = 0; i < size / 2; i++)
	{
		mass1[i] = mass[k];
		k++;
	}
	for (int i = 0; i < size / 2; i++)
	{
		mass2[i] = mass[k];
		k++;
	}
	cout << endl;
	OutArr(mass1, size / 2);
	cout << endl;
	OutArr(mass2, size / 2);
	

	cout << "Домашнее задание 9.2" << endl; 
	const int size = 10;
	int mass[size];
	int mass1[size];
	int mass2[size];
	InitArr(mass1, size);
	OutArr(mass1, size);
	cout << endl;
	InitArr(mass2, size);
	OutArr(mass2, size);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		mass[i] = mass1[i] + mass2[i];
	}
	OutArr(mass, size);
	


	cout << "Домашнее задание 9.3" << endl;
	const int size = 7;
	int options;
	double rashod[size];
	double sredSum = 0;
	double totalSum = 0;
	int days = 0;
	string week[] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
	cout << "Введите данные о своих расходах: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << week[i] << ": ";
		cin >> rashod[i];
	}
	cout << tab << "Меню:" << endl;
	cout << "1 - средняя потраченная сумма" << endl;
	cout << "2 - общая потраченная сумма за неделю" << endl;
	cout << "3 - сумма расхода, превышающая 100$" << endl;
	cout << "4 - выход" << endl;

	do
	{
		cin >> options;
		switch (options)
		{
		case 1:
			
			
			for (int i = 0; i < size; i++)
			{
				sredSum += (double)rashod[i] / 7;
			}
			cout << "Средняя сумма потраченная за неделю: " << sredSum << endl;
			break;
		case 2:
			
			for (int i = 0; i < size; i++)
			{
				totalSum += rashod[i];
			}
			cout << "Общая сумма потраченная за неделю: " << totalSum << endl;
			break;
		case 3:
			cout << "Дни, когда сумма расхода больше 100$:" << endl;
			for (int i = 0; i < size; i++)
			{
				
				if (rashod[i] >= 100)
				{
					cout << week[i] << ": " << rashod[i] << "$" << endl;
					days++;
				}
			}
			if (days == 0)
			{
				cout << "Таких дней нет!" << endl;
			}
			cout << "Общее количество дней, когда сумма расхода превысила 100$: " << days << endl;
			break;
		case 4:
			break;
		default:
			cout << "Ошибка! Такого пункта в меню нет! Повторите ввод!" << endl;
			break;
		}
	} while (options != 4);
	*/

	cout << "Домашнее задание 9.4" << endl;
	const int mounth = 12;
	string moun[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
	double kurs[mounth];
	double percent[mounth];
	double shetVEvro, shetVDoll, nachSum;
	int nomMounth = 0;
	cout << "Введите курс доллара по отношению к евро: " << endl;
	for (int i = 0; i < mounth; i++)
	{
		cout << moun[i] << ": ";
		cin >> kurs[i];
	}
	cout << "Введите начисленные проценты на депозитном счету в евро: " << endl;
	for (int i = 0; i < mounth; i++)
	{
		cout << moun[i] << ": ";
		cin >> percent[i];
	}
	cout << "Введите сумму на депозите в евро:";
	cin >> shetVEvro;
	cout << "Введите номер месяца: ";
	cin >> nomMounth;
	nachSum = shetVEvro * percent[nomMounth - 1] / 100; //вычисляем начисленную сумму в евро
	shetVDoll = kurs[nomMounth - 1] * nachSum; //переводим начисленную сумму из евро в доллары
	if (shetVDoll >= 500) // проверяем условие, если больше или равно 500$
	{
		cout << "Вы можете обналичить " << (0.5 * shetVDoll) << "$" << endl; // обналичиваем 50% от начисленной суммы
	}
	else
		cout << "Вы не можете обналичить в этом месяце!" << endl;
}

