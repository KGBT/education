#include <iostream>
#include <Windows.h>
using namespace std;
struct Student
{
    string surname;
    string group;
    int k = 5;
    int* academicPerformans = new int [k];
};
void InputSt(Student student[], const int COUNT) {
    
    cout << "Заполните журнал:" << endl;
    cout << "Фамилия:\tГруппа:\t\tУспеваемость:" << endl;
    for (int i = 0; i < COUNT; i++)
    {
        cout << "Введите фамилию: ";
        cin >> student[i].surname;
        cout << "Введите группу: ";
        cin >> student[i].group;
        cout << "Введите оценки студента: ";
        for (int j = 0; j < student[i].k; j++)
        {
            cin >> student[i].academicPerformans[j];
        }
        cout << endl;
    }
    cout << endl;

}
void OutputSt(Student student[], const int COUNT) {

    cout << "Журнал успеваемости:" << endl;
    cout << "Фамилия:\tГруппа:\t\tУспеваемость:" << endl;
    for (int i = 0; i < COUNT; i++)
    {
        cout << student[i].surname << " \t\t" << student[i].group << " \t\t";
        for (int j = 0; j < student[i].k; j++)
        {
            cout << student[i].academicPerformans[j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}
void ChangeSt(Student* &student, int& COUNT) {  //функция, динамически изменяющая размер массива

    int choice;
    int f = 0;
    string surname;
    enum Menu
    {
        ADD = 1,
        DELETEST,
        EXIT
    };

    do
    {
        Student* buffer;
        cout << "\tМеню:" << endl;
        cout << "1 - Добавить студента." << endl;
        cout << "2 - Удалить студента." << endl;
        cout << "3 - Выход." << endl;
        cout << "Выберите пункт меню: " << endl;
        cin >> choice;
        switch (choice)
        {
        case ADD:
            
            COUNT++;
            buffer = new Student[COUNT];

            for (int i = 0; i < COUNT-1; i++)
            {
                buffer[i].surname = student[i].surname;
                buffer[i].group = student[i].group;
                for (int j = 0; j < student[i].k; j++)
                {
                    buffer[i].academicPerformans[j] = student[i].academicPerformans[j];
                }
            }
            
            for (int i = 0; i < COUNT-1; i++)
            {
                delete[] student[i].academicPerformans;
            }
            delete[] student;
                       
            student = buffer;
            
            cout << "Заполните запись в журнале:" << endl;
            cout << "Фамилия:\tГруппа:\t\tУспеваемость:" << endl;
            cout << "Введите фамилию: ";
            cin >> student[COUNT-1].surname;
            cout << "Введите группу: ";
            cin >> student[COUNT - 1].group;
            cout << "Введите оценки студента: ";
            for (int j = 0; j < student[COUNT - 1].k; j++)
            {
                cin >> student[COUNT - 1].academicPerformans[j];
            }
            cout << endl;
           
            break;


        case DELETEST:
            COUNT--;
            buffer = new Student[COUNT];
            cout << "Введите фамилию удаляемого студента: " << endl;
            cin >> surname;
            for (int i = 0; i < COUNT+1; i++)
            {

                if (student[i].surname == surname)
                {
                    continue;
                }
                else {

                    buffer[f].surname = student[i].surname;
                    buffer[f].group = student[i].group;
                    for (int j = 0; j < student[i].k; j++)
                    {
                        buffer[f].academicPerformans[j] = student[i].academicPerformans[j];
                    }
                    f++;
                }

            }
            
            for (int i = 0; i < COUNT+1; i++)
            {
                delete[] student[i].academicPerformans;
            }
            delete[] student;
            
            student = buffer;


            break;
        case EXIT:
            cout << "Пока!" << endl;
            break;
        default:
            cout << "Ошибка! Повторите ввод!" << endl;
            break;
        }
    } while (choice != 3);

}
void OutputExcellent(Student student[], const int  COUNT) {
    
    float sumTotal = 0, sumExcell = 0;
    cout << "Список отличников: " << endl;
    for (int i = 0; i < COUNT; i++)
    {
        sumExcell = 0;
        sumTotal = 0;
        for (int j = 0; j < student[i].k; j++)
        {
            sumTotal++;
            if (student[i].academicPerformans[j] == 5)
            {
                sumExcell++;
            }
        }
        if ((sumExcell / sumTotal) >= 0.75)
        {
            cout << student[i].surname << " \t\t" << student[i].group << " \t\t";
            for (int j = 0; j < student[i].k; j++)
            {
                cout << student[i].academicPerformans[j] << " ";
            }
            cout << endl;
        }
    }

}
void OutputLosers(Student student[], const int  COUNT) {

    float sumTotal = 0, sumLosers = 0;
    cout << "Список двоечников: " << endl;
    for (int i = 0; i < COUNT; i++)
    {
        sumLosers = 0;
        sumTotal = 0;
        for (int j = 0; j < student[i].k; j++)
        {
            sumTotal++;
            if (student[i].academicPerformans[j] <= 3)
            {
                sumLosers++;
            }
        }
        if ((sumLosers / sumTotal) >= 0.50)
        {
            cout << student[i].surname << " \t\t" << student[i].group << " \t\t";
            for (int j = 0; j < student[i].k; j++)
            {
                cout << student[i].academicPerformans[j] << " ";
            }
            cout << endl;
        }
    }

}


struct Date {

    int day;
    int month;
    int year;

};
struct Man{
    string surname;
    string name;
    int age;
    Date date;
};
void PrintSortName(Man* man, const int size) {
    
    int left = 0, right = size - 1;
    Man name;
    while (left <= right)
    {
        for (int i = right; i > left; --i)
        {
            if (man[i-1].name > man[i].name)
            {
                name = man[i];
                man[i] = man[i - 1];
                man[i - 1] = name;
            }
            
        }
        ++left;
        for (int i = left; i < right; ++i)
        {
            if (man[i].name > man[i+1].name)
            {
                name = man[i];
                man[i] = man[i - 1];
                man[i - 1] = name;
            }

        }
        --right;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Фамилия: "<< man[i].surname <<"\tИмя: " << man[i].name << "\t\tВозраст: " << man[i].age << "\tДата рождения: " << man[i].date.day 
            << "." << man[i].date.month << "." << man[i].date.year << endl;
            
       
    }

}
void InputMan(Man man[], const int size) {
    cout << "Заполните массив Man:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << endl <<"Введите фамилию: " << endl;
        cin >> man[i].surname;
        cout << "Введите имя: " << endl;
        cin >> man[i].name;
        cout << "Введите возраст: " << endl;
        cin >> man[i].age;
        cout << "Введите день Рождения: " << endl;
        cin >> man[i].date.day;
        cout << "Введите месяц Рождения: " << endl;
        cin >> man[i].date.month;
        cout << "Введите год Рождения: " << endl;
        cin >> man[i].date.year;
    }
}
void PrintBirthdey(Man man[], const int size, const int month) {
    
    bool flag = false;
   
    cout << "Список именинников в " << month << " месяце: " << endl;
    if (month >=1 && month <= 12)
    {
        

        for (int i = 0; i < size; i++)
        {
            
            if (man[i].date.month == month)
            {
                flag = true;
                cout << "Фамилия: " << man[i].surname << "\tИмя: " << man[i].name << "\t" << "\tДата рождения: " << man[i].date.day
                    << "." << man[i].date.month << "." << man[i].date.year << endl;
            }
           
        }
        
        if (!flag)
        {
            cout << "Именинники в данном месяце отсутствуют!" << endl;
        }

    }
    else
        cout << "Количество месяцев от 1 до 12!" << endl;
    

}
void ChangeMan(Man*& man, int& size) {
    
    int choice;
   
    
    enum Menu
    {
        ADD = 1,
        DELETEMAN,
        EXIT
    };

    do
    {
        Man* buffer;
        string delSurname;
        int num = 0;
       
       
        cout << "\tМеню:" << endl;
        cout << "1 - Добавить запись." << endl;
        cout << "2 - Удалить запись." << endl;
        cout << "3 - Выход." << endl;
        cout << "Выберите пункт меню: " << endl;
        cin >> choice;
        switch (choice)
        {
        case ADD:
            size++;
            buffer = new Man[size];

            for (int i = 0; i < size - 1; i++)
            {
                buffer[i].name = man[i].name;
                buffer[i].surname = man[i].surname;
                buffer[i].age = man[i].age;
                buffer[i].date.day = man[i].date.day;
                buffer[i].date.month = man[i].date.month;
                buffer[i].date.year = man[i].date.year;
                             
            }

            delete[] man;
            man = buffer;
                                   
            cout << "Заполните запись:" << endl;
            cout << endl << "Введите фамилию: " << endl;
            cin >> man[size-1].surname;
            cout << "Введите имя: " << endl;
            cin >> man[size - 1].name;
            cout << "Введите возраст: " << endl;
            cin >> man[size - 1].age;
            cout << "Введите день Рождения: " << endl;
            cin >> man[size - 1].date.day;
            cout << "Введите месяц Рождения: " << endl;
            cin >> man[size - 1].date.month;
            cout << "Введите год Рождения: " << endl;
            cin >> man[size - 1].date.year;
            
            cout << endl;
         
            
            break;



        case DELETEMAN:
            
            size--;
            buffer = new Man[size];
            cout << "Введите фамилию, которую хотите удалить: " << endl;
            cin >> delSurname;
            for (int j = 0; j < size + 1; j++)
            {
                if (delSurname == man[j].surname)
                {

                    cout << "Запись удалена!" << endl;
                   
                    continue;
                }
                else
                {
                    buffer[num].name = man[j].name;
                    buffer[num].surname = man[j].surname;
                    buffer[num].age = man[j].age;
                    buffer[num].date.day = man[j].date.day;
                    buffer[num].date.month = man[j].date.month;
                    buffer[num].date.year = man[j].date.year;
                    num++;
                   
                }
            }
           
            delete[] man;
            man = buffer;
                        
            cout << endl;
            break;
        case EXIT:
            cout << "Пока!" << endl;
            break;
        default:
            cout << "Ошибка! Повторите ввод!" << endl;
            break;
        }
    } while (choice != 3);


}
void SearchSurnameName(Man* man, int size) {
    cout << "Поиск по фамилии и имени." << endl;
    string sur, name;
    bool flag = false;
    int pos;
    cout << "Введите фамилию и имя: " << endl;
    cin >> sur >> name;
    for (int i = 0; i < size; i++)
    {
        if (man[i].surname == sur && man[i].name == name)
        {
            flag = true;
            pos = i;
            break;
        }
    }
    if (flag)
    {
        cout << "Запись найдена!" << endl;
        cout << "Фамилия: " << man[pos].surname << "\tИмя: " << man[pos].name << "\t\tВозраст: " << man[pos].age << "\tДата рождения: " << man[pos].date.day
            << "." << man[pos].date.month << "." << man[pos].date.year << endl;
    }
    else
    {
        cout << "Запись не найдена!" << endl;
    }
}
void EditMans(Man* man, int size) {

    cout << "Введите номер записи для редактирования: " << endl;
    int number;
    cin >> number;
    enum Menu
    {
        ALLMANS = 1,
        SURNAME,
        NAME,
        AGE,
        DATE,
        OUTPUT,
        EXIT
    };

    int choice;
    do
    {
        cout << "\tМеню редактирования." << endl;
        cout << "1 - Редактировать запись полностью." << endl;
        cout << "2 - Редактировать фамилию." << endl;
        cout << "3 - Редактировать имя." << endl;
        cout << "4 - Редактировать возраст." << endl;
        cout << "5 - Редактировать дату рождения." << endl;
        cout << "6 - Вывод записей." << endl;
        cout << "7 - Выход." << endl;
        cout << "Введите пункт меню: " << endl;
        cin >> choice;
        switch (choice)
        {
        case ALLMANS:
            cout << endl << "Введите фамилию: " << endl;
            cin >> man[number].surname;
            cout << "Введите имя: " << endl;
            cin >> man[number].name;
            cout << "Введите возраст: " << endl;
            cin >> man[number].age;
            cout << "Введите день Рождения: " << endl;
            cin >> man[number].date.day;
            cout << "Введите месяц Рождения: " << endl;
            cin >> man[number].date.month;
            cout << "Введите год Рождения: " << endl;
            cin >> man[number].date.year;

            break;
        case SURNAME:
            cout << "Введите фамилию: " << endl;
            cin >> man[number].surname;
            break;
        case NAME:
            cout << "Введите имя: " << endl;
            cin >> man[number].name;
            break;
        case AGE:
            cout << "Введите возраст: " << endl;
            cin >> man[number].age;
            break;
        case DATE:
            cout << "Введите день Рождения: " << endl;
            cin >> man[number].date.day;
            cout << "Введите месяц Рождения: " << endl;
            cin >> man[number].date.month;
            cout << "Введите год Рождения: " << endl;
            cin >> man[number].date.year;
            break;
        case OUTPUT:
            PrintSortName(man, size);
            break;
        case EXIT:
            cout << "До встречи!" << endl;
            break;
        default:
            cout << "Ошибка! Повторите ввод!" << endl;
            break;
        }
    } while (choice != 7);

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   /*
    cout << "Домашнее задание 20.1\n" << endl;
    int COUNT = 4;
    Student* students = new Student[COUNT];
    InputSt(students, COUNT);
    OutputSt(students, COUNT);
    ChangeSt(students, COUNT);
    OutputSt(students, COUNT);
    OutputExcellent(students, COUNT);
    OutputLosers(students, COUNT);
    */
    
    cout << "Домашнее задание 20.2\n" << endl;
    int k = 4;
    int month;
    Man* mans = new Man[k];
    InputMan(mans, k);
    PrintSortName(mans, k);
    cout << "Введите номер месяца: ";
    cin >> month;
    PrintBirthdey(mans, k, month);
    ChangeMan(mans, k);
    PrintSortName(mans, k);
    SearchSurnameName(mans, k);
    EditMans(mans, k);
    
}
