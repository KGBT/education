#include <iostream>
#include <Windows.h>
using namespace std;

class Fraction
{
public:
    /*
    Fraction();
	Fraction(int numer, int denom);
    */
    void setNumer(int numer);
    void setDenom(int denom);

    int getNumer();
    int getDenom();

    void sumFrac(int numer1, int denom1, int numer2, int denom2);
    void diffFrac(int numer1, int denom1, int numer2, int denom2);
    void multFrac(int numer1, int denom1, int numer2, int denom2);
    void divFrac(int numer1, int denom1, int numer2, int denom2);
    void printFract();
private:
    int numerator;
    int denominator;
};

/*
Fraction::Fraction() {};
Fraction::Fraction(int numer, int denom)
{
    numerator = numer;
    denominator = denom;
}
*/
void Fraction :: setNumer(int numer){
    numerator = numer;
}
void Fraction :: setDenom(int denom){
    
    if (denom == 0)
    {
        denominator = 1;
    }
    else
    {
        denominator = denom;
    }
}

int Fraction::getNumer() {
    return numerator;
}
int Fraction::getDenom() {
    return denominator;
}

void Fraction :: sumFrac(int numer1, int denom1, int numer2, int denom2){
        
    if (denom1 == denom2)
    {
        numerator = numer1 + numer2;
        denominator = denom1;
    }
    else
    {
        numer1 *= denom2;
        numer2 *= denom1;
        denominator = denom1 * denom2;
        numerator = numer1 + numer2;
    }
}
void Fraction::diffFrac(int numer1, int denom1, int numer2, int denom2) {

    if (denom1 == denom2)
    {
        numerator = numer1 - numer2;
        denominator = denom1;
    }
    else
    {
        numer1 *= denom2;
        numer2 *= denom1;
        denominator = denom1 * denom2;
        numerator = numer1 - numer2;
    }
}
void Fraction::multFrac(int numer1, int denom1, int numer2, int denom2) {

    numerator = numer1 * numer2;
    denominator = denom1 * denom2;
       
    
}
void Fraction::divFrac(int numer1, int denom1, int numer2, int denom2) {

    numerator = numer1 * denom2;
    denominator = numer2 * denom1;
}
void Fraction::printFract() {

    cout << numerator << "/" << denominator;
   
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Fraction fr1;
    fr1.setNumer(1);
    fr1.setDenom(2);

    Fraction fr2;
    fr2.setNumer(2);
    fr2.setDenom(3);

    Fraction fr3;

    cout << "Сложение дробей: " << endl;
    fr1.printFract();
    cout << " + ";
    fr2.printFract();
    cout << " = ";
    fr3.sumFrac(fr1.getNumer(), fr1.getDenom(), fr2.getNumer(), fr2.getDenom());
    fr3.printFract();
    cout << endl;

    cout << "Вычитание дробей: " << endl;
    fr1.printFract();
    cout << " - ";
    fr2.printFract();
    cout << " = ";
    fr3.diffFrac(fr1.getNumer(), fr1.getDenom(), fr2.getNumer(), fr2.getDenom());
    fr3.printFract();
    cout << endl;

    cout << "Умножение дробей: " << endl;
    fr1.printFract();
    cout << " * ";
    fr2.printFract();
    cout << " = ";
    fr3.multFrac(fr1.getNumer(), fr1.getDenom(), fr2.getNumer(), fr2.getDenom());
    fr3.printFract();
    cout << endl;

    cout << "Деление дробей: " << endl;
    fr1.printFract();
    cout << " : ";
    fr2.printFract();
    cout << " = ";
    fr3.divFrac(fr1.getNumer(), fr1.getDenom(), fr2.getNumer(), fr2.getDenom());
    fr3.printFract();
    cout << endl;
}
