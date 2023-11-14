#include <iostream>
using namespace std;
int main()
{
	/*
	//Task 7.1
	cout << "Home Task 7.1" << endl << endl;
	int number, choice, countNum = 0, sumNum = 0, count0 = 0;
	float sumSr = 0;
	cout << "Vvedite chislo: ";
	cin >> number;
	cout << endl;
	do {
		cout << "\tMenu" << endl;
		cout << "1 - kolichestvo tsifr v chisle." << endl;
		cout << "2 - summa chisel." << endl;
		cout << "3 - podschet srednego arifmeticheskogo." << endl;
		cout << "4 - kolichestvo nulei." << endl;
		cout << "5 - vihod." << endl << endl;
		cout << "Viberite punkt v menu: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			while (number != 0)
			{
				countNum++;
				number /= 10;

			}
			cout << "Kolichestvo tsifr v chisle: " << countNum << endl << endl;
			break;
		case 2:
			while (number != 0)
			{
				sumNum += number % 10;
				number /= 10;
			}
			cout << "Summa tsifr v chisle: " << sumNum << endl << endl;
			break;
		case 3:
			while (number != 0)
			{
				countNum++;
				sumNum += number % 10;
				number /= 10;

			}
			sumSr = (float)sumNum / countNum;
			cout << "Srednee arifmeticheskoe: " << sumSr << endl << endl;
			break;
		case 4:
			while (number != 0)
			{
				if (number % 10 == 0)
					count0++;
				number /= 10;
			}
			cout << "Kolichestvo 0 v chisle: " << count0 << endl << endl;
			break;
		case 5:
			cout << "Do vstrechi!" << endl;
			break;
		default:
			cout << "Error! Takogo punkta v Menu net!" << endl << endl;
			break;
		}
	} while (choice != 5);
	
	//Task 7.2
	cout << "Home Task 7.2" << endl << endl;
	int razmer;
	string sym1, sym2;
	cout << "Vvedite razmer kletochki: ";
	cin >> razmer;
	cout << endl;
	for (int i = 0; i < razmer; i++)
	{
		sym1 += "*";
		sym2 += "-";
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << sym1 << sym2;
		}
		cout << endl;
	}
	

	//Task 7.3
	cout << "Home Task 7.3" << endl << endl;
	int countClients, choiceSlad, choiceNap, exit, countSlad = 1, countNap = 1;
	double check = 0, sumSlad = 0, sumNap = 0,
		Muftochka = 6.95, Maffini = 5.36, Koltso = 3.52,
		Chai = 1, Sok = 1.5, Kofe = 2.5;
	cout << "Na skol'ko chelovek zakaz?" << endl;
	cout << "Vvedite colichestvo chelovek: ";
	cin >> countClients;
	cout << endl;
	do
	{
		while (true)
		{
			cout << "\tMenu blud:" << endl;
			cout << "1 - Muftochka - 6.95$." << endl;
			cout << "2 - Maffini - 5.36$." << endl;
			cout << "3 - Zavarnoe kol'tso - 3.52$." << endl;
			cout << "4 - Perehod k Menu napitkov." << endl << endl;
			cout << "Viberite punkt v Menu blud: ";
			cin >> choiceSlad;
			switch (choiceSlad)
			{
			case 1:
				cout << "Vvedite kolichestvo: ";
				cin >> countSlad;
				sumSlad += Muftochka * countSlad;
				cout << endl;
				break;
			case 2:
				cout << "Vvedite kolichestvo: ";
				cin >> countSlad;
				sumSlad += Maffini * countSlad;
				cout << endl;
				break;
			case 3:
				cout << "Vvedite kolichestvo: ";
				cin >> countSlad;
				sumSlad += Koltso * countSlad;
				cout << endl;
				break;
			case 4:
				cout << "Perehod k Menu napitkov." << endl << endl;

				break;
			default:
				cout << "Error! Takogo punkta v Menu net!" << endl;
				cout << "Povtorite vvod." << endl << endl;;
				sumNap = 0;
				sumSlad = 0;
				continue;
				break;
			}
			cout << "\tMenu napitkov:" << endl;
			cout << "1 - Chai - 1$." << endl;
			cout << "2 - Sok - 1.5$." << endl;
			cout << "3 - Kofe - 2.5$." << endl;
			cout << "4 - Perehod k Menu blud." << endl;
			cout << "5 - exit." << endl << endl;
			cout << "Viberite punkt v Menu napitkov: ";
			cin >> choiceNap;
			switch (choiceNap)
			{
			case 1:
				cout << "Vvedite kolichestvo: ";
				cin >> countNap;
				sumNap += Chai * countNap;
				cout << endl;
				break;
			case 2:
				cout << "Vvedite kolichestvo: ";
				cin >> countNap;
				sumNap += Sok * countNap;
				cout << endl;
				break;
			case 3:
				cout << "Vvedite kolichestvo: ";
				cin >> countNap;
				sumNap += Kofe * countNap;
				cout << endl;
				break;
			case 4:
				cout << endl;
				continue;
				break;
			case 5:
				break;
			default:
				cout << "Error! Takogo punkta v Menu net!" << endl;
				cout << "Povtorite zakaz." << endl << endl;
				sumNap = 0;
				sumSlad = 0;
				continue;
				break;
			}

			cout << "Hotite zakazat' chto-to eshe?" << endl;
			cout << "1 - Yes\t 2 - No" << endl;
			cin >> exit;
			cout << endl;
			if (exit == 1) {
				continue;
			}
			else if (exit == 2) {
				cout << "Next client!" << endl << endl;
				break;
			}
			else {
				cout << "Oshibka vvoda! Povtorite zakaz." << endl << endl;
				sumNap = 0;
				sumSlad = 0;
			}
		}
		check += sumNap + sumSlad;
		sumNap = 0;
		sumSlad = 0;
		countClients--;
	} while (countClients != 0);
	
	cout << "Chek na summu: " << check << endl;
	*/
	// Task 7.4
	cout << "Home Task 7.4" << endl << endl;
	char sym = 'A';
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << (char)(sym + j) << i << " ";
		}
		cout << endl;
	}
}

