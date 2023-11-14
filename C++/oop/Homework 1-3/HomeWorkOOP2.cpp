#include <Windows.h>
#include <iostream>
#include <io.h>
#include "Subscriber.h"
using namespace std;

int findSub(Subscriber* subs, int numb) {

    char n[20], sn[20], p[20];
    cout << "Введите фамилию: " << endl;
    gets_s(sn);
    cout << "Введите имя: " << endl;
    gets_s(n);
    cout << "Введите отчество: " << endl;
    gets_s(p);

    for (int i = 0; i < numb; i++)
    {
        if (!(strcmp(subs[i].getName(), n) | strcmp(subs[i].getSurname(), sn) | strcmp(subs[i].getPatronymic(), p)))
        {
            return i;
        }
    }
    return -1;
}
void AddSub(Subscriber* &subs, int& numb) {

    cout << "Добавление абонента." << endl;
    Subscriber* buf = new Subscriber[numb + 1];
    char str[200];
    for (int i = 0; i < numb; i++)
    {
        buf[i].setName(subs[i].getName());
        buf[i].setSurname(subs[i].getSurname());
        buf[i].setPatronymic(subs[i].getPatronymic());
        buf[i].setHomePhone(subs[i].getHomePhome());
        buf[i].setWorkPhone(subs[i].getWorkPhone());
        buf[i].setMobilePhone(subs[i].getMobilePhone());
        buf[i].setAdditInfo(subs[i].getAdditInfo());
    }
    delete[] subs;
    subs = buf;
    numb++;

    cout << "Заполните карточку абонента: " << endl;
    cout << "Фамилия: " << endl;
    gets_s(str);
    subs[numb - 1].setSurname(str);
    cout << "Имя: " << endl;
    gets_s(str);
    subs[numb - 1].setName(str);
    cout << "Отчество: " << endl;
    gets_s(str);
    subs[numb - 1].setPatronymic(str);
    cout << "Домашний телефон: " << endl;
    gets_s(str);
    subs[numb - 1].setHomePhone(str);
    cout << "Рабочий телефон: " << endl;
    gets_s(str);
    subs[numb - 1].setWorkPhone(str);
    cout << "Мобильный телефон: " << endl;
    gets_s(str);
    subs[numb - 1].setMobilePhone(str);
    cout << "Дополнительная информация: " << endl;
    gets_s(str);
    subs[numb - 1].setAdditInfo(str);
}
void DelSub(Subscriber* &subs, int& numb) {
       
    cout << "Удаление абонента." << endl;
    int f = findSub(subs, numb);
    
    if (f != -1)
    {
        Subscriber* buf = new Subscriber[numb - 1];
        for (int i = 0, j = 0; i < numb; i++)
        {
            if (i != f)
            {
                buf[j].setName(subs[i].getName());
                buf[j].setSurname(subs[i].getSurname());
                buf[j].setPatronymic(subs[i].getPatronymic());
                buf[j].setHomePhone(subs[i].getHomePhome());
                buf[j].setWorkPhone(subs[i].getWorkPhone());
                buf[j].setMobilePhone(subs[i].getMobilePhone());
                buf[j].setAdditInfo(subs[i].getAdditInfo());
                j++;
            }
        }
        delete[] subs;
        subs = buf;
        numb--;
    }
    else
    {
        cout << "Не удалось удалить абонента по причине отсутствия в телефонной книге." << endl;
    }

}
void SearchSub(Subscriber* subs, int numb) {
    cout << "Поиск по ФИО." << endl;
    int f = findSub(subs, numb);
    if (f != -1)
    {
        cout << endl << "Фамилия: " << subs[f].getSurname() << endl;
        cout << "Имя: " << subs[f].getName() << endl;
        cout << "Отчество: " << subs[f].getPatronymic() << endl;
        cout << "Домашний телефон: " << subs[f].getHomePhome() << endl;
        cout << "Рабочий телефон: " << subs[f].getWorkPhone() << endl;
        cout << "Мобильный телефон: " << subs[f].getMobilePhone() << endl;
        cout << "Дополнительная информация: " << subs[f].getAdditInfo() << endl;
    }
    else
    {
        cout << "Абонента с таким ФИО нет в телефонной книге." << endl;
    }
}
void PrintSub(Subscriber* subs, int numb) {

    cout << "Телефонная книга." << endl;
    for (int i = 0; i < numb; i++)
    {
        cout << endl << "Фамилия: " << subs[i].getSurname() << endl;
        cout << "Имя: " << subs[i].getName() << endl;
        cout << "Отчество: " << subs[i].getPatronymic() << endl;
        cout << "Домашний телефон: " << subs[i].getHomePhome() << endl;
        cout << "Рабочий телефон: " << subs[i].getWorkPhone() << endl;
        cout << "Мобильный телефон: " << subs[i].getMobilePhone() << endl;
        cout << "Дополнительная информация: " << subs[i].getAdditInfo() << endl;
    }

}
void SaveSub(Subscriber* subs, int numb) {

    cout << "Сохранение в файл абонента." << endl;
    FILE* sub;
    char fname[50];
    char path[50] = "C:\\1\\";
    cout << "Введите имя файла: " << endl;
    gets_s(fname);
    if (strstr(fname, "*.txt") == NULL)
    {

        strcat_s(path, strlen(path) + strlen(fname) + 1, fname);
        strcat_s(path, strlen(path) + 5, ".txt");
    }
    else
    {
        strcat_s(path, strlen(path) + strlen(fname) + 1, fname);
    }

    fopen_s(&sub, path, "w");

    if (sub == NULL)
    {
        cout << "Не удалось сохранить." << endl;
    }
    else
    {
        
        int f = findSub(subs, numb);
        if (f != -1)
        {
            fputs(subs[f].getSurname(), sub);
            fputs("\n", sub);
            fputs(subs[f].getName(), sub);
            fputs("\n", sub);
            fputs(subs[f].getPatronymic(), sub);
            fputs("\n", sub);
            fputs(subs[f].getHomePhome(), sub);
            fputs("\n", sub);
            fputs(subs[f].getWorkPhone(), sub);
            fputs("\n", sub);
            fputs(subs[f].getMobilePhone(), sub);
            fputs("\n", sub);
            fputs(subs[f].getAdditInfo(), sub);
            cout << "Файл сохранен." << endl;
        }
        else
        {
            cout << "Не удалось сохранить абонента по причине отсутствия в телефонной книге." << endl;
        }
    }
    fclose(sub);
}
void LoadSub(Subscriber*& subs, int &numb) {

    cout << "Загрузка абонента из файла." << endl;
    FILE* sub;
    char fname[50];
    char path[50] = "C:\\1\\";
    cout << "Введите имя файла: " << endl;
    gets_s(fname);
    if (strstr(fname, "*.txt") == NULL)
    {
       
        strcat_s(path, strlen(path) + strlen(fname) + 1, fname);
        strcat_s(path, strlen(path) + 5, ".txt");
    }
    else
    {
        strcat_s(path, strlen(path) + strlen(fname) + 1, fname);
    }

    fopen_s(&sub, path, "r");

    if (sub == NULL)
    {
        cout << "Не удалось загрузить." << endl;
    }
    else
    {
        Subscriber* buf = new Subscriber[numb + 1];
        char str[200];
        for (int i = 0; i < numb; i++)
        {
            buf[i].setName(subs[i].getName());
            buf[i].setSurname(subs[i].getSurname());
            buf[i].setPatronymic(subs[i].getPatronymic());
            buf[i].setHomePhone(subs[i].getHomePhome());
            buf[i].setWorkPhone(subs[i].getWorkPhone());
            buf[i].setMobilePhone(subs[i].getMobilePhone());
            buf[i].setAdditInfo(subs[i].getAdditInfo());
        }
        delete[] subs;
        subs = buf;
        numb++;
               

        while (!feof(sub))
        {
            fgets(str, 200, sub);
            subs[numb - 1].setSurname(str);
            fgets(str, 200, sub);
            subs[numb - 1].setName(str);
            fgets(str, 200, sub);
            subs[numb - 1].setPatronymic(str);
            fgets(str, 200, sub);
            subs[numb - 1].setHomePhone(str);
            fgets(str, 200, sub);
            subs[numb - 1].setWorkPhone(str);
            fgets(str, 200, sub);
            subs[numb - 1].setMobilePhone(str);
            fgets(str, 200, sub);
            subs[numb - 1].setAdditInfo(str);
        }

       
    }
    fclose(sub);
}
void Menu() {
    
    char b[2];
    int choice;
    int numb = 0;
    Subscriber* subs = new Subscriber[numb];

    do
    {
        std::cout << "Телефонная книга.\n";
        cout << "Меню." << endl;
        cout << "1 - Добавить нового абонента." << endl;
        cout << "2 - Удалить абонента." << endl;
        cout << "3 - Поиск по ФИО." << endl;
        cout << "4 - Вывод всех абонентов." << endl;
        cout << "5 - Сохранить информацию об абоненте." << endl;
        cout << "6 - Загрузить информацию об абоненте." << endl;
        cout << "7 - Выход." << endl;
        cin >> choice;
        gets_s(b);
        switch (choice)
        {
        case 1:
            AddSub(subs, numb);
            break;
        case 2:
            DelSub(subs, numb);
            break;
        case 3:
            SearchSub(subs, numb);
            break;
        case 4:
            PrintSub(subs, numb);
            break;
        case 5:
            SaveSub(subs, numb);
            break;
        case 6:
            LoadSub(subs, numb);
            break;
        case 7:
            break;
        default:
            cout << "Ошибка. Повторите ввод." << endl;
            break;
        }
    } while (choice  != 7);

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Menu();
  
    
}
