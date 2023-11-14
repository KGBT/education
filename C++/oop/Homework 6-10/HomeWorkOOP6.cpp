#include <iostream>
#include <Windows.h>
using namespace std;

class Fraction
{
public:
    
    
    Fraction(int numer, int denom) : numerator{ numer }, denominator{ denom } {}
    Fraction() : Fraction(1, 1) {}
    Fraction(int numerator) : Fraction(numerator, 1) {}
    Fraction(const Fraction& fr) : numerator{ fr.numerator }, denominator{ fr.denominator } {}
    void setNumer(int numer);
    void setDenom(int denom);

    int getNumer();
    int getDenom();

    void sumFrac(int numer1, int denom1, int numer2, int denom2);
    void diffFrac(int numer1, int denom1, int numer2, int denom2);
    void multFrac(int numer1, int denom1, int numer2, int denom2);
    void divFrac(int numer1, int denom1, int numer2, int denom2);
    void printFract();

    Fraction operator+ (const Fraction& fr) {
        if (this->denominator == fr.denominator)
        {
            return Fraction(this->numerator + fr.numerator, this->denominator);
        }
       
        return Fraction(this->numerator * fr.denominator + fr.numerator * this->denominator, this->denominator * fr.denominator);
    }
    Fraction operator- (const Fraction& fr) {
        if (this->denominator == fr.denominator)
        {
            return Fraction(this->numerator - fr.numerator, this->denominator);
        }

        return Fraction((this->numerator * fr.denominator) - (fr.numerator * this->denominator), this->denominator * fr.denominator);
    
    }
    Fraction operator* (const Fraction& fr) {
        
        return Fraction(this->numerator * fr.numerator, this->denominator * fr.denominator);
    }
    Fraction operator/ (const Fraction& fr) {

        return Fraction(this->numerator * fr.denominator, fr.numerator * this->denominator);
    }
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
void Fraction::setNumer(int numer) {
    numerator = numer;
}
void Fraction::setDenom(int denom) {

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

void Fraction::sumFrac(int numer1, int denom1, int numer2, int denom2) {

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

class ComplexNumber
{
public:
    ComplexNumber(float, float);
    ComplexNumber() : ComplexNumber(0, 0) {}
    ComplexNumber(float Re) : ComplexNumber(Re, 0) {}

    void OutputNumber() {

        if (Im == 0)
        {
            cout << Re;
        }
        else if (Re == 0)
            cout << Im << "i";
        else
            cout << Re << "+" << Im << "i";

    }
    float getRe() {
        return Re;
    }
    float getIm() {
        return Im;
    }

    ComplexNumber& setRe(float Re) {
        this->Re = Re;
        return *this;
    }
    ComplexNumber& setIm(float Im) {
        this->Im = Im;
        return *this;
    }

    ComplexNumber operator+ (const ComplexNumber& cn) {
        return ComplexNumber(this->Re + cn.Re, this->Im + cn.Im);
    }
    ComplexNumber operator-(const ComplexNumber& cn) {
        return ComplexNumber(this->Re - cn.Re, this->Im - cn.Im);
    }
    ComplexNumber operator* (const ComplexNumber& cn) {
        return ComplexNumber(this->Re * cn.Re - this->Im * cn.Im, this->Re * cn.Im + cn.Re * this->Im);
    }
    ComplexNumber operator/(const ComplexNumber& cn) {
        float Re1 = (this->Re * cn.Re + this->Im * cn.Im) / (cn.Re * cn.Re + cn.Im * cn.Im);
        float Im1 = (cn.Re * this->Im - this->Re * cn.Im) / (cn.Re * cn.Re + cn.Im * cn.Im);
        return ComplexNumber(Re1, Im1);
    }
private:
    float Re;
    float Im;
};

ComplexNumber::ComplexNumber(float Re, float Im) : Re{ Re }, Im{ Im } {}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fraction fr1;
    fr1.setNumer(1);
    fr1.setDenom(2);

    Fraction fr2;
    fr2.setNumer(1);
    fr2.setDenom(3);

    Fraction fr3;
    cout << "Домашнее задание ООП_6.1" << endl;
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

    Fraction fr4;
    cout << "Сложение дробей: " << endl;
    fr1.printFract();
    cout << " + ";
    fr2.printFract();
    fr4 = fr1 + fr2;
    cout << " = ";
    fr4.printFract();
    cout << endl;

    cout << "Вычитание дробей: " << endl;
    fr1.printFract();
    cout << " - ";
    fr2.printFract();
    cout << " = ";
    fr4 = fr1 - fr2;
    fr4.printFract();
    cout << endl;

    cout << "Умножение дробей: " << endl;
    fr1.printFract();
    cout << " * ";
    fr2.printFract();
    cout << " = ";
    fr4 = fr1 * fr2;
    fr4.printFract();
    cout << endl;

    cout << "Деление дробей: " << endl;
    fr1.printFract();
    cout << " : ";
    fr2.printFract();
    cout << " = ";
    fr4 = fr1 / fr2;
    fr4.printFract();
    cout << endl;
    cout << endl;
    cout << "Домашнее задание ООП_6.2" << endl;
    ComplexNumber num1(-2,1);
    ComplexNumber num2;
    ComplexNumber num3;
    num2.setRe(1).setIm(-1);

    cout << "Сложение комплексных чисел: " << endl;
    num1.OutputNumber();
    cout << " + ";
    num2.OutputNumber();
    num3 = num1 + num2;
    cout << " = ";
    num3.OutputNumber();
    cout << endl;

    cout << "Вычитание комплексных чисел: " << endl;
    num1.OutputNumber();
    cout << " - ";
    num2.OutputNumber();
    num3 = num1 - num2;
    cout << " = ";
    num3.OutputNumber();
    cout << endl;

    cout << "Умножение комплексных чисел: " << endl;
    num1.OutputNumber();
    cout << " * ";
    num2.OutputNumber();
    num3 = num1 * num2;
    cout << " = ";
    num3.OutputNumber();
    cout << endl;

    cout << "Деление комплексных чисел: " << endl;
    num1.OutputNumber();
    cout << " / ";
    num2.OutputNumber();
    num3 = num1 / num2;
    cout << " = ";
    num3.OutputNumber();
    cout << endl;

}
