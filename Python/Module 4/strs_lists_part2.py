import re
from random import randint

"""
Задание 1:
Пользователь вводит с клавиатуры арифметическое
выражение. Например, 23+12.
Необходимо вывести на экран результат выражения.
В нашем примере это 35. Арифметическое выражение
может состоять только из трёх частей: число, операция,
число. Возможные операции: +, -,*,/
"""
# print("Задание 1")
# result = 0
# try:
#     delemiter = r'[*+-/]{1}'
#     expression = input("Введите выражение типа: 23 + 12.\nВозможные операции: +, -, *, /:\n").replace(" ", "")
#     operation = re.search(delemiter, expression).group()
#     expression = re.split(delemiter, expression)
#     if not expression[0].isdigit() or not expression[1].isdigit():
#         raise Exception("Не удалось преобразовать!")
#     expression = [float(i) for i in expression]
#     if "+" == operation:
#         result = sum(expression)
#     if "-" == operation:
#         result = expression[0] - expression[1]
#     if "*" == operation:
#         result = expression[0] * expression[1]
#     if "/" == operation:
#         if expression[1] == 0:
#             raise ZeroDivisionError
#         result = expression[0] / expression[1]
# except AttributeError:
#     print("Недопустимая операция!")
# except ZeroDivisionError:
#     print("Деление на 0!")
# except Exception as ex:
#     print(ex)
# print("Результат выражения: ", result)


"""
Задание 2:
В списке целых, заполненном случайными числами,
определить минимальный и максимальный элементы,
посчитать количество отрицательных элементов, посчитать количество положительных элементов, посчитать
количество нулей. Результаты вывести на экран.
"""
print("Задание 2")
length = randint(1, 100)
arr = [randint(-100, 100) for _ in range(length)]
min_value = min(arr)
max_value = max(arr)
count_negative_value = 0
count_positive_value = 0
count_zero = arr.count(0)
for i in arr:
    if i < 0:
        count_negative_value += 1
    else:
        count_positive_value += 1
print("Минимальный элемент:", min_value)
print("Максимальный элемент:", max_value)
print("Количество отрицательных элементов:", count_negative_value)
print("Количество положительных элементов:", count_positive_value)
print("Количество нулей:", count_zero)