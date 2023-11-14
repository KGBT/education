#include <iostream>
#include <time.h>
using namespace std;
template<typename type>
type Max(type* arr, const int count) {
    type max = *arr;
    for (size_t i = 0; i < count; i++)
    {
        if (max < *(arr+i))
        {
            max = *(arr + i);
        }
    }
    return max;
}
template<typename type>
type Min(type* arr, const int count) {
    type min = *arr;
    for (size_t i = 0; i < count; i++)
    {
        if (min > *(arr + i))
        {
            min = *(arr + i);
        }
    }
    return min;
}
template<typename type>
void QuickSort(type* arr, const int count) {
    int i = 0, j = count - 1;
    type center = arr[count / 2];
    type temp;
    do
    {
        while (arr[i] < center) i++;
        while (arr[j] > center) j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        
    } while (i<=j);

    if (j > 0) QuickSort(arr, j + 1);
    if (count > i) QuickSort(arr + i, count - i);
}
template<typename type, typename t>
int BinarySearch(type* arr, const int count, t key) {
    
    int left = 0, right = count;
    int center = (left + right) / 2;

    do
    {
        
        if (key == *(arr+center))
        {
            return center;
        }
        if (key < *(arr + center))
        {
            right = center - 1;
            
        }
        if (key > *(arr + center))
        {
            left = center + 1;
            
        }
        center = (left + right) / 2;
    } while (left<=right);
    return -1;
}
template<typename type, typename t>

void Replace(type* arr, const int count, t number, int el) {
    
    if (el-1 < 0 || el-1 > count)
    {
        cout << "Невозможно заменить элемент по " << el-1 << " индексу." << endl;
        return;
    }
    cout << "Элемент " << *(arr + el - 1) << " заменен на " << number << "." << endl;
    *(arr + el-1) = number;
   
}
int main()
{
    setlocale(LC_ALL, "");
    srand(time(nullptr));
    std::cout << "Домашнее задание ООП11.\n";
    const int size = 10;
    /**/
    int* arr1 = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        *(arr1 + i) = rand() % 20 + 1;
    }

    cout << "Массив int: " << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr1 + i) << " ";
    }
    cout << endl;

    cout << "Отсортированный массив int: " << endl;
    QuickSort(arr1, size);
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr1 + i) << " ";
    }
    cout << endl;

    cout << "Максимальный элемент в массиве int: " << Max(arr1, size) << endl;
    cout << "Минимальный элемент в массиве int: " << Min(arr1, size) << endl;
    int el = BinarySearch(arr1, size, 3);
    cout << "Двоичный поиск " << 3 << " в массиве int: ";
    if (el != -1)
    {
        cout << el << " - индекс." << endl;
    }
    else
    {
        cout << "элемент не найден." << endl;
    }

    cout << "Замена элемента 66 под номером 1." << endl;
    Replace(arr1, size, 66, 1);

    cout << "Массив int: " << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr1 + i) << " ";
    }
    cout << endl << endl << endl;





    float* arr2 = new float[size];
    for (size_t i = 0; i < size; i++)
    {
        *(arr2 + i) = (float)(rand() % 60 + 1) / 3;
    }

    cout << "Массив float: " << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr2 + i) << " ";
    }
    cout << endl;

    cout << "Отсортированный массив float: " << endl;
    QuickSort(arr2, size);
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr2 + i) << " ";
    }
    cout << endl;

    cout << "Максимальный элемент в массиве float: " << Max(arr2, size) << endl;
    cout << "Минимальный элемент в массиве float: " << Min(arr2, size) << endl;
    el = BinarySearch(arr2, size, 3);
    cout << "Двоичный поиск " << 3 << " в массиве float: ";
    if (el != -1)
    {
        cout << el << " - индекс." << endl;
    }
    else
    {
        cout << "элемент не найден." << endl;
    }

    cout << "Замена элемента 66 под номером 1." << endl;
    Replace(arr2, size, 66, 1);

    cout << "Массив float: " << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr2 + i) << " ";
    }
    cout << endl;
}