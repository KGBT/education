#include <iostream>
#define tab "\t"

using namespace std;


bool VisYear(int year) {

    bool flag = false;

    if (year % 4 == 0 && year % 100 != 0)
    {
        flag = true;
    }
    else if (year % 400 == 0)
    {
        flag = true;
    }
    return flag;
}

int Days(int day1, int mounth1, int year1, int day2, int mounth2, int year2) {

    int y1, y2, m1, m2;
    int days1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // високосный год
   
    if (VisYear(year1))
    {
        y1 = 366;
        m1 = days2[mounth1 - 1];
    }
    else
    {
        y1 = 365;
        m1 = days1[mounth1 - 1];
    }

    if (VisYear(year2))
    {
        y2 = 366;
        m2 = days2[mounth2 - 1];
    }
    else
    {
        y2 = 365;
        m2 = days1[mounth2 - 1];
    }
    int razn = (year1 * y1 + m1 * mounth1 + day1) - (year2 * y2 + m2 * mounth2 + day2);
    return abs(razn);
}

template <typename data>
void InitArr(data arr[], int size) {

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 40 + 1;
    }
}

template <typename data>
void InitArr(int size, data arr[]) {

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 40 - 20;
    }
}

template <typename data>
void ShowArr(data arr[], int size) {

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

template <typename data>
double SredneeArf(data arr[], int size) {

    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += (double)arr[i] / size;
    }
    return sum;
}

template <typename data>
void Podshet(data arr[], int size) {

    int poz = 0, neg = 0, zero = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            poz++;
        }
        if (arr[i] < 0)
        {
            neg++;
        }
        else if (arr[i] == 0)
            zero++;
    }
    cout << "Количество положительных элементов в массиве: " << poz << endl;
    cout << "Количество отрицательных элементов в массиве: " << neg << endl;
    cout << "Количество нулевых элементов в массиве: " << zero << endl;
}

template <typename data>
void Sort(data arr[], int size) { //Для проверки
    int k;
    data min;
    for (int i = 0; i < size; i++)
    {
        min = arr[i];
        k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                k = j;
            }
        }
        if (k!=i)
        {
            arr[k] = arr[i];
            arr[i] = min;
        }
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    /*
    cout << "Домашнее задание 12.1" << endl;
    int day1, mounth1, year1, day2, mounth2, year2;
    cout << "Введите первую дату в формате dd mm yyyy: ";
    cin >> day1 >> mounth1 >> year1;

    cout << "Введите вторую дату в формате dd mm yyyy: ";
    cin >> day2 >> mounth2 >> year2;

    cout << "Разность в днях составляет: " << Days(day1, mounth1, year1, day2, mounth2, year2) << endl;
    */

    cout << "Домашнее задание 12.2" << endl;
    const int size = 20;
    int arr[size];
    InitArr(arr, size);
    ShowArr(arr, size);
    cout << endl;
    cout << "Среднее арифметическое массива равно: " << SredneeArf(arr, size) << endl;
    

        /*
    cout << "Домашнее задание 12.3" << endl;
    const int size = 20;
    int arr[size];
    InitArr(size, arr); // перегруженная инициализация
    ShowArr(arr, size);
    cout << endl;
    Podshet(arr, size);
    cout << endl;
    Sort(arr, size);
    ShowArr(arr, size);
    */
}

