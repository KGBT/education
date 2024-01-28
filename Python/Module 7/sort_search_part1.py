from random import randint

"""
Задание 1
Необходимо отсортировать первые две трети списка
в порядке возрастания, если среднее арифметическое
всех элементов больше нуля; иначе — лишь первую треть.
Остальную часть списка не сортировать, а расположить
в обратном порядке.
"""


def sort_part(arr: list, len_coeff: int) -> None:
    for i in range(len_coeff):
        for j in range(len_coeff - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def sort_arr(arr: list) -> list:
    buff: list
    aver = sum(arr) / len(arr)
    len_coeff_1 = int(2 / 3 * len(arr))
    len_coeff_2 = int(1 / 3 * len(arr))
    if aver > 0:
        sort_part(arr, len_coeff_1)
        buff = arr[len_coeff_1:]
        buff.reverse()
        arr[len_coeff_1:] = buff
    else:
        sort_part(arr, len_coeff_2)
        buff = arr[len_coeff_2:]
        buff.reverse()
        arr[len_coeff_2:] = buff


print("Задание 1.")
arr = [randint(-10, 10) for _ in range(15)]
print(f"Массив до сортировки: {arr}.")
sort_arr(arr)
print(f"Массив после сортировки: {arr}.")

"""
Задание 2
Написать программу «успеваемость». Пользователь
вводит 10 оценок студента. Оценки от 1 до 12. Реализовать
меню для пользователя:
■ Вывод оценок (вывод содержимого списка);
■ Пересдача экзамена (пользователь вводит номер элемента списка и новую оценку);
■ Выходит ли стипендия (стипендия выходит, если
средний бал не ниже 10.7);
■ Вывод отсортированного списка оценок: по возрастанию или убыванию.
"""


def input_marks(marks: list) -> None:
    while len(marks) != 10:
        try:
            mark = int(input("Введите оценку студента от 1 до 12: "))
            if mark < 1 or mark > 12:
                raise Exception("Оценка должна находиться в диапазоне от 1 до 12.")
            marks.append(mark)
        except ValueError:
            print("Ожидалась цифра!")
        except Exception as e:
            print(e)


def print_all_marks(marks: list) -> None:
    #     print("Номер оценки ", end=" ")
    #     for mark in marks["Номер оценки"]:
    #         print(mark, end=" ")
    #     print()
    #     print("Оценка       ", end=" ")
    #     for mark in marks["Оценка"]:
    #         print(mark, end=" ")
    #     print()
    print("Оценки: ", end=" ")
    for mark in marks:
        print(mark, end=" ")
    print()


def retaking_mark(marks: list) -> None:
    try_ = 0
    while try_ == 0:
        try:
            numb_mark = int(input("Введите номер оценки: "))
            mark = int(input("Введите оценку студента от 1 до 12: "))
            if numb_mark < 1 or numb_mark > 10:
                raise Exception("Номер оценки должен находиться в диапазоне от 1 до 10")
            if mark < 1 or mark > 12:
                raise Exception("Оценка должна находиться в диапазоне от 1 до 12.")
            marks[numb_mark - 1] = mark
            try_ += 1
        except ValueError:
            print("Ожидалась цифра!")
        except Exception as e:
            print(e)


def is_scholarship(marks: list) -> bool:
    aver = sum(marks) / len(marks)
    if aver >= 10.7:
        return True
    return False


def sort_marks(marks: list, reverse=False) -> None:
    sorted_marks = sorted(marks, reverse=reverse)
    print("Список оценок: ")
    for mark in sorted_marks:
        print(mark, end=" ")
    print()


def sub_menu(marks: list) -> None:
    choices = ["1", "2", "3"]
    while True:
        print("""
    Выберите вариант сортировки:
1 - По возрастанию.
2 - По убыванию.
3 - Выход.
""")
        choice = input("Введите пункт: ")
        if choice == choices[0]:
            sort_marks(marks)
        if choice == choices[1]:
            sort_marks(marks, reverse=True)
        if choice == choices[2]:
            break
        if choice not in choices:
            print("Ошибка! Такого пункта нет!")


def menu():
    choices = ["1", "2", "3", "4", "5", "6"]
    marks = []
    while True:
        print("""
        Меню.
1 - Ввод оценок студента;
2 - Вывод оценок студента;
3 - Пересдача экзамена (пользователь вводит номер элемента списка и новую оценку);
4 - Выходит ли стипендия;
5 - Вывод отсортированного списка оценок.
6 - Выход.
        """)
        choice = input("Выберите пункт меню: ")
        if choice == choices[0]:
            input_marks(marks)
        if choice == choices[1]:
            if len(marks) == 0:
                print("Оценки отсутствуют!")
            else:
                print_all_marks(marks)
        if choice == choices[2]:
            if len(marks) == 0:
                print("Оценки отсутствуют!")
            else:
                print_all_marks(marks)
                retaking_mark(marks)
        if choice == choices[3]:
            if len(marks) == 0:
                print("Оценки отсутствуют!")
            else:
                if is_scholarship(marks):
                    print("Стипендия будет выплачиватся.")
                else:
                    print("Стипендия не будет выплачиваться.")
        if choice == choices[4]:
            if len(marks) == 0:
                print("Оценки отсутствуют!")
            else:
                sub_menu(marks)

        if choice not in choices:
            print("Ошибка! Такого пункта меню нет!")
        if choice == choices[5]:
            break


# print("Задание 2.")
# menu()


"""
Задание 3
Написать программу, реализующую сортировку списка
методом усовершенствованной сортировки пузырьковым
методом. Усовершенствование состоит в том, чтобы анализировать количество перестановок на каждом шагу, если
это количество равно нулю, то продолжать сортировку
нет смысла — список отсортирован.
"""


def bubble_sort(arr: list):
    for i in range(len(arr)):
        swapped = False
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
        if not swapped:
            break


print("Задание 3.")
arr = [randint(-10, 10) for _ in range(15)]
print(f"Неотсортированный массив: {arr}.")
bubble_sort(arr)
print(f"Отсортированный массив: {arr}.")
