#include <iostream>
using namespace std;
struct ComplexNumber
{
    float Re;
    float Im;
};
void OutputNumber(ComplexNumber num) {

    if (num.Im == 0)
    {
        cout << num.Re << endl;
    }
    else if (num.Re == 0)
        cout << num.Im << "i" << endl;
    else
        cout << num.Re << "+" << num.Im << "i" << endl;

}
ComplexNumber SumNumber(ComplexNumber num1, ComplexNumber num2) {

    ComplexNumber newNumber;
    newNumber.Re = num1.Re + num2.Re;
    newNumber.Im = num1.Im + num2.Im;
    return newNumber;
}
ComplexNumber SubtrNumber(ComplexNumber num1, ComplexNumber num2) {

    ComplexNumber newNumber;
    newNumber.Re = num1.Re - num2.Re;
    newNumber.Im = num1.Im - num2.Im;
    return newNumber;
}
ComplexNumber MultNumber(ComplexNumber num1, ComplexNumber num2) {

    ComplexNumber newNumber;
    newNumber.Re = num1.Re * num2.Re - num1.Im * num2.Im;
    newNumber.Im = num1.Re * num2.Im + num2.Re * num1.Im;
    return newNumber;
}
ComplexNumber DivNumber(ComplexNumber num1, ComplexNumber num2) {

    ComplexNumber newNumber;
    newNumber.Re = 0;
    newNumber.Im = 0;
    if (num2.Re != 0 || num2.Im != 0)
    {
        newNumber.Re = (num1.Re * num2.Re + num1.Im * num2.Im) / (num2.Re * num2.Re + num2.Im * num2.Im);
        newNumber.Im = (num1.Im * num2.Re - num1.Re * num2.Im) / (num2.Re * num2.Re + num2.Im * num2.Im);
    }
    return newNumber;
}

struct Car
{
    int num = 0;
    int length = 0;
    int clearance = 0;
    float engineCapacity = 0;
    float enginePower = 0;
    int wheelDiameter = 0;
    string color = "Nan";
    string gearboxType = "Nan";
};
void InputCar(Car& car, int i) {
    car.num = i+1;
    cout << "Введите длину машины в мм: " << endl;
    cin >> car.length;
    cout << "Введите клиренс машины в мм: " << endl;
    cin >> car.clearance;
    cout << "Введите объем двигателя в литрах: " << endl;
    cin >> car.engineCapacity;
    cout << "Введите мощность двигателя в л.с.: " << endl;
    cin >> car.enginePower;
    cout << "Введите диаметр колес в мм: " << endl;
    cin >> car.wheelDiameter;
    cout << "Введите цвет машины: " << endl;
    cin >> car.color;
    cout << "Введите тип коробки передач: " << endl;
    cin >> car.gearboxType;
    cout << endl;

}
void OutputCar(Car car) {
    cout << "\tМашина под номером " << car.num << endl;
    cout << "Длина: " << car.length << " мм." << endl;
    cout << "Клиренс: " << car.clearance << " мм." << endl;
    cout << "Объем двигателя: " << car.engineCapacity << " л." << endl;
    cout << "Мощность двигателя: " << car.enginePower << " л.с." << endl;
    cout << "Диаметр колес: " << car.wheelDiameter << " мм." << endl;
    cout << "Цвет: " << car.color << endl;
    cout << "Тип коробки передач: "  << car.gearboxType << endl;
    cout << endl;
}
void SearchCarKey(Car car[], int countCars,float key) {
    
    bool flag = false;
    int pos;

    for (int i = 0; i < countCars; i++)
    {
        if (key - 1 == car->num)
        {
            flag = true;
            pos = i;
            break;
        }
    }
    if (flag)
    {
        cout << "Машина найдена!" << endl;
        OutputCar(car[pos]);
    }
    else {
        cout << "Не найдено!" << endl;
    }

}
void SearchCarColor(Car car[], int countCars, string key) {

    bool flag = false;
    int pos;

    for (int i = 0; i < countCars; i++)
    {
        if (key == car[i].color)
        {
            flag = true;
            pos = i;
            break;
        }
    }
    if (flag)
    {
        cout << "Машина найдена!" << endl;
        OutputCar(car[pos]);
    }
    else {
        cout << "Не найдено!" << endl;
    }

}
int main()
{
    setlocale(LC_ALL, "ru");
    /*
    cout << "Домашнее задание 18.1" << endl;
    ComplexNumber number1, number2, result;
    cout << "Введите действительную часть первого комплексного числа: " << endl;
    cin >> number1.Re;
    cout << "Введите мнимую часть первого комплексного числа: " << endl;
    cin >> number1.Im;
    cout << "Введите действительную часть второго комплексного числа: " << endl;
    cin >> number2.Re;
    cout << "Введите мнимую часть второго комплексного числа: " << endl;
    cin >> number2.Im;
    cout << "Вывод комплексных чисел: " << endl;
    OutputNumber(number1);
    OutputNumber(number2);
    cout << "Результат сложения комплексных чисел: " << endl;
    result = SumNumber(number1, number2);
    OutputNumber(result);
    cout << "Результат вычитания комплексных чисел: " << endl;
    result = SubtrNumber(number1, number2);
    OutputNumber(result);
    cout << "Результат умножения комплексных чисел: " << endl;
    result = MultNumber(number1, number2);
    OutputNumber(result);
    cout << "Результат деления комплексных чисел: " << endl;
    result = DivNumber(number1, number2);
    OutputNumber(result);
    */
    cout << "Домашнее задание 18.2" << endl;
    Car cars[3];
    for (int i = 0; i < 3; i++)
    {
        InputCar(cars[i], i);
    }
    for (int i = 0; i < 3; i++)
    {
        OutputCar(cars[i]);
    }
    SearchCarKey(cars, 3, 2);
    SearchCarColor(cars, 3, "Black");
}