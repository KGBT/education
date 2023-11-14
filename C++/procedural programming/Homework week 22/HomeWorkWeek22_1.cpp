#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

struct Employee
{
   
    char name[50] = "-";
    char surname[50] = "-";
    int age = 0;
    char positionAtWork[50] = "-";
};

void InitProgram(char* path, Employee*& employees, int& k) {
    
    FILE* employ;
    int choice;
    fopen_s(&employ, path, "r");
    if (employ == NULL)
    {
        cout << "Файл со списком сотрудников отсутствует. Хотите создать?" << endl;
        cout << "1 - Да." << endl;
        cout << "2 - Нет." << endl;
        do
        {
            cin >> choice;
            if (choice == 1 || choice == 2)
            {
                break;
            }
            else
            {
                cout << "Ошибка. Повторите ввод." << endl;
            }
        } while (true);

        if (choice == 1)
        {
            fopen_s(&employ, path, "w");
            if (employ == NULL)
            {
                cout << "Ошибка создания базы данных сотрудников." << endl;
            }
            else
            {
                cout << "База данных сотрудников создана." << endl;
                              
                fprintf(employ, "%d", k);
                if (fclose(employ) == EOF)
                {
                    cout << "Ошибка закрытия базы данных." << endl;
                }
                else
                {
                    cout << "База данных закрыта." << endl;
                }
            }
        }
        if (choice == 2)
        {
            cout << "Для продолжения работы необходимо создать базу данных." << endl;
        }

    }
    else
    {
        delete[] employees;
        
        fscanf_s(employ, "%d", &k);
        employees = new Employee[k];

        while (!feof(employ))
        {
            for (int i = 0; i < k; i++)
            {
                fgets(employees[i].name, sizeof(employees[i].name), employ);
                fgets(employees[i].surname, sizeof(employees[i].surname), employ);
                fscanf_s(employ, "%d", &employees[i].age);
                fgets(employees[i].positionAtWork, sizeof(employees[i].positionAtWork), employ);
            }
        }

        if (fclose(employ) == EOF)
        {
            cout << "Ошибка закрытия базы данных." << endl;
        }
        else
        {
            cout << "База данных сотрудников загружена." << endl;
        }
    }

}
void AddBD(Employee*& employees, int & k) {
    
    cout << "Добавление существующей БД." << endl;
    char path[50];
    char name[50]{};
    cout << "Введите полный путь: " << endl;
    gets_s(path);
    cout << "Введите имя БД: " << endl;
    gets_s(name);
    strcat(path, name);
    FILE* employ;
    fopen_s(&employ, path, "r");

    if (employ == NULL)
    {
        cout << "Ошибка загрузки БД." << endl;
    }
    else
    {
        delete[] employees;
        
        fscanf_s(employ, "%d", &k);

        employees = new Employee[k];

        while (!feof(employ))
        {
            for (int i = 0; i < k; i++)
            {
                fgets(employees[i].name, sizeof(employees[i].name), employ);
                fgets(employees[i].surname, sizeof(employees[i].surname), employ);
                fscanf_s(employ, "%d", &employees[i].age);
                fgets(employees[i].positionAtWork, sizeof(employees[i].positionAtWork), employ);
            }
        }

        if (fclose(employ) == EOF)
        {
            cout << "Ошибка закрытия базы данных." << endl;
        }
        else
        {
            cout << "База данных сотрудников загружена." << endl;
        }
    }
    

}
void AddEmp(Employee*& employees, int& k) {
    
    Employee* buf = new Employee[k + 1];
    for (int i = 0; i < k; i++)
    {
        
        strcpy(buf[i].name, employees[i].name);
        strcpy(buf[i].surname, employees[i].surname);
        buf[i].age = employees[i].age;
        strcpy(buf[i].positionAtWork, employees[i].positionAtWork);

    }
    delete[]employees;
    k++;
    employees = buf;
    char b[3];
    cout << endl << "Ввод данных сотрудника." << endl;
    cout  << "Введите данные нового сотрудника: " << endl;
    cout << "Введите имя: " << endl;
    gets_s(employees[k-1].name);
    cout << "Введите фамилию: " << endl;
    gets_s(employees[k - 1].surname);
    cout << "Введите возраст: " << endl;
    cin >> employees[k - 1].age;
    gets_s(b);
    cout << "Введите должность: " << endl;
    gets_s(employees[k - 1].positionAtWork);
    cout << endl << "Информация загружена." << endl;
}
void OutputAllEmp(Employee* employees, int k) {

    cout << "Информация по всем сотрудникам: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << endl << "Имя: ";
        puts(employees[i].name);
        cout << "Фамилия: ";
        puts(employees[i].surname);
        cout << "Возраст: " << employees[i].age << endl;;
        cout << "Должность: ";
        puts(employees[i].positionAtWork);

    }

}
int SearchPosEmp(Employee* employees, int k) {
    

    cout << endl << "Введите фамилию: " << endl;
    char surname[50]{};

    gets_s(surname);

    for (int i = 0; i < k; i++)
    {
        if (_stricmp(employees[i].surname, surname) == 0)
        {
            return i;
        }
    }

    return -1;
}
void ChangeEmp(Employee* employees, int k) {
    
    cout << endl << "Редактирование данных сотрудника: " << endl;
    cout << "Хотите вывести базу по всем сотрудникам?" << endl;
    cout << "1 - Да." << endl;
    cout << "2 - Нет." << endl;
    int choice;
    char str[50];
    char b[3];
    int pos;
    do
    {
        cin >> choice;
        gets_s(b);
        if (choice == 1 || choice == 2)
        {
            break;
        }
        else
        {
            cout << "Ошибка. Повторите ввод." << endl;
        }
    } while (true);

    if (choice == 1)
    {
        OutputAllEmp(employees, k);
    }
    
    pos = SearchPosEmp(employees, k);

    if (pos == -1)
    {
        cout << "Сотрудник с такой фамилией отсутствует! Повториите поиск." << endl;
    }
    else
    {
        
        cout << "Сотрудник найден!" << endl;
        cout << "Введите новые данные: " << endl;
        cout << "Введите имя: " << endl;
        gets_s(str);
        strcpy(employees[pos].name, str);
        cout << "Введите фамилию: " << endl;
        gets_s(str);
        strcpy(employees[pos].surname, str);
        cout << "Введите возраст: " << endl;
        cin >> employees[pos].age;
        gets_s(b);
        cout << "Введите должность: " << endl;
        gets_s(str);
        strcpy(employees[pos].positionAtWork, str);
        cout << endl << "Информация загружена." << endl;
    }
}
void DelEmp(Employee*& employees, int &k) {

    cout << endl << "Удаление сотрудника из БД: " << endl;
    cout << "Хотите вывести базу по всем сотрудникам?" << endl;
    cout << "1 - Да." << endl;
    cout << "2 - Нет." << endl;
    int choice;
    char b[3];
    int pos;
    do
    {
        cin >> choice;
        gets_s(b);
        if (choice == 1 || choice == 2)
        {
            break;
        }
        else
        {
            cout << "Ошибка. Повторите ввод." << endl;
        }
    } while (true);

    if (choice == 1)
    {
        OutputAllEmp(employees, k);
    }

    pos = SearchPosEmp(employees, k);

    if (pos == -1)
    {
        cout << "Сотрудник с такой фамилией отсутствует! Повториите поиск." << endl;
    }
    else
    {
        cout << "Сотрудник найден! Производим удаление..." << endl;
        Employee* buf = new Employee[k - 1];
        int j = 0;
        for (int i = 0 ; i < k; i++)
        {
            if (i == pos)
            {
                continue;
            }
            else
            {
                strcpy(buf[j].name, employees[i].name);
                strcpy(buf[j].surname, employees[i].surname);
                buf[j].age = employees[i].age;
                strcpy(buf[j].positionAtWork, employees[i].positionAtWork);
                j++;
            }
           
        }
        delete[]employees;
        k--;
        employees = buf;
        cout << "Сотрудник удален." << endl;
    }
}
void SaveBD(Employee* employees, int k, char* path) {

    FILE* employ;
    fopen_s(&employ, path, "w");

    if (employ == NULL)
    {
        cout << "Ошибка сохранения файла." << endl;
    }
    else
    {
        fprintf(employ, "%d", k);
        fprintf(employ, "%s", "\n");
        for (size_t i = 0; i < k; i++)
        {
            fprintf(employ, "%s", employees[i].name);
            fprintf(employ, "%s", "\n");
            fprintf(employ, "%s", employees[i].surname);
            fprintf(employ, "%s", "\n");
            fprintf(employ, "%d", employees[i].age);
            fprintf(employ, "%s", "\n");
            fprintf(employ, "%s", employees[i].positionAtWork);
        }

        if (fclose(employ) == EOF)
        {
            cout << "Ошибка сохранения файла." << endl;
        }
        else
        {
            cout << "БД сохранена." << endl;
        }
    }

}
void SearchEmpAge(Employee* employees, int k, Employee*& findEmp, int& f) {
    
   
    f = 0;
    int age;
    char b[3];
    bool isFind = false;
    cout << "Введите возраст сотрудника: " << endl;
    cin >> age;
    gets_s(b);
    for (int i = 0; i < k; i++)
    {
        if (employees[i].age == age)
        {
            isFind = true;
            f++;
        }
    }

    if (isFind)
    {
        delete[]findEmp;
        findEmp = new Employee[f];
        int fJ = 0;
        for (int i = 0; i < k; i++)
        {
            if (employees[i].age == age)
            {
                strcpy(findEmp[i].name, employees[i].name);
                strcpy(findEmp[i].surname, employees[i].surname);
                findEmp[i].age = employees[i].age;
                strcpy(findEmp[i].positionAtWork, employees[i].positionAtWork);


                cout << endl << "Имя: ";
                puts(findEmp[i].name);
                cout << "Фамилия: ";
                puts(findEmp[i].surname);
                cout << "Возраст: " << findEmp[i].age << endl;;
                cout << "Должность: ";
                puts(findEmp[i].positionAtWork);
            }
        }



    }
    else
    {
        cout << "Не найдено!" << endl;
    }

}
void SearchEmpSur(Employee* employees, int k, Employee*& findEmp, int& f) {

   
    f = 0;
    int age;
    char sSurName[50];
    bool isFind = false;
    cout << "Введите первую букву фамилии: " << endl;
    gets_s(sSurName);
    for (int i = 0; i < k; i++)
    {
        if (strstr(employees[i].surname, sSurName) != NULL)
        {
            isFind = true;
            f++;
        }
    }

    if (isFind)
    {
        delete[]findEmp;
        findEmp = new Employee[f];
        int fJ = 0;
        for (int i = 0; i < k; i++)
        {
            if (strstr(employees[i].surname, sSurName) != NULL)
            {
                strcpy(findEmp[i].name, employees[i].name);
                strcpy(findEmp[i].surname, employees[i].surname);
                findEmp[i].age = employees[i].age;
                strcpy(findEmp[i].positionAtWork, employees[i].positionAtWork);


                cout << endl << "Имя: ";
                puts(findEmp[i].name);
                cout << "Фамилия: ";
                puts(findEmp[i].surname);
                cout << "Возраст: " << findEmp[i].age << endl;;
                cout << "Должность: ";
                puts(findEmp[i].positionAtWork);
            }
        }



    }
    else
    {
        cout << "Не найдено!" << endl;
    }

}
void SaveSearch(Employee* findEmp, int f) {

    FILE* employ;
    char path[50] = "C:\\1\\";
    char nameF[50];
    cout << "Введите имя файла: " << endl;
    gets_s(nameF);
    strcat(path, nameF);
    strcat(path, ".txt");
    fopen_s(&employ, path, "w");

    if (employ == NULL)
    {
        cout << "Ошибка сохранения." << endl;
    }
    else
    {
        cout << "Файл сохранен." << endl;
        for (size_t i = 0; i < f; i++)
        {
            fprintf(employ, "%s", findEmp[i].name);
            fprintf(employ, "%s", "\n");
            fprintf(employ, "%s", findEmp[i].surname);
            fprintf(employ, "%s", "\n");
            fprintf(employ, "%d", findEmp[i].age);
            fprintf(employ, "%s", "\n");
            fprintf(employ, "%s", findEmp[i].positionAtWork);
            fprintf(employ, "%s", "\n");
        }
        fclose(employ);

    }

}

void SubMenu(Employee* employees, int k, Employee*& findEmp, int& f){
    

    int choice;
    char b[3];

 
    do
    {
        cout << "Вывод всех сотрудников: " << endl;
        cout << "1 - Вывод сотрудников по возрасту. " << endl;
        cout << "2 - Вывод по фамилии." << endl;
        cout << "3 - Выход. " << endl;
        cin >> choice;
        gets_s(b);

        switch (choice)
        {
        case 1:
            SearchEmpAge(employees, k, findEmp, f);
            break;
        case 2:
            SearchEmpSur(employees, k, findEmp, f);
            break;
        case 3:
            break;
        default: 
            cout << "Ошибка ввода. Повторите." << endl;
            break;
        }


    } while (choice != 3);
}
void Menu() {
    
    int k = 0, f = 0;
    Employee* employees = new Employee[k];
    Employee* findEmp = new Employee[f];
    int choice;
    char buf[3];
    char path[50] = "C:\\1\\employeers.txt";
    InitProgram(path, employees, k);
   
    do
    {
        cout << endl << "Информационная система \"Сотрудники\"." << endl;
        cout << "1 - Инициализация БД." << endl;
        cout << "2 - Ввод данных сотрудника." << endl;
        cout << "3 - Редактирование данных сотрудника." << endl;
        cout << "4 - Удаление сотрудника из БД." << endl;
        cout << "5 - Поиск сотрудника." << endl;
        cout << "6 - Вывод всех сотрудников." << endl;
        cout << "7 - Сохранить информацию в файл." << endl;
        cout << "8 - Сохранить БД." << endl;
        cout << "9 - Выход." << endl;
        cin >> choice;
        gets_s(buf);

        switch (choice)
        {
        case 1:
            AddBD(employees, k);
            break;
        case 2:
            AddEmp(employees, k);
            break;
        case 3:
            ChangeEmp(employees, k);
            break;
        case 4:
            DelEmp(employees, k);
            break;
        case 5:
            SubMenu(employees, k, findEmp, f);
            break;
        case 6:
            OutputAllEmp(employees, k);
            break;
        case 7:
            SaveSearch(findEmp, f);
            break;
        case 8:
            SaveBD(employees, k, path);
            break;
        case 9:
            FILE * employ;
            fopen_s(&employ, path, "w");

            if (employ == NULL)
            {
               
            }
            else
            {
                fprintf(employ, "%d", k);
                fprintf(employ, "%s", "\n");
                for (size_t i = 0; i < k; i++)
                {
                    fprintf(employ, "%s", employees[i].name);
                    fprintf(employ, "%s", "\n");
                    fprintf(employ, "%s", employees[i].surname);
                    fprintf(employ, "%s", "\n");
                    fprintf(employ, "%d", employees[i].age);
                    fprintf(employ, "%s", "\n");
                    fprintf(employ, "%s", employees[i].positionAtWork);
                    fprintf(employ, "%s", "\n");
                }
                fclose(employ);
                
            }
            cout << "Пока!" << endl;

            break;
        default:
            cout << "Ошибка ввода. Повторите." << endl;
            break;
        }
    } while (choice != 9);

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Домашнее задание 22.1\n";
    Menu();
}
