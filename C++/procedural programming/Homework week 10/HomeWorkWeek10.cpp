#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    /*
    cout << "Домашнее задание 10.1" << endl;
    const int rows = 10;
    const int col = 2;
    int mass[rows][col];
    int num;
    cout << "Введите число: ";
    cin >> num;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            
            
            if (i == 0 & j == 0)
            {
                mass[i][j] = num;
            }else
                mass[i][j] = 2 * mass[i][j - 1];
            
           
                
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
    
    */
    /*
    cout << "Домашнее задание 10.2" << endl;
    const int rows = 10;
    const int col = 2;
    int mass[rows][col];
    int num;
    cout << "Введите число: ";
    cin >> num;
   for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            
            
            if (i == 0 & j == 0)
            {
                mass[i][j] = num;
            }else
                mass[i][j] = mass[i][j - 1] + 1;
            
           
                
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << "Домашнее задание 10.3" << endl;
    const int rows = 5;
    const int col = 5;
    int arr[rows][col];
    int sdvig = 0;
    int choice;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10 + 1;
        }
    }
    cout << "Начальный массив: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Введите количество сдвигов: ";
    cin >> sdvig;
    cout << endl;
    do
    {
        cout << "Выберите пункт Меню: " << endl;
        cout << "1 - Сдвиг влево." << endl;
        cout << "2 - Сдвиг вправо." << endl;
        cout << "3 - Сдвиг вверх." << endl;
        cout << "4 - Сдвиг вниз." << endl;
        cout << "5 - Изменить количество сдвигов." << endl;
        cout << "6 - Напечатать массив в консоль." << endl;
        cout << "7 - Выход." << endl << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:

            for (int i = 0; i < rows; i++) //влево
            {
                for (int k = 0; k < sdvig; k++)
                {
                    int buffer = arr[i][0];

                    for (int j = 0; j < col; j++)
                    {
                        arr[i][j] = arr[i][j + 1];
                    }

                    arr[i][col - 1] = buffer;
                }
            }


            break;
        case 2: 

        for (int i = 0; i < rows; i++) //вправо
        {
            for (int k = 0; k < sdvig; k++)
            {
                int buffer = arr[i][col - 1];

                for (int j = col - 1; j > 0; j--)
                {
                    arr[i][j] = arr[i][j - 1];
                }

                arr[i][0] = buffer;
            }
        }

            break;
        case 3:
            for (int k = 0; k < sdvig; k++) //вверх
            {
                for (int i = 0; i < rows - 1; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        int buffer = arr[i + 1][j];
                        arr[i + 1][j] = arr[i][j];
                        arr[i][j] = buffer;
                    }
                }
            }
            break;
        case 4:
            for (int k = 0; k < sdvig; k++) //вниз
            {
                for (int i = rows - 1; i > 0; i--)
                {
                    for (int j = 0; j < col; j++)
                    {
                        int buffer = arr[i - 1][j];
                        arr[i - 1][j] = arr[i][j];
                        arr[i][j] = buffer;
                    }
                }
            }
            break;
        case 5:
            cout << "Введите количество сдвигов: ";
            cin >> sdvig;
            cout << endl;
            break;
        case 6:

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;

            break;

        case 7:
            cout << "Пока!" << endl;
            break;

        default:cout << "Ошибка! Повторите ввод!" << endl;
            break;
        }
    } while (choice != 7);
    
    
    
   

   

   



}
