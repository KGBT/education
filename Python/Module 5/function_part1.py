"""
Задание 1
Напишите функцию, которая отображает на экран
форматированный текст, указанный ниже:
“Don't compare yourself with anyone in this world…
if you do so, you are insulting yourself.”
                                        Bill Gates
"""


def bill_gates() -> None:
    #     text = """“Don't compare yourself with anyone in this world…
    # if you do so, you are insulting yourself.”
    # Bill Gates"""
    # Не понял как это сделать с текстом выше. Поэтому поделил на предложения.
    str1 = """“Don't compare yourself with anyone in this world…"""
    str2 = """if you do so, you are insulting yourself.”"""
    str3 = """Bill Gates"""
    print(str1.ljust(50))
    print(str2.ljust(50))
    print(str3.rjust(50))


# print('Задание 1.')
# bill_gates()
"""
Задание 2
Напишите функцию, которая принимает два числа
в качестве параметра и отображает все четные числа
между ними.
"""


def print_even_number(num_1: int, num_2: int) -> None:
    if num_1 > num_2:
        num_1, num_2 = num_2, num_1
    for i in range(num_1 + num_1 % 2, num_2, 2):
        print(i, end=' ')
    print()


# print("Задание 2.")
# num_1 = 50
# num_2 = 10
# print(f"Все четные числа между {num_1, num_2}")
# print_even_number(num_1, num_2)

"""
Задание 3
Напишите функцию, которая отображает пустой или
заполненный квадрат из некоторого символа. Функция
принимает в качестве параметров: длину стороны квадрата, символ и переменную логического типа:
■ если она равна True, квадрат заполненный;
■ если False, квадрат пустой.
"""


def draw_square(side_sq: int, symbol: str, full: bool) -> None:
    if full:
        for _ in range(side_sq):
            print(symbol * side_sq)
    else:
        print(symbol * side_sq)
        for _ in range(side_sq - 2):
            print(symbol + " " * (side_sq - 2) + symbol)
        print(symbol * side_sq)


# print("Задание 3.")
# draw_square(5, symbol="*", full=True)
# print()
# draw_square(5, symbol="*", full=False)

"""
Задание 4
Напишите функцию, которая возвращает минимальное
из пяти чисел. Числа передаются в качестве параметров.
"""


def min_five(num_1: int, num_2: int, num_3: int, num_4: int, num_5: int) -> int:
    return min(num_1, num_2, num_3, num_4, num_5)


# print("Задание 4.")
# print(f"Минимальное из 5 чисел: {min_five(5, 7, 8, 1, 3)}")

"""
Задание 5
Напишите функцию, которая возвращает произведение чисел 
в указанном диапазоне. Границы диапазона передаются в качестве 
параметров. Если границы диапаpазона перепутаны(например, 5 - верхняя граница,
25 - нижняя граница), их нужно поменять местами.
"""


def multiply(bottom_line: int, top_line: int) -> int:
    result = 1
    if bottom_line > top_line:
        bottom_line, top_line = top_line, bottom_line
    for i in range(bottom_line, top_line + 1):
        result *= i
    return result


# print("Задание 5.")
# print(f"Произведение чисел в диапазоне от 1 до 3: {multiply(1, 3)}")
# print(f"Произведение чисел в диапазоне от 20 до 10: {multiply(20, 10)}")


"""
Задание 6
Напишите функцию, которая считает количество
цифр в числе. Число передаётся в качестве параметра. Из
функции нужно вернуть полученное количество цифр.
Например, если передали 3456, количество цифр будет 4.
"""


def count_digits(num: int) -> int:
    return len(str(num))


# print("Задание 6.")
# print(f"Количество цифр в числе 3456: {count_digits(3456)}")

"""
Задание 7
Напишите функцию, которая проверяет является ли
число палиндромом. Число передаётся в качестве параметра. 
Если число палиндром нужно вернуть из функции
true, иначе false.
«Палиндром» — это число, у которого первая часть
цифр равна второй перевернутой части цифр. Например,
123321—палиндром(первая часть 123, вторая 321, которая
после переворота становится 123), 546645 — палиндром,
а 421987 — не палиндром.
"""


def palindrom_number(num: int) -> bool:
    str_num = str(num)
    if str_num[:len(str_num) // 2] == str_num[(len(str_num)):len(str_num) // 2 - 1:-1]:
        return True
    return False


print(f"Число 123321 палиндром? {palindrom_number(123321)}")
print(f"Число 546645 палиндром? {palindrom_number(546645)}")
print(f"Число 421987 палиндром? {palindrom_number(421987)}")
