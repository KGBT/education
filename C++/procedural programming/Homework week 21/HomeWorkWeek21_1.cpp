#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    /*
    std::cout << "Домашнее задание 21.1" << endl;
    char path1[50] = "C:\\1\\file4.txt"; //для проверки вставляйте файлы file1, file2...
    char path2[50] = "C:\\1\\file2.txt"; //для проверки вставляйте файлы file1, file2...
    FILE* file1, *file2;
    fopen_s(&file1, path1, "r");
    fopen_s(&file2, path2, "r");
    if (file1 == NULL || file2 == NULL)
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт." << endl;
        char str1[100], str2[100];
        while (!feof(file1))
        {
            fgets(str1, sizeof(str1), file1);
            fgets(str2, sizeof(str2), file2);
            if (feof(file2))
            {
                break;
            }
            if (strcmp(str1, str2) != 0)
            {
                cout << "Несовпадающие строки: " << endl;
                cout << "Строка из первого файла: " << str1 << strlen(str1) << endl;
                cout << "Строка из второго файла: " << str2 << strlen(str2) << endl;
            }
            
        }
        if (!feof(file1))
        {
            cout  << endl << "Несовпадающие строки из первого файла: " << endl;
            while (!feof(file1))
            {
                fgets(str1, sizeof(str1), file1);
                cout << str1;
            }
        }
        if (!feof(file2))
        {
            cout << endl << "Несовпадающие строки из второго файла: " << endl;
            while (!feof(file2))
            {
                fgets(str2, sizeof(str2), file2);
                cout << str2;
            }
        }

         if (fclose(file1) == EOF)
    {
        cout << endl << "Ошибка закрытия файла." << endl;
    }
    else
    {
        cout << endl << "Файл закрыт." << endl;
    }

    if (fclose(file2) == EOF)
    {
        cout << endl << "Ошибка закрытия файла." << endl;
    }
    else
    {
        cout << endl << "Файл закрыт." << endl;
    }
        
    }

   
    */
    /*
    std::cout << "Домашнее задание 21.2" << endl;
    char path[50] = "C:\\1\\1\\file.txt";
    FILE* file;
    fopen_s(&file, path, "r");
    int buf;
    char s;
    int sym = 0; //символы
    int str = 1; //строки
    int vowels = 0; //гласные
    int consonants = 0; //согласные
    int digit = 0; //цифра
    int vow[12] = { 65, 69, 73, 79, 85, 89, 97, 101, 105, 111, 117, 121 };
    if (file == NULL)
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл открыт." << endl;
        while (!feof(file))
        {
           buf = fgetc(file);
           s = (char)buf;
           sym++;
           if (buf == '\n')
           {
               str++;
           }
           for (int i = 0; i < 12; i++)
           {
               if (buf == vow[i])
               {
                   vowels++;
                   break;
               }
           }
           
           if ((buf >=66 && buf <=68) || (buf >= 70 && buf <= 72) || (buf >= 74 && buf <= 78) || (buf >= 80 && buf <= 84) || (buf >= 86 && buf <= 88) || buf == 90)
           {
               consonants++;
           }

           if ((buf >= 98 && buf <= 100) || (buf >= 102 && buf <= 104) || (buf >= 106 && buf <= 110) || (buf >= 112 && buf <= 116) || (buf >= 118 && buf <= 120) || buf == 122)
           {
               consonants++;
           }

           if (buf >= 48 && buf <= 57)
           {
               digit++;
           }
        }
        str++;
        cout << "Количество символов: " << sym << endl;
        cout << "Количество строк: " << str << endl;
        cout << "Количество гласных букв: " << vowels << endl;
        cout << "Количество согласных букв: " << consonants << endl;
        cout << "Количество цифр: " << digit << endl;
        if (fclose(file) == EOF)
        {
            cout << "Ошибка закрытия файла." << endl;
        }
        else
        {
            cout << "Файл закрыт." << endl;
        }
    }
    */
    
    std::cout << "Домашнее задание 21.3" << endl;
    char path1[50] = "C:\\1\\1\\newfile.txt";
    char path2[50] = "C:\\1\\1\\Caesar.txt";
    FILE* newFile, * Caesar;
    fopen_s(&newFile, path1, "r");
    fopen_s(&Caesar, path2, "w");
    int cipher;
    int key = 2;
    if (newFile == NULL)
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        if (Caesar == NULL)
        {
            cout << "Ошибка записи файла!" << endl;
        }
        else
        {
            while (!feof(newFile))
            {
                cipher = fgetc(newFile);
                cipher += key;
                fprintf(Caesar, "%c", cipher);

            }

            if (fclose(Caesar) == EOF)
            {
                cout << "Ошибка закрытия файла." << endl;
            }
            else
            {
                cout << "Файл закрыт." << endl;
            }

            fopen_s(&Caesar, path2, "r");
           int sy;
            while (!feof(Caesar))
            {
                sy = fgetc(Caesar);
                cout << (char)sy;
            }

            if (fclose(newFile) == EOF)
            {
                cout << "Ошибка закрытия файла." << endl;
            }
            else
            {
                cout << "Файл закрыт." << endl;
            }
            if (fclose(Caesar) == EOF)
            {
                cout << "Ошибка закрытия файла." << endl;
            }
            else
            {
                cout << "Файл закрыт." << endl;
            }
        
        }
    }
}
