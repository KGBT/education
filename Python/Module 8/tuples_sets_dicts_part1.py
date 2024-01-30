from random import randint

"""
Задание 1
Есть три кортежа целых чисел необходимо найти
элементы, которые есть во всех кортежах.
"""
# a = -3
# b = 3
# tuple_a = (
# randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b),
# randint(a, b), randint(a, b))
# tuple_b = (randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b))
# tuple_c = (randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b))
#
# print("Задание 1.")
# print(f"Кортеж А: {tuple_a}")
# print(f"Кортеж B: {tuple_b}")
# print(f"Кортеж C: {tuple_c}")
# commons_elements = tuple(set(tuple_a) & set(tuple_b) & set(tuple_c))
# if len(commons_elements) == 0:
#     print("Общие элементы отсутствуют!")
# else:
#     print(f"Общие элементы: {commons_elements}")


"""
Задание 2
Есть три кортежа целых чисел необходимо найти
элементы, которые уникальны для каждого списка.
"""

def display_tuple(tuple_:tuple)->None:
    if len(tuple_) == 0:
        print("Уникальные элементы отсутствуют!")
    else:
        print(f"Уникальные элементы: {tuple_}")


# print("Задание 2.")
# a = -10
# b = 10
# tuple_a = (
# randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b),
# randint(a, b), randint(a, b))
# tuple_b = (randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b))
# tuple_c = (randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b))
# print(f"Кортеж А: {tuple_a}")
# print(f"Кортеж B: {tuple_b}")
# print(f"Кортеж C: {tuple_c}")
# print(f"Множество А: {set(tuple_a)}")
# print(f"Множество B: {set(tuple_b)}")
# print(f"Множество C: {set(tuple_c)}")
# unique_elements_A = tuple(set(tuple_a) - set(tuple_b).union(set(tuple_c)))
# unique_elements_B = tuple(set(tuple_b) - set(tuple_a).union(set(tuple_c)))
# unique_elements_C = tuple(set(tuple_c) - set(tuple_b).union(set(tuple_a)))
# print("Уникальные элементы кортежа А:")
# display_tuple(unique_elements_A)
# print("Уникальные элементы кортежа B:")
# display_tuple(unique_elements_B)
# print("Уникальные элементы кортежа C:")
# display_tuple(unique_elements_C)


"""
Задание 3
Есть три кортежа целых чисел необходимо найти элементы, которые есть в каждом из кортежей и находятся
в каждом из кортежей на той же позиции.
"""

print("Задание 3.")
a = 1
b = 2
tuple_a = (
randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b),
randint(a, b), randint(a, b))
tuple_b = (randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b))
tuple_c = (randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b), randint(a, b))
print(f"Кортеж А: {tuple_a}")
print(f"Кортеж B: {tuple_b}")
print(f"Кортеж C: {tuple_c}")
result_list = []
for i in range(min(len(tuple_a), len(tuple_b), len(tuple_c))):
    if tuple_a[i] == tuple_b[i] == tuple_c[i]:
        result_list.append(tuple_a[i])
if len(result_list) != 0:
    print(f"Элементы, которые есть в каждом из кортежей и находятся в каждом из кортежей на той же позиции {result_list}")
else:
    print("Таких элементов нет!")