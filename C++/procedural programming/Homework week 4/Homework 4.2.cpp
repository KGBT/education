#include <iostream>
using namespace std;

int main()
{
	/*
	int colPizza = 0, colNapitok = 0, idPizza = 0, idNapitok = 0; //Количество и id пиццы и напитков
	double sumPizza = 0, sumNapitkov = 0, totalSum = 0, costPiz = 0, costNap = 0; //Суммы 

	string tempPiz, tempNap; //Переменные необходимые для вывода наименований

	double margarita = 10.5, //Цены на пиццы 
		gavaiskaya = 8.30,
		pepperoni = 15.95,
		diablo = 6.30;

	double kokaKola = 2.5, //Цены на напитки
		sprite = 0.75,
		merinda = 3.5;


	cout << " Home Task 4.2." << endl << endl;
	cout << "\tMenu" << endl << endl;
	cout << "\tPizza" << endl;
	cout << " 1 - margarita - 10.5$." << endl;
	cout << " 2 - gavaiskaya - 8.30$." << endl;
	cout << " 3 - pepperoni - 15.95$." << endl;
	cout << " 4 - diabolo - 6.30$." << endl << endl;
	cout << "\tNapitki" << endl;
	cout << " 1 - koka-kola - 2.5$." << endl;
	cout << " 2 - sprite - 0.75$." << endl;
	cout << " 3 - merinda - 1.5$." << endl << endl;

	cout << "Viberite pizza." << endl; //Ввод данных
	cin >> idPizza;
	cout << "Vvedite kolichestvo." << endl;
	cin >> colPizza;
	cout << "Viberite napitok." << endl;
	cin >> idNapitok;
	cout << "Vvedite kolichestvo." << endl;
	cin >> colNapitok;

	switch (idPizza) //Выбор пиццы 
	{
	case 1:
		sumPizza = margarita * colPizza;
		costPiz = margarita;
		tempPiz = "Margarita";
		break;
	case 2:
		sumPizza = gavaiskaya * colPizza;
		costPiz = gavaiskaya;
		tempPiz = "Gavaiskaya";
		break;
	case 3:
		sumPizza = pepperoni * colPizza;
		costPiz = pepperoni;
		tempPiz = "Pepperoni";
		break;
	case 4:
		sumPizza = diablo * colPizza;
		costPiz = diablo;
		tempPiz = "Diablo";
		break;

	default:
		cout << "Error! Takoi Pizza net v menu!" << endl;
		break;
	}

	switch (idNapitok) //Выбор напитков
	{
	case 1:
		sumNapitkov = kokaKola * colNapitok;
		costNap = kokaKola;
		tempNap = "Koka - cola";
		break;
	case 2:
		sumNapitkov = sprite * colNapitok;
		costNap = sprite;
		tempNap = "Sprite";
		break;
	case 3:
		sumNapitkov = merinda * colNapitok;
		costNap = merinda;
		tempNap = "Merinda";
		break;

	default:
		cout << "Error! Takogo Napitka net v menu!" << endl;
		break;
	}

	if (colPizza % 5 == 0) //Расчет скидки за 5 пицц
	{
		cout << "Super discount for you - every 5th pizza is free!" << endl;
		sumPizza -= costPiz * (colPizza / 5);
		
	}

	if ((costNap >= 2) && (colNapitok >= 3)) //Расчет скидки на напитки
	{
		cout << "You have a discount (15%) on drinks!" << endl;
		sumNapitkov -= sumNapitkov * 0.15;
	}

	if (sumNapitkov+sumPizza >= 50) //Расчет суммарной скидки
	{	
		cout << "You have a discount (20%) for the whole order!" << endl;
		totalSum = (sumNapitkov + sumPizza) * 0.8;
	}
	else {
		totalSum = sumNapitkov + sumPizza;
	}

	if ((idPizza > 0 && idPizza < 5) && (idNapitok > 0 && idNapitok < 4)) //Вывод чека
	{
		cout << "Your order:" << endl;
		cout << tempPiz << " - " << "kol: " << colPizza << " - " << sumPizza << " $" << endl;
		cout << tempNap << " - " << "kol: " << colNapitok << " - " << sumNapitkov << " $" << endl;
		cout << "Total: " << totalSum << " $" << endl;
	}
	*/

	double salaryMan1, salaryMan2, salaryMan3;
	const int salary = 200;
	double lvProd1, lvProd2, lvProd3;

	cout << "Vvedite lv prodaj 1 managera: ";
	cin >> lvProd1;
	cout << "Vvedite lv prodaj 2 managera: ";
	cin >> lvProd2;
	cout << "Vvedite lv prodaj 3 managera: ";
	cin >> lvProd3;

	if (lvProd1 < 500)
	{
		salaryMan1 = salary + lvProd1 * 0.03;
	}
	else if (lvProd1 >= 1000) {
		salaryMan1 = salary + lvProd1 * 0.08;
	}
	else {
		salaryMan1 = salary + lvProd1 * 0.05;
	}

	if (lvProd2 < 500)
	{
		salaryMan2 = salary + lvProd2 * 0.03;
	}
	else if (lvProd2 >= 1000) {
		salaryMan2 = salary + lvProd2 * 0.08;
	}
	else {
		salaryMan2 = salary + lvProd2 * 0.05;
	}

	if (lvProd3 < 500)
	{
		salaryMan3 = salary + lvProd3 * 0.03;
	}
	else if (lvProd3 >= 1000) {
		salaryMan3 = salary + lvProd3 * 0.08;
	}
	else {
		salaryMan3 = salary + lvProd3 * 0.05;
	}

	if (lvProd1>lvProd2 && lvProd1>lvProd3)
	{
		cout << "Luchshii menemger - 1! Poluchite premiu - 200$" << endl;
		salaryMan1 += 200;
	}
	else if (lvProd2 > lvProd3) {
		cout << "Luchshii menemger - 2! Poluchite premiu - 200$" << endl;
		salaryMan2 += 200;
	}
	else {
		cout << "Luchshii menemger - 3! Poluchite premiu - 200$" << endl;
		salaryMan3 += 200;
	}
	cout << "Salary 1 managera: " << salaryMan1 << endl;
	cout << "Salary 2 managera: " << salaryMan2 << endl;
	cout << "Salary 3 managera: " << salaryMan3 << endl;
}


