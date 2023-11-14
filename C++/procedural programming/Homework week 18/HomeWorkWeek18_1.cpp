#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
void CreateArr(int**& arr, int rows, int col) {
    arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        *(arr + i) = new int[col];
    }
}
void InitArr(int** arr, int rows, int col) {
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 20 - 10;
            //arr[i][j] = - i - j; //для проверки отрицательных элементов
        }
    }

}
void PrintArr(int** arr, int rows, int col) {

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void SortArr(int** arr, int rows, int col) {
    
   
    int buff;
    for (int i = 0; i < rows; i++)
    {
        int left = 0, right = col - 1;
        while (left <= right)
        {
            for (int j = right; j > left; --j)
            {
                if (arr[i][j-1] > arr[i][j])
                {
                    buff = arr[i][j];
                    arr[i][j] = arr[i][j - 1];
                    arr[i][j - 1] = buff;
                }
                
            }
            left++;
            for (int j = left; j < right; ++j)
            {
                if (arr[i][j] > arr[i][j+1])
                {
                    buff = arr[i][j];
                    arr[i][j] = arr[i][j + 1];
                    arr[i][j + 1] = buff;
                }

            }
            right--;
        }
    }

}
int BiSearch(int key, int** arr, int rows, int col) {
    int result = 0;
    for (int i = 0; i < rows; i++)
    {
        int left = 0, rigth = col-1;
        
        while (true)
        {
            int avg = (left + rigth) / 2;

            if (key == arr[i][avg])
            {
                result = arr[i][avg];
                break;
            }
            else if (left > rigth) {
                break;
            }
            else
            {
                if (key > arr[i][avg])
                {
                    left = avg + 1;
                }
                else
                {
                    rigth = avg - 1;
                }
            }
                                    
        }
    }
    return result;
}
int* CommonValues(int** A, int rowsA, int colA, int** B, int rowsB, int colB, int** C, int rowsC, int colC, int &count) {
    int k = 1, kbuff = 0;
    count = 0;
    int* arr = new int[1]{0};
    int* buffer;
    bool flag = false;
    
    int resultSearch;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
           resultSearch = BiSearch(A[i][j], B, rowsB, colB);

           if (resultSearch)
           {
               resultSearch = BiSearch(A[i][j], C, rowsC, colC);

               if (resultSearch)
               {
                   
                   buffer = new int[kbuff];
                   for (int i = 0; i < kbuff; i++)
                   {
                       *(buffer + i) = *(arr + i);
                   }
                   if (*(arr+0) == 0)
                   {
                       *(arr+0) = resultSearch;
                       kbuff++;
                       delete[] buffer;
                   }
                   else
                   {
                       delete[] arr;
                       arr = new int[++k];
                       for (int i = 0; i < kbuff; i++)
                       {
                           *(arr + i) = *(buffer + i);
                       }
                       *(arr + k - 1) = resultSearch;
                       kbuff++;
                       delete[] buffer;
                   }
                   
               }
              
           }


        }
        
    }
    count = k;
    return arr;
}
int* CommonValues(int** A, int rowsA, int colA, int** C, int rowsC, int colC, int& count) {
    int k = 1, kbuff = 0;
    count = 0;
    int* arr = new int[1] {0};
    int* buffer;
    bool flag = false;

    int resultSearch;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            resultSearch = BiSearch(A[i][j], C, rowsC, colC);

            if (resultSearch)
            {

                buffer = new int[kbuff];
                for (int i = 0; i < kbuff; i++)
                {
                    *(buffer + i) = *(arr + i);
                }
                if (*(arr + 0) == 0)
                {
                    *(arr + 0) = resultSearch;
                    kbuff++;
                    delete[] buffer;
                }
                else
                {
                    delete[] arr;
                    arr = new int[++k];
                    for (int i = 0; i < kbuff; i++)
                    {
                        *(arr + i) = *(buffer + i);
                    }
                    *(arr + k - 1) = resultSearch;
                    kbuff++;
                    delete[] buffer;
                }

            }

            
               

            


        }

    }
    count = k;
    return arr;
}

int BiSearchUniq(int key, int** arr, int rows, int col) {
    int result = key;
    for (int i = 0; i < rows; i++)
    {
        int left = 0, rigth = col - 1;

        while (true)
        {
            int avg = (left + rigth) / 2;

            if (key == arr[i][avg])
            {
                result = 0;
                break;
            }
            else if (left > rigth) {
                break;
            }
            else
            {
                if (key > arr[i][avg])
                {
                    left = avg + 1;
                }
                else
                {
                    rigth = avg - 1;
                }
            }

        }
    }
    return result;
}
int* CommonValuesUniq(int** A, int rowsA, int colA, int** B, int rowsB, int colB, int** C, int rowsC, int colC, int& count) {
    int k = 1, kbuff = 0;
    count = 0;
    int* arr = new int[1] {0};
    int* buffer;
    bool flag = false;

    int resultSearch;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            resultSearch = BiSearchUniq(A[i][j], B, rowsB, colB);

            if (resultSearch)
            {
                resultSearch = BiSearchUniq(A[i][j], C, rowsC, colC);

                if (resultSearch)
                {

                    buffer = new int[kbuff];
                    for (int i = 0; i < kbuff; i++)
                    {
                        *(buffer + i) = *(arr + i);
                    }
                    if (*(arr + 0) == 0)
                    {
                        *(arr + 0) = resultSearch;
                        kbuff++;
                        delete[] buffer;
                    }
                    else
                    {
                        delete[] arr;
                        arr = new int[++k];
                        for (int i = 0; i < kbuff; i++)
                        {
                            *(arr + i) = *(buffer + i);
                        }
                        *(arr + k - 1) = resultSearch;
                        kbuff++;
                        delete[] buffer;
                    }

                }

            }


        }

    }
    count = k;
    return arr;
}

int* MinusCommonValues(int** A, int rowsA, int colA, int** B, int rowsB, int colB, int** C, int rowsC, int colC, int& count) {
    int k = 1, kbuff = 0;
    count = 0;
    int* arr = new int[1] {0};
    int* buffer;
    bool flag = false;

    int resultSearch;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            resultSearch = BiSearch(A[i][j], B, rowsB, colB);

            if (resultSearch)
            {
                resultSearch = BiSearch(A[i][j], C, rowsC, colC);



                if (resultSearch && resultSearch < 0)
                {
                    flag = false;
                    for (int i = 0; i < k; i++)
                    {
                        if (resultSearch == arr[i])
                        {
                            flag = true;
                        }
                                                                      
                    }
                    if (!flag)
                    {
                        buffer = new int[kbuff];
                        for (int i = 0; i < kbuff; i++)
                        {
                            *(buffer + i) = *(arr + i);
                        }
                        if (*(arr + 0) == 0)
                        {
                            *(arr + 0) = resultSearch;
                            kbuff++;
                            delete[] buffer;
                        }
                        else
                        {
                            delete[] arr;
                            arr = new int[++k];
                            for (int i = 0; i < kbuff; i++)
                            {
                                *(arr + i) = *(buffer + i);
                            }
                            *(arr + k - 1) = resultSearch;
                            kbuff++;
                            delete[] buffer;
                        }
                    }
                
                    

                }

            }


        }

    }
    count = k;
    return arr;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    /*
    std::cout << "Домашнее задание 18.1\n";
    char** st = new char* [5];
    for (int i = 0; i < 5; i++)
    {
        st[i] = new char[20];
    }
    cout << "Введите 5 фамилий студентов: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> *(st+i);
        
    }
    cout << endl;
    char* min = new char[20] {};
    int k;
    for (int i = 0; i < 5; ++i)
    {
        
        k = i;
        strcpy_s(min, 20, *(st + i));
        for (int j = i+1; j < 5; j++)
        {
            if (*min > **(st+j))
            {
                strcpy_s(min, 20,*(st+j));
                k = j;
            }
        }
        if (k!=i)
        {
            
            strcpy_s(*(st+k), 20, *(st + i));
            strcpy_s(*(st + i), 20, min);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *(st+i) << endl;
    }
    */
    std::cout << "Домашнее задание 18.2\n";
    int rowsA, rowsB, rowsC, colA, colB, colC, sizeNewArr = 0;
    int** A, ** B, ** C;
    cout << "Введите количество строк и столбцов для массива А: ";
    cin >> rowsA >> colA;
    CreateArr(A,rowsA,colA);
    InitArr(A, rowsA, colA);
    PrintArr(A, rowsA, colA);
    cout << endl << "Отсортированный массив:" << endl;
    SortArr(A, rowsA, colA);
    PrintArr(A, rowsA, colA);
    cout << "Введите количество строк и столбцов для массива B: ";
    cin >> rowsB >> colB;
    CreateArr(B, rowsB, colB);
    InitArr(B, rowsB, colB);
    PrintArr(B, rowsB, colB);
    cout << endl << "Отсортированный массив:" << endl;
    SortArr(B, rowsB, colB);
    PrintArr(B, rowsB, colB);
    cout << "Введите количество строк и столбцов для массива C: ";
    cin >> rowsC >> colC;
    CreateArr(C, rowsC, colC);
    InitArr(C, rowsC, colC);
    PrintArr(C, rowsC, colC);
    cout << endl << "Отсортированный массив:" << endl;
    SortArr(C, rowsC, colC);
    PrintArr(C, rowsC, colC);
    /*
    int* res;
    res = CommonValues(A, rowsA, colA, B, rowsB, colB, C, rowsC, colC,sizeNewArr);
    cout << "Новый массив, состоящий из элементов А, В, С: " << endl;
    for (int i = 0; i < sizeNewArr; i++)
    {
        cout << res[i] << " ";
    }
    */
    /*
    int* res2;
    int sizeNewArr2 = 0;
    res2 = CommonValuesUniq(A, rowsA, colA, B, rowsB, colB, C, rowsC, colC, sizeNewArr2);
    cout << "Новый массив уникальных элементов: " << endl;
    for (int i = 0; i < sizeNewArr2; i++)
    {
        cout << res2[i] << " ";
    }
    */
    /*
    int* res3;
    int sizeNewArr3 = 0;
    res3 = CommonValues(A, rowsA, colA, C, rowsC, colC, sizeNewArr3);
    cout << "Новый массив, состоящий из элементов А и С: " << endl;
    for (int i = 0; i < sizeNewArr3; i++)
    {
        cout << res3[i] << " ";
    }
    */
   
    //для проверки отрицательных элементов перейдите в InitArr(int** arr, int rows, int col) и измените код(обозначено комментарием)
    int* res4;
    int sizeNewArr4 = 0;
    res4 = MinusCommonValues(A, rowsA, colA, B, rowsB, colB, C, rowsC, colC, sizeNewArr4);
    cout << "Новый массив, состоящий из отрицательных элементов А, B, С: " << endl;
    for (int i = 0; i < sizeNewArr4; i++)
    {
        cout << res4[i] << " ";
    }
 
}
