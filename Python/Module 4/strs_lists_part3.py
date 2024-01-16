from random import randint
"""
Задание 1
Два списка целых заполняются случайными числами.
Необходимо:
■ Сформировать третий список, содержащий элементы
обоих списков;
■ Сформировать третий список, содержащий элементы
обоих списков без повторений;
■ Сформировать третий список, содержащий элементы
общие для двух списков;
■ Сформировать третий список, содержащий только
уникальные элементы каждого из списков;
■ Сформировать третий список, содержащий только
минимальное и максимальное значение каждого из
списков.
"""
length = (0, 5)
list1 = [randint(*length) for _ in range(5)]
list2 = [randint(*length) for _ in range(7)]
all_el_list = list1 + list2  # элементы обоих списков
all_el_no_repeats_list = []  # элементы обоих списков без повторений
for l1 in list1:
    if l1 not in all_el_no_repeats_list:
        all_el_no_repeats_list.append(l1)
for l2 in list2:
    if l2 not in all_el_no_repeats_list:
        all_el_no_repeats_list.append(l2)
total_el_list = []  # элементы общие для двух списков
for l1 in list1:
    if l1 in list2:
        total_el_list.append(l1)
for l2 in list2:
    if l2 in list1:
        total_el_list.append(l2)
unique_list = []  # уникальные элементы
for l1 in list1:
    if l1 not in list2:
        unique_list.append(l1)
for l2 in list2:
    if l2 not in list1:
        unique_list.append(l2)
max_min_list = [min(list1 + list2), max(list1 + list2)]  # из максимального и минимального
print(f"Первый список: {list1}")
print(f"Второй список: {list2}")
print(f"Элементы обоих списков: {all_el_list}")
print(f"Элементы обоих списков без повторений: {all_el_no_repeats_list}")
print(f"Общие элементы для двух списков: {total_el_list}")
print(f"Уникальные элементы: {unique_list}")
print(f"Минимальное и максимальное значение: {max_min_list}")
