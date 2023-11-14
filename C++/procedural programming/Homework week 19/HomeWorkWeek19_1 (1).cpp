#include <iostream>
#include <Windows.h>
using namespace std;
struct Book
{
    int number = 0;
    string titleOfTheBook;
    string author;
    string publishingHouse;
    string genre;
};
void PrintBook(Book);
void EditBook(Book book[], int number = 0) {
        
    number = number - 1;
    enum Menu
    {
        ALLBOOK = 1,
        TITLEOFTHEBOOK,
        AUTHOR,
        PUBLISHINGHOUSE,
        GENRE,
        OUTPUT,
        EXIT
    };

    int choice;
    do
    {
        cout << "\tМеню редактирования." << endl;
        cout << "1 - Редактировать полностью книгу." << endl;
        cout << "2 - Редактировать название." << endl;
        cout << "3 - Редактировать автора." << endl;
        cout << "4 - Редактировать издательство." << endl;
        cout << "5 - Редактировать жанр." << endl;
        cout << "6 - Вывод книги." << endl;
        cout << "7 - Выход." << endl;
        cout << "Введите пункт меню: " << endl;
        cin >> choice;
        switch (choice)
        {
        case ALLBOOK:
            cout << "Введите название книги: ";
            cin >> book[number].titleOfTheBook;
            cout << "Введите автора: ";
            cin >> book[number].author;
            cout << "Введите издательство: ";
            cin >> book[number].publishingHouse;
            cout << "Введите жанр: ";
            cin >> book[number].genre;
           
            break;
        case TITLEOFTHEBOOK:
            cout << "Введите название книги: ";
            cin >> book[number].titleOfTheBook;
            break;
        case AUTHOR:
            cout << "Введите автора: ";
            cin >> book[number].author;
            break;
        case PUBLISHINGHOUSE:
            cout << "Введите издательство: ";
            cin >> book[number].publishingHouse;
            break;
        case GENRE:
            cout << "Введите жанр: ";
            cin >> book[number].genre;
            break;
        case OUTPUT:
            PrintBook(book[number]);
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
void BookEntry(Book book[], const int count) {
        
    for (int i = 0; i < count; i++)
    {
        book[i].number = i + 1;
        cout << "Книга под номером " << book[i].number << ":" << endl;
        cout << "Введите название книги: ";
        cin >> book[i].titleOfTheBook;
        cout << "Введите автора: ";
        cin >> book[i].author;
        cout << "Введите издательство: ";
        cin >> book[i].publishingHouse;
        cout << "Введите жанр: ";
        cin >> book[i].genre;
        cout << endl;
    }
    
}
void PrintBook(Book book[], const int count) {

    for (int i = 0; i < count; i++)
    {
        cout << "Книга под номером " << book[i].number << ":" << endl;
        cout << "Название книги: " << book[i].titleOfTheBook << endl;
        cout << "Автор: " << book[i].author << endl;
        cout << "Издательство: " << book[i].publishingHouse << endl;
        cout << "Жанр: " << book[i].genre << endl;
        cout << endl;
    }

}
void PrintBook(Book book) {
        
    cout << "Книга под номером " << book.number << ":" << endl;
    cout << "Название книги: " << book.titleOfTheBook << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Издательство: " << book.publishingHouse << endl;
    cout << "Жанр: " << book.genre << endl;
    cout << endl;
    

}
void SearchAuthor(Book book[], const int count, const string key) {
    
    bool isBook = false;
    int position;

    for (int i = 0; i < count; i++)
    {
        if (book[i].author == key)
        {
            isBook = true;
            position = i;
            break;
        }
    }

    if (isBook)
    {
        cout << "Книга найдена!" << endl;
        cout << "Книга под номером " << book[position].number << ":" << endl;
        cout << "Название книги: " << book[position].titleOfTheBook << endl;
        cout << "Автор: " << book[position].author << endl;
        cout << "Издательство: " << book[position].publishingHouse << endl;
        cout << "Жанр: " << book[position].genre << endl;
        cout << endl;
    }
    else
        cout << "Книга отсутствует в библиотеке!" << endl;

}
void SearchTitle(Book book[], const int count, const string key) {

    bool isBook = false;
    int position;

    for (int i = 0; i < count; i++)
    {
        if (book[i].titleOfTheBook == key)
        {
            isBook = true;
            position = i;
            break;
        }
    }

    if (isBook)
    {
        cout << "Книга найдена!" << endl;
        cout << "Книга под номером " << book[position].number << ":" << endl;
        cout << "Название книги: " << book[position].titleOfTheBook << endl;
        cout << "Автор: " << book[position].author << endl;
        cout << "Издательство: " << book[position].publishingHouse << endl;
        cout << "Жанр: " << book[position].genre << endl;
        cout << endl;
    }
    else
        cout << "Книга отсутствует в библиотеке!" << endl;

}
void SortTitleBook(Book book[], const int SIZE) {
    
    string min;
    Book remember;
    int k;
    cout << endl << endl << "Сортировка по названию книги. " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        k = i;
        min = book[i].titleOfTheBook;

        for (int j = i + 1; j < SIZE; j++)
        {
            if (min > book[j].titleOfTheBook)
            {
                min = book[j].titleOfTheBook;
                remember = book[j];
                k = j;
            }
        }

        if (k!=i)
        {
            book[k] = book[i];
            book[i] = remember;
        }
    }

}
void SortAuthor(Book book[], const int SIZE) {

    cout << endl << endl << "Сортировка по автору книги. " << endl;
    int k = SIZE - 1, lb = 1, ub = SIZE - 1;
    Book remember;
    do
    {
        for (int i = ub; i > 0 ; i--)
        {
            if (book[i-1].author > book[i].author)
            {
                remember = book[i - 1];
                book[i - 1] = book[i];
                book[i] = remember;
                k = i;
            }
        }
        lb = k + 1;

        for (int i = 1; i <= ub; i++)
        {
            if (book[i - 1].author > book[i].author)
            {
                remember = book[i - 1];
                book[i - 1] = book[i];
                book[i] = remember;
                k = i;
            }
        }
        ub = k - 1;

    } while (lb < ub);

}
void SortPublishingHouse(Book book[], const int SIZE) {
    
    cout << endl << endl << "Сортировка по издательству книги. " << endl;
    Book remember, x;

    for (int i = 0; i < SIZE; i++)
    {
        x.publishingHouse = book[i].publishingHouse;
        remember = book[i];
        for (int j = i - 1; j >= 0 && book[j].publishingHouse > x.publishingHouse; j--)
        {
            book[j + 1] = book[j];
            book[j + 1] = remember;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Домашнее задание 19.1\n";
    const int SIZE = 10;
    Book Books[SIZE];
    int number;
    string key;
    BookEntry(Books, SIZE);
    PrintBook(Books, SIZE);
    cout << "Введите номер книги для редактирования: " << endl;
    cin >> number;
    EditBook(Books, number);
    cout << "Введите автора для поиска: " << endl;
    cin >> key;
    SearchAuthor(Books, SIZE, key);
    cout << "Введите название книги для поиска: " << endl;
    cin >> key;
    SearchTitle(Books, SIZE, key);
    SortTitleBook(Books, SIZE);
    PrintBook(Books, SIZE);
    SortAuthor(Books, SIZE);
    PrintBook(Books, SIZE);
    SortPublishingHouse(Books, SIZE);
    PrintBook(Books, SIZE);
}
