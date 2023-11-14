#include <iostream>
using namespace std;

int main()
{  
	/*
	//Task 6.1
    int num1, num2, num3;
    int counter = 100, countKol = 0;
	cout << "Home Task 6.1" << endl;;
	while (counter<1000)
	{
		num1 = counter / 100;
		num2 = counter / 10 % 10;
		num3 = counter % 10;
		if (num1 == num2 && num1!=num3)
		{
			countKol++;
		}
		if (num1 == num3 && num1 != num2)
		{
			countKol++;
		}
		if (num2 == num3 && num2 != num1)
		{
			countKol++;
		}
		counter++;
	}
	cout << "Summa chisel: " << countKol << endl;
	

	//Task 6.2
	int number1, number2, number3;
	int sumKol = 0;
	cout << "Home Task 6.2" << endl;
	for (int i = 100; i < 1000; i++)
	{
		number1 = i / 100;
		number2 = i / 10 % 10;
		number3 = i % 10;
		if (number1 != number2 && number1 != number3 && number2 != number3)
		{
			sumKol++;
		}
				
	}
	
	cout << "Summa chisel: " << sumKol << endl;
	
	//Task 6.3
	int number, numBez36 = 0, temp, des = 1;
	cout << "Home Task 6.3" << endl;
	cin >> number;
	while (number != 0)
	{
		temp = number % 10;
		if (temp != 3 && temp != 6)
		{
			numBez36 += temp * des;

		}
		number = number / 10;
		des *= 10;
	}
	numBez36 != 0 ? cout << "Chislo bez chisel 3 i 6: " << numBez36 << endl : cout << "Ne udalos' udalit'" << endl;
	

	//Task 6.4
	cout << "Home Task 6.4" << endl;
	int a;
	cout << "Vvedite chislo a: ";
	cin >> a;
	cout << "Chisla B dlya kotorih A delit'sya bez ostatka: " << endl;
	for (int i = a-1; i >= 0; i--)
	{
		if (a % (i*i) == 0 && (a % (i * i * i) != 0))
		{
			cout << "B = " << i << endl;
		}
	}
	
	//Task 6.5
	cout << "Home Task 6.5" << endl;
	int num, sum = 0, temp;
	cout << "Vvedite chislo A: ";
	cin >> num;
	temp = num;
	while (temp != 0)
	{
		sum += temp % 10;
		temp /= 10;
	}
	if (pow(sum, 3) == pow(num,2))
	{
		cout << "Kub summi tsifr chisla " << num << " raven " << num * num << endl;
	}else
		cout << "Kub summi tsifr chisla " << num << " NE raven " << num * num << endl;
	
	//Task 6.
	cout << "Home Task 6.6" << endl;
	int number;
	cout << "Vvedite chislo: ";
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		if (number % i == 0)
		{
			cout << "Chislo " << number << " delit'sya bez ostatka na " << i << endl;
		}
	}
	*/
	//Task 6.7
	cout << "Home Task 6.7" << endl;
	int num1, num2, temp = 0, count = 1;
	cout << "Vvedite pervoe chislo: ";
	cin >> num1;
	cout << "Vvedite vtoroe chislo: ";
	cin >> num2;
	while (num1 != count)
	{
		count++;
		if (num1 % count == 0 && num2 % count == 0)
		{
			temp = count;
			cout << "Delitel' chisel " << num1 << " i " << num2 << ": " << temp << endl;
		}
	}
	if (temp == 0)
	{
		cout << "Obshego delitelya dlya chisel " << num1 << " i " << num2 << " krome 1 Net!" << endl;
	}
}

