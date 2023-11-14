#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*
    std::cout << "Домашнее задание 21.1\n";
    char path1[50] = "C:\\1\\1\\delete.txt";
    char path2[50] = "C:\\1\\1\\newDelete.txt";
    FILE* file1;
    FILE* file2;
    fopen_s(&file1, path1, "r");
    if (file1 == NULL)
    {
        cout << "Ошибка открытия файла." << endl;
    }
    else
    {
        fopen_s(&file2, path2, "w");
        if (file2 == NULL)
        {
            cout << "Ошибка создания файла." << endl;
        }
        else
        {
            int k = 0;
            char str[100][100];

            while (!feof(file1))
            {
                fgets(str[k], sizeof(str[k]), file1);
                k++;
            }
            cout << "Текущий файл: " << endl;
            for (int i = 0; i < k; i++)
            {
                cout << str[i];
            }
            cout << endl << "Введите строку: " << endl;

            char st[100];

            gets_s(st, 100);

            strcpy(str[k - 1], st);

            cout << endl << "Измененная строка: " << endl;
            for (int i = 0; i < k; i++)
            {
                cout << str[i];
            }
            cout << endl;
            for (int i = 0; i < k; i++)
            {
                fprintf(file2, "%s", str[i]);
            }
        }

        if (fclose(file1) == EOF)
        {
            cout << "Ошибка закрытия файла." << endl;
        }
        else
        {
            cout << "Файл закрыт." << endl;
        }
        if (fclose(file2) == EOF)
        {
            cout << "Ошибка закрытия файла." << endl;
        }
        else
        {
            cout << "Файл закрыт." << endl;
        }
    }
    */
    /*
    std::cout << "Домашнее задание 21.2\n";
    char path[50] = "C:\\1\\1\\file.txt";
    FILE* file;
    fopen_s(&file, path, "r");

    if (file == NULL)
    {
        cout << "Не удалось открыть файл." << endl;
    }
    else
    {
        cout << "Файл открыт." << endl;
        char str[100];
        char max[100];
        int len = 0;
        fgets(max, sizeof(max), file);
        len = strlen(max);
        while (!feof(file))
        {
            fgets(str, sizeof(str), file);
            if (strcmp(max,str) < 0)
            {
                strcpy(max, str);
                len = strlen(max);
            }
        }
        cout << "Длина самой длинной строки: " << len << endl;
    }
    if (fclose(file) == EOF)
    {
        cout << "Ошибка закрытия файла." << endl;
    }
    else
    {
        cout << "Файл закрыт." << endl;
    }
    */
    /*
    std::cout << "Домашнее задание 21.3\n";
    char path[50] = "C:\\1\\1\\f.txt";
    FILE* file;
    fopen_s(&file, path, "r");
    if (file == NULL)
    {
        cout << "Ошибка чтения файла." << endl;
    }
    else
    {
        cout << "Файл открыт." << endl;
        char str[20][100];
        char st[100];
        int k = 0;
        int count = 0;
        while (!feof(file))
        {
            fgets(str[k], sizeof(str[k]), file);
            k++;
        }
        for (int i = 0; i < k; i++)
        {
            cout << str[i];
        }
        cout << endl << "Введите слово: " << endl;
        gets_s(st, sizeof(st));

        for (int i = 0; i < k; i++)
        {
            do
            {
                if (strstr(str[i], st))
                {
                    count++;
                    strcpy(str[i], strstr(str[i], st) + strlen(st));
                }
            } while (strstr(str[i],st) != NULL);
        }
        cout << "Количество раз встречаемое слово: " << count << endl;

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

    std::cout << "Домашнее задание 21.4\n";
    char path[50] = "C:\\1\\1\\f.txt";
    FILE* file;
    fopen_s(&file, path, "r");
    if (file == NULL)
    {
        cout << "Ошибка открытия файла." << endl;
    }
    else
    {
        cout << "Файл открыт." << endl;
        char text[20][100];
        char findWord[100];
        char changeWord[100];
        char buf[100]{};
        int k = 0;
        int len = 0;
        while (!feof(file))
        {
            fgets(text[k], sizeof(text[k]), file);
            k++;
        }
        for (int i = 0; i < k; i++)
        {
            cout << text[i];
        }
        cout << endl;
        
        cout << "Введите слово, которое хотите заменить: " << endl;
        gets_s(findWord, sizeof(findWord));

        cout << "Введите слово, на которое хотите заменить: " << endl;
        gets_s(changeWord, sizeof(changeWord));
        int oWsize = strlen(findWord);
        for (int i = 0; i < k; i++)
        {
            do
            {

                if (strstr(text[i], findWord))
                {
                    len = strstr(text[i], findWord) - text[i];

                    buf[0] = '\0';
                    // положим в буфер часть текста до заменяемого слова
                    strncat(buf, text[i], len);
                    //добавим новое слово
                    strcat(buf, changeWord);
                    // добавим оставшуюся часть текста
                    strcat(buf, text[i] + len + oWsize);
                    // text[i][0] = '\0';
                    strcpy(text[i], buf);
                }

            } while (strstr(text[i], findWord) != nullptr);
        }


        cout << "Измененный текст: " << endl;
        for (int i = 0; i < k; i++)
        {
            cout << text[i];
        }
        cout << endl;

        if (fclose(file) == EOF)
        {
            cout << "Ошибка закрытия файла." << endl;
        }
        else
        {
            cout << "Файл закрыт." << endl;
        }
    }
}
