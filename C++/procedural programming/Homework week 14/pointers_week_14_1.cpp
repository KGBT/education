#include <iostream>
#include <time.h>
using namespace std;


template<typename data>
void InitArray(data* arr, int size) {

    for (int i = 0; i < size; i++)
    {
        *arr++ = rand() % 10 + 1;
    }
}

template <typename data>
void ShowArray(data* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << *arr++ << " ";
    }
    cout << endl;
}


int Counter(int* arr1, int* arr2, int size1, int size2) { 
      
    int k = 0;
    bool flag;

    for (int i = 0; i < size1; i++)
    {
        flag = true;

        for (int j = 0; j < size2; j++) // Считаем количество совпадений массива А с массивом В
        {
            if (*(arr1+i) == *(arr2+j))
            {
                flag = false;
                break;
            }    
               
        }

        if (flag)
        {
            for (int k = i + 1; k < size1; k++) //Считаем количество совпадений внутри массива А
            {
                if ((*(arr1 + i) == *(arr1 + k)))
                {
                    flag = false;
                    break;
                }
            }
        }
        

        if (flag)
        {
            k++;
        }
        
    }
    return k;
}


void NewArray(int* arr1, int* arr2, int* arr3,int size1, int size2) { // создаем новый массив
          
    bool flag;

    for (int i = 0; i < size1; i++)
    {
        flag = true;

        for (int j = 0; j < size2; j++) // Считаем количество совпадений массива А с массивом В
        {
            if (*(arr1 + i) == *(arr2 + j))
            {
                flag = false;
                break;
            }

        }

        if (flag)
        {
            for (int k = i + 1; k < size1; k++) //Считаем количество совпадений внутри массива А
            {
                if ((*(arr1 + i) == *(arr1 + k)))
                {
                    flag = false;
                    break;
                }
            }
        }


        if (flag)
        {
            *arr3++ = *(arr1+i);
        }

    }
    
}




void NewArray2(int* arr1, int* arr2, int* arr3, int size1, int size2) { // создаем новый массив

    bool flag;

    for (int i = 0; i < size1; i++)
    {
        flag = true;

        for (int j = 0; j < size2; j++) // Считаем количество совпадений массива А с массивом В
        {
            if (*(arr1 + i) == *(arr2 + j))
            {
                flag = false;
                break;
            }

        }

        if (flag)
        {
            for (int k = i + 1; k < size1; k++) //Считаем количество совпадений внутри массива А
            {
                if ((*(arr1 + i) == *(arr1 + k)))
                {
                    flag = false;
                    break;
                }
            }
        }


        if (flag)
        {
            *arr3++ = *(arr1 + i);
        }

    }



    for (int i = 0; i < size2; i++)
    {
        flag = true;

        for (int j = 0; j < size1; j++) // Считаем количество совпадений массива А с массивом В
        {
            if (*(arr2 + i) == *(arr1 + j))
            {
                flag = false;
                break;
            }

        }

        if (flag)
        {
            for (int k = i + 1; k < size2; k++) //Считаем количество совпадений внутри массива А
            {
                if ((*(arr2 + i) == *(arr2 + k)))
                {
                    flag = false;
                    break;
                }
            }
        }


        if (flag)
        {
            *arr3++ = *(arr2 + i);
        }

    }


}



int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    /*
    cout << "Домашнее задание 14.1" << endl;
    int M, N;
    int k = 0;
    cout << "Введите размер массива А: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;
    int* A = new int[M];
    int* B = new int[N];
    cout << "Массив A: " << endl;
    InitArray(A, M);
    ShowArray(A, M);
    cout << "Массив B: " << endl;
    InitArray(B, N);
    ShowArray(B, N);
    
    k = Counter(A,B,M,N);
   
    cout << "Счетчик: " << k << endl;

    cout << "Новый массив: " << endl;
    int* arr = new int[k];
    NewArray(A,B,arr,M,N);
    ShowArray(arr, k);
    delete[] A;
    delete[] B;
    delete[] arr;
    */
    cout << "Домашнее задание 14.2" << endl;
    int M, N;
    int k = 0;
    cout << "Введите размер массива А: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;
    int* A = new int[M];
    int* B = new int[N];
    cout << "Массив A: " << endl;
    InitArray(A, M);
    ShowArray(A, M);
    cout << "Массив B: " << endl;
    InitArray(B, N);
    ShowArray(B, N);

    k = Counter(A, B, M, N) + Counter(B,A,N,M);

    cout << "Счетчик: " << k << endl;

    cout << "Новый массив: " << endl;
    int* arr = new int[k];
    NewArray2(A, B, arr, M, N);
    ShowArray(arr, k);
    delete[] A;
    delete[] B;
    delete[] arr;
}
