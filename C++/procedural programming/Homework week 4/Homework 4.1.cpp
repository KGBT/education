#include <iostream>
using namespace std;

int main()
{
    //Task 4.1
    /*
    int num, num1, num2, num3, num4, num5, num6; // Переменные для хранения разрядов чисел
    int sum1, sum2; // Переменные для хранения суммы первых трех и последних трех чисел
    cout << "Home Task 4.1" << endl;
    cout << "Vvedite chislo: ";
    cin >> num;
    if ((num / 100000 != 0) && (num / 100000 < 10)) { // Проверка на количество чисел
             
        num1 = num / 100000 % 10; // Разделение числа на разряды
        num2 = num / 10000 % 10;
        num3 = num / 1000 % 10;
        num4 = num / 100 % 10;
        num5 = num / 10 % 10;
        num6 = num % 10;
        sum1 = num1 + num2 + num3;
        sum2 = num4 + num5 + num6;

        if (sum1 == sum2) // Проверка числа на "Счастливость"
        {
            cout << "Vashe chislo schastlivoe!" << endl;
        }
        else
        {
            cout << "Vashe chislo ne schastlivoe!" << endl;
        }
    }
    else
           cout << "Error! Vi vveli ne 6-ti znachoe chislo!"; //Ошибка
            
    
    //Task 4.2
    cout << "Home Task 4.2" << endl;
    int num, num1, num2, num3, num4; //Переменные для хранения числа и его разрядов
    int sum; // Измененное число
    cout << "Vvedite chislo: ";
    cin >> num;
    if (num / 1000 != 0 && num / 1000 < 10) { // Проверка на количество цифр
        num1 = num / 1000 % 10; // Разделение на разряды
        num2 = num / 100 % 10;
        num3= num / 10 % 10;
        num4 = num % 10;
        sum = num2 * 1000 + num1 * 100 + num4 * 10 + num3; //Формирование измененного числа
        cout << "Izmenennoe chislo: " << sum;
    }
    else 
        cout << "Error! Vi vveli ne 4-h znachoe chislo!"; //Ошибка
    
    //Task 4.3
    int num1, num2, num3, num4, num5, num6, num7; // Числа
    int max; // Максимальное значение
    cout << "Home Task 4.3" << endl;
    cout << "Vvedite pervoe chislo: "; // Ввод чисел
    cin >> num1;
    cout << "Vvedite vtoroe chislo: ";
    cin >> num2;
    cout << "Vvedite tret'e chislo: ";
    cin >> num3;
    cout << "Vvedite chetvertoe chislo: ";
    cin >> num4;
    cout << "Vvedite pyatoe chislo: ";
    cin >> num5;
    cout << "Vvedite shestoe chislo: ";
    cin >> num6;
    cout << "Vvedite sed'moe chislo: ";
    cin >> num7;
    if (num1 > num2) // Проверка на максимум
        max = num1;
    else
        max = num2;
    if (num3 > max)
        max = num3;
    if (num4 > max)
        max = num4;
    if (num5 > max)
        max = num5;
    if (num6 > max)
        max = num6;
    if (num7 > max)
        max = num7;
    cout << "Naibol'shee iz chisel: " << max << endl;
    */

    //Task 4.4
    int rastAB, rastBC, weight, VDozap; // Данные вводимые пользователем и объем дозаправки
    const int VBaka = 300; // Объем бака
    const int rashod500 = 1, rashod1000 = 4, // Нормы расхода топлива в зависимости от веса груза
        rashod1500 = 7, rashod2000 = 9;
    cout << "Home Task 4.4" << endl;
    cout << "Vvedite rastoyanie ot A do B: ";
    cin >> rastAB;
    cout << "Vvedite rastoyanie ot B do C: ";
    cin >> rastBC;
    cout << "Vvedite ves gruza: ";
    cin >> weight;
    if (weight > 2000) { // Проверка на условия грузоподъемности более 2000 кг
        cout << "Samolet ne podnimaet takoi gruz!" << endl;
    }
    else {
        if ((weight < 500) && (rastAB * rashod500 <= 300) && (rastBC * rashod500 <= 300)) { //Проверка условия на вес груза и возможности пролететь расстояние с этим грузом
            if (rashod500 * (rastAB + rastBC) <= VBaka) //Если суммарный объем топлива расстояний А-В и В-С не превышает объем бака самолета 
                cout << "Dozapravka ne trebuetsya! Samolet doletit na odnoi zapravke!" << endl;
                    else {
                        VDozap = rashod500 * rastBC - (VBaka - rashod500 * rastAB);
                        cout << "Minimal'noe kolichestvo topliva dlya dozapravki: " << VDozap << endl;
                    }


        }else if ((weight < 1000) && (rastAB * rashod1000 <= 300) && (rastBC * rashod1000 <= 300)) { //Проверка условия на вес груза и возможности пролететь расстояние с этим грузом
            if (rashod1000 * (rastAB + rastBC) <= VBaka) //Если суммарный объем топлива расстояний А-В и В-С не превышает объем бака самолета 
                cout << "Dozapravka ne trebuetsya! Samolet doletit na odnoi zapravke!" << endl;
            else {
                VDozap = rashod1000 * rastBC - (VBaka - rashod1000 * rastAB);
                cout << "Minimal'noe kolichestvo topliva dlya dozapravki: " << VDozap << endl;
            }


        }else if((weight < 1500) && (rastAB* rashod1500 <= 300) && (rastBC* rashod1500 <= 300)) { //Проверка условия на вес груза и возможности пролететь расстояние с этим грузом
            if (rashod1500 * (rastAB + rastBC) <= VBaka) //Если суммарный объем топлива расстояний А-В и В-С не превышает объем бака самолета 
                cout << "Dozapravka ne trebuetsya! Samolet doletit na odnoi zapravke!" << endl;
            else {
                VDozap = rashod1500 * rastBC - (VBaka - rashod1500 * rastAB);
                cout << "Minimal'noe kolichestvo topliva dlya dozapravki: " << VDozap << endl;
            }


        }else if ((weight < 2000) && (rastAB * rashod2000 <= 300) && (rastBC * rashod2000 <= 300)) { //Проверка условия на вес груза и возможности пролететь расстояние с этим грузом
            if (rashod2000 * (rastAB + rastBC) <= VBaka) //Если суммарный объем топлива расстояний А-В и В-С не превышает объем бака самолета 
                cout << "Dozapravka ne trebuetsya! Samolet doletit na odnoi zapravke!" << endl;
            else {
                VDozap = rashod2000 * rastBC - (VBaka - rashod2000 * rastAB);
                cout << "Minimal'noe kolichestvo topliva dlya dozapravki: " << VDozap << endl;
            }

        }
        else
            cout << "Nevozmojno poletet' po vvedennomu marshrutu!" << endl;
                      
            
       
    }
    
    return 0;
}

