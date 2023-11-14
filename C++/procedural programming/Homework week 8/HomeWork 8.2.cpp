#include <iostream>
using namespace std;

template <typename data>
void InitArr(data arr[], int size) {

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 500 + 1;
    }

}


template <typename data>
void InitArr(data arr[], int size, bool flag) { // переменная flag нужна, чтобы была перегрузка

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10 - 5;
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
int Max(data arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max<arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename data>
int Min(data arr[], int size) {
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

template <typename data>
void Sort(data arr[], int size) {
    int min, k;

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

template <typename data>
void InitNewArr(data arr[], int size, int a, int b) {

    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (b - a) + a;
    }

}

template <typename data>
int SummArr(data arr[], int size, int num) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < num)
            sum += arr[i];
    }
    return sum;
}

template <typename data>
int Max(data arr[], int size, int a, int b) {
    int max = arr[0];
    int k = 0;
    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    for (int i = a - 1; i <= b - 1; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            k = i;
        }
    }
    return k;
}

template <typename data>
int Min(data arr[], int size, int a, int b) {
    int min = arr[0];
    int k = 0;
    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    
    for (int i = a - 1; i <= b - 1; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            k = i;
        }
    }
    return k;
}




template<typename data>
int SumNegative(data arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

template<typename data>
long long Mult(data arr[], int size, int a, int b) {
    int mult = 1;
    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    for (int i = a; i <= b; i++)
    {
        mult *= arr[i];
    }
    return mult;
}

template<typename data>
long long MultEven(data arr[], int size) {
    int multEven = 1;
    
    for (int i = 0; i <size; i++)
    {
        if (i % 2 == 0)
        {
            multEven *= arr[i];
        }
    }
    return multEven;
}

template<typename data>
int SumNegPos(data arr[], int size) {
    int sum = 0;
    int a, b;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            a = i;
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            b = i;
            
        }
    }
    
    for (int i = a; i < b; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template <typename data>
int Max(data arr[], int size, bool flag) { //просто перегрузка
    int max = arr[0];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            k = i;
        }
    }
    return k;
}

template <typename data>
int Min(data arr[], int size, bool flag) { //просто перегрузка
    int min = arr[0];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            k = i;
        }
    }
    return k;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    /*
    const int size = 30;
    int arr[size];
    int min, max;
    cout << "Домашнее задание 8.1" << endl;
    InitArr(arr, size);
    ShowArr(arr, size);
    cout << endl;
    max = Max(arr, size);
    cout << endl;
    min = Min(arr, size);
    cout << endl;
    Sort(arr, size);
    ShowArr(arr, size);
    cout << endl;
    cout << endl;
    cout << "Максимальное значение в массиве: " << max << endl;
    cout << "Минимальное значение в массиве: " << min << endl;
    


    cout << "Домашнее задание 8.2" << endl;
    const int size = 30;
    int arr[size];
    int a, b, num, sum;
    cout << "Введите диапазон заполнения числами(от a до b): ";
    cin >> a >> b;
    cout << "Укажите значение: ";
    cin >> num;
    InitNewArr(arr, size, a, b);
    ShowArr(arr, size);
    cout << endl;
    sum = SummArr(arr, size, num);
    Sort(arr, size);
    cout << endl;
    ShowArr(arr, size);
    cout << endl;
    cout << "Сумма чисел меньших числа " << num << ": " << sum;

    

    cout << "Домашнее задание 8.3" << endl;
    const int size = 12;
    int arr[size];
    int a, b, mounthMin, mounthMax;
    cout << "Введите прибыль за 12 месяцев: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Прибыль за " << i + 1 << " месяц: ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Введите диапазон поиска(от a до b):";
    cin >> a >> b;
    mounthMax = Max(arr, size, a, b) + 1;
    mounthMin = Min(arr, size, a, b) + 1;
    cout << "Номер месяца с максимальной прибылью: " << mounthMax << endl;
    cout << "Прибыль составила: " << arr[mounthMax - 1] << endl;
    cout << "Номер месяца с минимальной прибылью: " << mounthMin << endl;
    cout << "Прибыль составила: " << arr[mounthMin - 1] << endl;

    */

    cout << "Домашнее задание 8.4" << endl;
    const int size = 10;
    int arr[size];
    int options, sumNeg, sumNP;
    long long multypl, multEv;
    InitArr(arr, size, true);
    ShowArr(arr, size);
    cout << endl << endl;
   
    cout << "\tМеню." << endl;
    cout << "1 - Сумма отрицательных элементов." << endl;
    cout << "2 - Произведение между min и max." << endl;
    cout << "3 - Произведение элементов с четными номерами." << endl;
    cout << "4 - Сумма между первым и последним отрицательным элементом." << endl;
    cout << "5 - выход." << endl;
    cout << "Выберите пункт в меню: " << endl;
    do
    {
        cin >> options;
        switch (options)
        {
        case 1:
            sumNeg = SumNegative(arr, size);
            cout << "Сумма отрицательных элементов: " << sumNeg << endl;
            break;
        case 2:
            multypl = Mult(arr, size, Min(arr, size, true), Max(arr, size, true));
            cout << "Произведение между min и max: " << multypl << endl;
            break;
        case 3:
            multEv = MultEven(arr, size);
            cout << "Произведение элементов с четными номерами: " << multEv << endl;
            break;
        case 4:
            sumNP = SumNegPos(arr, size);
            cout << "Сумма между первым и последним отрицательным элементом: " << sumNP << endl;
            break;
        case 5:
            options = 5;
            break;
        default:
            cout << "Ошибка! Такого пунтка в меню нет! Повторите ввод!" << endl;
            break;
        }
    } while (options != 5);
    Sort(arr, size); // для проверки
    ShowArr(arr, size);
}
