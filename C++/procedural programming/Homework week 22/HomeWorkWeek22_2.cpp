#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <io.h>
using namespace std;

void PrintFiles() {
    
    struct _finddata64i32_t findFile;
    long done = 0;
    char path[50];
    char mask[50];
    cout << "Введите путь файла: " << endl;
    gets_s(path);
    cout << "Введите маску файла: " << endl;
    gets_s(mask);
    strcat(path, mask);
        
    intptr_t findHandle = _findfirst(path,&findFile);
    
    while (findHandle && done != -1)
    {
        
        cout << findFile.name << endl;
        done = _findnext(findHandle, &findFile);
    }
        
}

void AddFile() {
    
    char path[50];
    char namef[20];
    FILE* newFile;
    
    cout << "Создание файла." << endl;
    cout << "Введите путь: " << endl;
    gets_s(path, sizeof(path));
    cout << "Введите имя файла: " << endl;
    gets_s(namef);
    strcat(path, namef);

    fopen_s(&newFile, path, "w");
    if (newFile == NULL)
    {
        cout << "Ошибка создания файла!" << endl;
    }
    else
    {
        cout << "Файл создан!" << endl;

        if (fclose(newFile) == EOF)
        {
            cout << "Ошибка закрытия файла!" << endl;
        }
        else
        {
            cout << "Файл закрыт." << endl;
        }
    }

}
void DeleteF() {
    
    char path[50];
    char namef[20];
    PrintFiles();
    cout << "Удаление файла." << endl;
    cout << "Введите путь: " << endl;
    gets_s(path, sizeof(path));
    cout << "Введите имя файла с расширением: " << endl;
    gets_s(namef);
    strcat(path, namef);
        
    if (remove(path) == 0) 
    {
        cout << "Файл удален." << endl;
    }
    else
    {
        cout << "Не удалось удалить файл." << endl;
              
    }



}
void RenameFile() {
    
    PrintFiles();
    char path[50];
    char oldPath[100];
    char newPath[100];
    char oldName[50];
    char newName[50];
    cout << "Переименование файла." << endl;
    cout << "Введите путь: " << endl;
    gets_s(path);
    cout << "Введите текущее имя файла: " << endl;
    gets_s(oldName);
    cout << "Введите новое имя файла: " << endl;
    gets_s(newName);

    strcpy(oldPath, path);
    strcat(oldPath, oldName);

    strcpy(newPath, path);
    strcat(newPath, newName);
    if (rename(oldPath, newPath) == 0)
    {
        cout << "Файл переименован." << endl;
    }
    else
    {
        cout << "Ошибка переименования файла." << endl;
    }
}
void MoveF() {

    PrintFiles();
    char oldPath[100];
    char newPath[100];
    char name[50];
    cout << "Перемещение файла." << endl;
    cout << "Введите текущий путь файла: " << endl;
    gets_s(oldPath);
    cout << "Введите имя файла: " << endl;
    gets_s(name);

    cout << "Введите новый путь файла: " << endl;
    gets_s(newPath);
       
    strcat(oldPath, name);
       
    strcat(newPath, name);

    if (rename(oldPath, newPath) == 0)
    {
        cout << "Файл перемещен." << endl;
    }
    else
    {
        cout << "Ошибка перемещения файла." << endl;
    }
}
void PrintF() {

    char path[50];
    char namef[20];
    char str[100];
    FILE* file;
    PrintFiles();
    cout << "Вывод содержимого файла." << endl;
    cout << "Введите путь: " << endl;
    gets_s(path, sizeof(path));
    cout << "Введите имя файла с расширением: " << endl;
    gets_s(namef);
    strcat(path, namef);
    fopen_s(&file, path, "r");
    if (file == NULL)
    {
        cout << "Ошибка открытия файла." << endl;
    }
    else
    {
        cout << "Файл открыт." << endl;
        while (!feof(file))
        {
            fgets(str, sizeof(str), file);
            cout << str;
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

void Menu() {
    
    int choice;
    char sym[2];
    do
    {
        cout << "1 - Создание нового файла." << endl;
        cout << "2 - Удаление файла из текущего каталога." << endl;
        cout << "3 - Переименование файла." << endl;
        cout << "4 - Перемещение файла." << endl;
        cout << "5 - Вывод файла." << endl;
        cout << "6 - Выход." << endl;
        cin >> choice;
        gets_s(sym);
        switch (choice)
        {
        case 1:
            AddFile();
            break;
        case 2:
            DeleteF();
            break;
        case 3:
            RenameFile();
            break;
        case 4:
            MoveF();
            break;
        case 5:
            PrintF();
            break;
        case 6:
            break;
        default:
            cout << "Ошибка. Повторите ввод." << endl;
            break;
        }
    } while (choice != 6);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Домашнее задание 22.2\n";
    Menu();
}
