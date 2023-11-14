
#include <iostream>
#include<windows.h>
using namespace std;



template <typename Osn>
float Step(Osn num, int step) {
	
	float result = 1;

	if (step == 0)
	{
		return result;
	}
	
	if (step < 0)
	{
		for (int i = step; i < 0; i++)
		{
			result *= (float)1 / num;
		}
	}else
		for (int i = 1; i <= step; i++)
		{
			result *= num;
		}
	return result;
}

int Summ(int a, int b) {

	int result = 0;

	if (a>b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	for (int i = a + 1; i < b; i++)
	{
		result += i;
	}
	return result;
}

void Soversh(int a, int b) {

	int sumDel = 0;
	bool flag = false;

	if (a > b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}

	for (int i = a; i <= b; i++)
	{
		if (i == 0)
		{
			continue;
		}

		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sumDel += j;
			}
		}

		if (i == sumDel)
		{
			flag = true;
			cout << "Найдено совершенное число: " << i << endl;
		}
		sumDel = 0;
	}
	if (!flag)
	{
		cout << "Совершенного числа в диапазоне от " << a << " до " << b << " нет!" << endl;
	}
}

void Cards(int mast, char card) {

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if ((j == 0 || j == 10) && i != 0)
			{
				cout << "|";
			}
			else if ((i == 0 && j > 0 && j != 10) || (i == 11 && j > 0 && j != 10))
			{
				cout << "_";
			}

			else if ((i == 2 && j == 2) || (i == 10 && j == 8))
				cout << card;
			else if ((i == 6 && j == 5))
			{
				cout << (char)mast;
			} 
			else 
				cout << " ";
			
			
			
			
			
		}
		
		cout << endl;
	}


}

void LuckyNum(int num) {
	int ln1 = 0;
	int ln2 = 0;
	int count1 = 0, count2 = 0;
	while (count1 != 3)
	{
		ln1 += num % 10;
		num /= 10;
		count1++;
	}
	while (count2 != 3)
	{
		ln2 += num % 10;
		num /= 10;
		count2++;
	}
	if (ln1 == ln2)
	{
		cout << "Поздравляем! Число является счастливым!" << endl;
	}
	else
		cout << "Число не является счастливым!" << endl;
}

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	
	cout << "Домашнее задание 11.1" << endl;
	float osn;
	int step;
	cout << "Введите основание степени: ";
	cin >> osn;
	cout << "Введите степень: ";
	cin >> step;
	cout << Step(osn, step) << endl;
	
	
	cout << "Домашнее задание 11.2" << endl;  // В этом задании не указано о включении границы в диапазон или нет
	int a, b;
	cout << "Введите диапазон: ";
	cin >> a >> b;
	cout << Summ(a, b) << endl;
	
	/*

	cout << "Домашнее задание 11.3" << endl;
	int a, b;
	cout << "Введите диапазон: ";
	cin >> a >> b;
	Soversh(a, b);
	
	

	cout << "Домашнее задание 11.4" << endl;
		
	char card1, mast1;
	
	int option = 0;
	bool flag = false;
	
	cout << "\tВыберите масть" << endl;
	cout << "1 - пики ♠"  << endl;
	cout << "2 - трефы ♣"  << endl;
	cout << "3 - червы ♥"  << endl;
	cout << "4 - бубны ♦" << endl;

	do
	{
		cin >> option;
		switch (option)
		{
		case 1:
			mast1 = '♠';
			break;
		case 2:
			mast1 = '♣';
			break;
		case 3:
			mast1 = '♥';
			break;
		case 4:
			mast1 = '♦';
			break;
		default:
			cout << "Ошибка! Такой масти нет! Повторите ввод!" << endl;
			break;
		}
		if (option == 1 || option == 2 || option == 3 || option == 4)
		{
			break;
		}
	} while (true);
	cout << "\tДостоинства карт:" << endl;
	cout << "6, 7, 8, 9, 10, J, Q, K, A" << endl;
	cout << "Введите достоинство карты (колода 36 карт): ";
	cin >> card1;
	Cards(mast1, card1);
	*/

	int num, copyNum;
	int count;
	cout << "Домашнее задание 11.5" << endl;

	cout << "Введите 6-значное число: ";
	do
	{
		cin >> num;
		count = 0;
		copyNum = num;
		while (copyNum != 0)
		{
			copyNum /= 10;
			count++;
		}
		if (count == 6)
		{
			break;
		}
		else
			cout << "Ошибка! Введенное число не является 6-значным! Повторите ввод!" << endl;
	} while (true);
	
	LuckyNum(num);
	
}

