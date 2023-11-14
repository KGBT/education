#include <iostream>
using namespace std;

int main()
{   
    int choice; // Выбор фигуры
    cout << "Home Task 7.1" << endl;
    cout << "\t Figuri:" << endl;
    cout << "\t1 - a" << "\t6 - e" << endl;
    cout << "\t2 - b" << "\t7 - j" << endl;
    cout << "\t3 - v" << "\t8 - z" << endl;
    cout << "\t4 - g" << "\t9 - i" << endl;
    cout << "\t5 - d" << "\t10 - k" << endl;
    cout << "Viberite variant figuri: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        for (int i = 0; i < 10; i++) // Фигуры по картинке по порядку
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {
                
                if (i < j)
                {
                    cout << "*";
                }
                else
                    cout << " ";
                
            }
            cout << endl;
        }
        break;
    case 2:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if (i > j)
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 3:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if (i < j && i+j < 10)
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 4:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if (i >= j && i + j >= 10)
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 5:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if ((i >= j && i + j >= 10) || (i < j && i + j < 10))
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 6:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if ((i > j && i+j < 10) || (i <= j && i + j >= 10))
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 7:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if ((i > j && i + j < 10))
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 8:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if ((i <= j && i + j >= 10))
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 9:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if (i + j < 10)
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    case 10:
        for (int i = 0; i < 10; i++)
        {
            cout << "\t";
            for (int j = 0; j < 10; j++)
            {

                if (i + j >= 10)
                {
                    cout << "*";
                }
                else
                    cout << " ";

            }
            cout << endl;
        }
        break;
    default:
        cout << "Error! Takoi figuri net!";
        break;
    }

}

