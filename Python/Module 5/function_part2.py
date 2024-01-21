from random import randint

"""
Задание 1
Напишите функцию, вычисляющую произведение
элементов списка целых. Список передаётся
в качестве параметра. Полученный результат
возвращается изфункции.
"""


def multiply(arr: 'list[int]') -> int:
    result = 1
    for i in arr:
        result *= i
    return result


# print("Задание 1.")
# arr = [randint(1, 10) for _ in range(3)]
# print(f"Наш список: {arr}")
# print(f"Произведение чисел: {multiply(arr)}")

"""
Задание 2
Напишите функцию для нахождения минимума в
списке целых. Список передаётся в качестве параметра.
Полученный результат возвращается из функции.
"""


def min_num(arr: 'list[int]') -> int:
    return min(arr)


def min_num2(arr: 'list[int]') -> int:
    min = arr[0]
    for i in arr:
        if min > i:
            min = i
    return min


# print("Задание 2.")
# arr = [randint(1, 10) for _ in range(5)]
# print(f"Наш список: {arr}")
# print(f"Минимальное число в списке: {min_num(arr)}")
# print(f"Минимальное число в списке: {min_num2(arr)}")


"""
Задание 3
Напишите функцию, определяющую количество простых чисел в 
списке целых. Список передаётся в качестве
параметра.Полученный результат возвращается из функции.
"""


def simple_num(arr: 'list[int]') -> int:
    count_simple = 0
    for i in arr:
        count_divider = 0
        if i == 2 or i == 3:
            count_simple += 1
            continue
        if i % 2 == 0 or i == 1:
            continue
        for j in range(3, i // 2 + 1):
            if i % j == 0:
                count_divider += 1
                break
        if count_divider == 0:
            count_simple += 1

    return count_simple


# print("Задание 3.")
# arr = [randint(1, 20) for _ in range(20)]
# print(f"Наш список: {arr}")
# print(f"Количество простых чисел: {simple_num(arr)}")

"""
Задание 4
Напишите функцию, удаляющую из списка целых
некоторое заданное число. Из функции нужно вернуть
количество удаленных элементов.
"""


def delete_elements(arr: 'list[int]', number) -> int:
    del_elements = 0
    for i in arr:
        if i == number:
            arr.remove(i)
            del_elements += 1
    return del_elements


# print("Задание 4.")
# arr = [randint(1, 20) for _ in range(20)]
# print(f"Наш список: {arr}")
# try:
#     number = int(input("Введите число для удаления: "))
#     print(f"Количество удаленных элементов: {delete_elements(arr, number)}")
#     print(f"Список после удаления: {arr}")
# except ValueError:
#     print("Введен не тот тип. Ожидалось int.")


"""
Задание 5
Напишите функцию, которая получает два списка в
качестве параметра и возвращает список, содержащий
элементы обоих списков.
"""


def unite_lists(arr_1: list, arr_2: list) -> list:
    return arr_1 + arr_2


# print("Задание 5.")
# arr_1 = [randint(1, 10) for _ in range(10)]
# arr_2 = [randint(1, 10) for _ in range(5)]
# print(f"Первый список: {arr_1}")
# print(f"Второй список: {arr_2}")
# print(f"Третий список, содержащий элементы обоих списков: {unite_lists(arr_1, arr_2)}")


"""
Задание 6
Напишите функцию, высчитывающую степень каждого
элемента списка целых. Значение для степени передаётся
в качестве параметра, список тоже передаётся в качестве
параметра. Функция возвращает новый список, содержащий полученные результаты.
"""


def list_degree(arr: list, degree: int) -> list:
    degree_list = list(arr)
    for i in range(len(degree_list)):
        degree_list[i] = degree_list[i] ** degree
    return degree_list


print("Задание 6.")
arr = [randint(1, 10) for i in range(10)]
print(f"Список: {arr}")
new_arr = list_degree(arr, 2)
print(f"Новый список: {new_arr}")
