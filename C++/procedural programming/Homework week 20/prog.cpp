#include <iostream>
#include <Windows.h>
#define INTEGER
#include "function.h"

using namespace std;
#ifdef  INTEGER
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int key;
    const int size = 10;
    int arrInt[size];
    cout << "Инициализация массива: " << endl;
    Init(arrInt, size);
    cout << "Вывод массива: " << endl;
    Print(arrInt, size);
    cout << "Минимальный элемент массива: " << SearchMin(arrInt, size) << endl;
    cout << "Максимальный элемент массива: " << SearchMax(arrInt, size) << endl;
    cout << "Сортировка массива: " << endl;
    cout << "Вывод массива: " << endl;
    Print(arrInt, size);
    cout << "Вывод отсортированного массива: " << endl;
    Sort(arrInt, size);
    Print(arrInt, size);
    cout << "Изменение элемента:" << endl;
    Change(arrInt, size);
    cout << "Вывод массива: " << endl;
    Print(arrInt, size);

 
}
#endif //  INTEGER
#ifdef FLOAT
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int key;
    const int size = 10;
    float arrFloat[size];
    cout << "Инициализация массива: " << endl;
    Init(arrFloat, size);
    cout << "Вывод массива: " << endl;
    Print(arrFloat, size);
    cout << "Минимальный элемент массива: " << SearchMin(arrFloat, size) << endl;
    cout << "Максимальный элемент массива: " << SearchMax(arrFloat, size) << endl;
    cout << "Сортировка массива: " << endl;
    cout << "Вывод массива: " << endl;
    Print(arrFloat, size);
    cout << "Вывод отсортированного массива: " << endl;
    Sort(arrFloat, size);
    Print(arrFloat, size);
    cout << "Изменение элемента:" << endl;
    Change(arrFloat, size);
    cout << "Вывод массива: " << endl;
    Print(arrFloat, size);

}

#endif

#ifdef CHAR
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int key;
    const int size = 10;
    char* arrChar = new char [size]{'\0'};
    cout << "Инициализация массива: " << endl;
    Init(arrChar, size);
    cout << "Вывод массива: " << endl;
    Print(arrChar);
    cout << "Минимальный элемент массива: " << SearchMin(arrChar, size) << endl;
    cout << "Максимальный элемент массива: " << SearchMax(arrChar, size) << endl;
    cout << "Сортировка массива: " << endl;
    cout << "Вывод массива: " << endl;
    Print(arrChar);
    cout << "Вывод отсортированного массива: " << endl;
    Sort(arrChar, size);
    Print(arrChar);
    cout << "Изменение элемента:" << endl;
    Change(arrChar);
    cout << "Вывод массива: " << endl;
    Print(arrChar);
  
}
#endif

