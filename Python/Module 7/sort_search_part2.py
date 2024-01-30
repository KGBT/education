from random import randint

"""
Задание 1
Написать программу «справочник».Создать два списка
целых. Один список хранит идентификационные коды,
второй — телефонные номера. Реализовать меню для
пользователя:
■ Отсортировать по идентификационным кодам;
■ Отсортировать по номерам телефона;
■ Вывести список пользователей с кодами и телефонами;
■ Выход.
"""


def display_dict(codes: list, phonenumbers: list) -> None:
    print("Коды\tНомера телефонов")
    for i in range(len(codes)):
        print(f"{codes[i]}\t\t{phonenumbers[i]}")
    print()


def pred_code_phone(codes: list, phone_numbers: list, j: int, predicate: bool) -> bool:
    if predicate:
        return codes[j] > codes[j + 1]
    return phone_numbers[j] > phone_numbers[j + 1]


def sort_codes_phones(codes: list, phone_numbers: list, predicate=True):
    for i in range(len(codes)):
        swapped = False
        for j in range(len(codes) - i - 1):
            if pred_code_phone(codes, phone_numbers, j, predicate=predicate):
                swapped = True
                codes[j], codes[j + 1] = codes[j + 1], codes[j]
                phone_numbers[j], phone_numbers[j + 1] = phone_numbers[j + 1], phone_numbers[j]
        if not swapped:
            break


def menu():
    choices = ["1", "2", "3", "4"]

    # +7(495)274-05-25
    codes = [str(randint(100, 999)) for _ in range(10)]
    phone_number = [str(randint(100, 999)) + "-" + str(randint(10, 99)) + "-" + str(randint(10, 99)) for _ in range(10)]
    while True:
        print("""
        Меню
1 - Отсортировать по идентификационным кодам;
2 - Отсортировать по номерам телефона;
3 - Вывести список пользователей с кодами и телефонами;
4 - Выход.
        """)
        choice = input("Выберите пункт меню: ")
        if choice == choices[0]:
            sort_codes_phones(codes, phone_number)
        if choice == choices[1]:
            sort_codes_phones(codes, phone_number, predicate=False)
        if choice == choices[2]:
            display_dict(codes, phone_number)
        if choice == choices[3]:
            break
        if choice not in choices:
            print("Такого пункта меню нет!")


# print("Задание 1.")
# menu()


"""
Задание 2
Написать программу «книги». Создать два списка
с данными. Один список хранит название книг, второй - 
годы выпуска. Реализовать меню для пользователя:
■ Отсортировать по названию книг;
■ Отсортировать по годам выпуска;
■ Вывести список книг с названиями и годами выпуска;
■ Выход;
"""


def display_books(name_books: list, year_books: list) -> None:
    print("Названия книги\tГод выпуска")
    for i in range(len(name_books)):
        print(f"{name_books[i]}\t\t\t{year_books[i]}")
    print()


# def merge_books(left_1: list, right_1: list, left_2: list, right_2: list) -> tuple:
#     i = j = 0
#     arr_1 = []
#     arr_2 = []
#     while i < len(left_1) and j < len(right_1):
#         if left_1[i] < right_1[j]:
#             arr_1.append(left_1)
#             arr_2.append(left_2)
#             i += 1
#         else:
#             arr_1.append(right_1[j])
#             arr_2.append(right_2[i])
#             j += 1
#     if i < len(left_1):
#         arr_1.extend(left_1[i:])
#         arr_2.extend(left_2[i:])
#     if j < len(right_1):
#         arr_1.extend(right_1[j:])
#         arr_2.extend(right_2[i:])
#     return [arr_1, arr_2]
#
#
# def divide_books(name_books: list, year_books: list, predicate=True) -> tuple:
#     if predicate:
#         if len(name_books) == 1:
#             return (name_books, year_books)
#         middle = len(name_books) // 2
#         left = divide_books(name_books[:middle], year_books[:middle])
#         right = divide_books(name_books[middle:], year_books[middle:])
#         return merge_books(left[0], right[0], left[1], right[1])
#     else:
#         if len(year_books) == 1:
#             return (year_books, name_books)
#         middle = len(year_books) // 2
#         left = divide_books(year_books[:middle], name_books[:middle])
#         right = divide_books(year_books[middle:], name_books[middle:])
#         return merge_books(left[0], right[0], left[1], right[1])


def pred_name_year(name_book: list, year_book: list, j: int, predicate: bool) -> bool:
    if predicate:
        return name_book[j] > name_book[j + 1]
    return year_book[j] > year_book[j + 1]


def sort_name_year(name_book: list, year_book: list, predicate=True):
    for i in range(len(name_book)):
        swapped = False
        for j in range(len(name_book) - i - 1):
            if pred_code_phone(name_book, year_book, j, predicate=predicate):
                swapped = True
                name_book[j], name_book[j + 1] = name_book[j + 1], name_book[j]
                year_book[j], year_book[j + 1] = year_book[j + 1], year_book[j]
        if not swapped:
            break


def menu_book():
    choices = ["1", "2", "3", "4"]
    name_books = ["Идиот", "Фауст", "Мертвые души", "Записки сумасшедшего", "Моби Дик", "Лолита", "Старик и море", "Дети полуночи"]
    year_books = ["1869", "1832", "1842", "1918", "1851", "1955", "1952", "1981"]
    while True:
        print("""
        Меню
1 - Отсортировать по названию книг;
2 - Отсортировать по годам выпуска;
3 - Вывести список книг с названиями и годами выпуска;
4 - Выход.
        """)
        choice = input("Выберите пункт меню: ")
        if choice == choices[0]:
            sort_name_year(name_books, year_books)
        if choice == choices[1]:
            sort_name_year(name_books, year_books, predicate=False)
        if choice == choices[2]:
            display_books(name_books, year_books)
        if choice == choices[3]:
            break
        if choice not in choices:
            print("Такого пункта меню нет!")


print("Задание 2.")
menu_book()
