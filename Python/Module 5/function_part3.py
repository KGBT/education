from random import randint, choices, choice

"""
Задание 1
Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.
"""


def NOD(number_1: int, number_2: int) -> int:
    if number_1 > number_2:
        number_1, number_2 = number_2, number_1
    # if number_1 == 0:
    #     return number_2
    # if number_2 == 0:
    #     return number_1
    if number_2 % number_1 == 0:
        nod = number_1
    else:
        nod = NOD(number_1, number_2 % number_1)
    return nod


# print("Задание 1.")
# print(f"Наибольший общий делитель чисел 40 и 16: {NOD(40, 16)}")
# print(f"Наибольший общий делитель чисел 80 и 24: {NOD(80, 24)}")
# print(f"Наибольший общий делитель чисел 165 и 45: {NOD(165, 45)}")
# print(f"Наибольший общий делитель чисел 11 и 13: {NOD(11, 13)}")
# print(f"Наибольший общий делитель чисел 2 и 147: {NOD(2, 147)}")

"""
Задание 2
Написать игру «Быки и коровы». Программа «загадывает» четырёхзначное число и играющий должен
угадать его. После ввода пользователем числа программа
сообщает, сколько цифр числа угадано (быки) и сколько
цифр угадано и стоит на нужном месте (коровы). После
отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток. В программе
необходимо использовать рекурсию.
"""


def rules() -> None:
    print("""
Компьютер «загадывает» четырёхзначное число 
и игрок должен угадать его. После ввода игроком четырехзначного 
числа компьютер сообщает, сколько цифр числа угадано (быки) и сколько
цифр угадано и стоит на нужном месте (коровы).
""")


def input_number() -> str:
    while True:
        try:
            player_number = int(input("Введите четырехзначное число: "))
            if len(str(player_number)) != 4:
                raise Exception("Число должно быть четырехзначным.")
            if type(player_number) == int and len(str(player_number)) == 4:
                break
        except ValueError:
            print("Ожидалось число.")
        except Exception as e:
            print(e)

    return str(player_number)


def game(secret_numb: str) -> int:
    bulls = 0
    cows = 0
    numb_att = 1
    player_number = input_number()
    if player_number == secret_numb:
        return numb_att
    for i in range(len(player_number)):
        if player_number[i] in secret_numb:
            bulls += 1
        if player_number[i] == secret_numb[i]:
            cows += 1
    print(f"\nКоличество быков: {bulls}")
    print(f"Количество коров: {cows}")
    # input("Нажмите Enter.")

    return numb_att + game(secret_numb)


# print("Задание 2.")
# end_game = False
# choices = [1, 2, 3]
# secret_number = str(randint(1000, 9999))
# numb_attempts = 0
# while not end_game:
#     print("""
# Добро пожаловать в игру "Быки и коровы".
# 1 - Новая игра.
# 2 - Правила.
# 3 - Выход.
#     """)
#     try:
#         choice = int(input("Выберите действие: "))
#     except ValueError:
#         print("Ожидалась цифра.")
#     if choice == choices[0]:
#         numb_attempts = game(secret_number)
#         print(f"\nПоздравляю! Вы угадали число {secret_number}!\nКоличество сделанных попыток: {numb_attempts}!")
#         input("Нажмите Enter.")
#     if choice == choices[1]:
#         rules()
#         input("Нажмите Enter.")
#     if choice == choices[2]:
#         end_game = True
#     if choice not in choices:
#         print("Ошибка! Такого действия нет.")


"""
Задание 3
Данашахматная доска размером8×8 ишахматный конь.
Программа должна запросить у пользователя координаты
клетки поля и поставить туда коня. Задача программы
найти и вывести путь коня, при котором он обойдет все
клетки доски, становясь в каждую клетку только один
раз. (Так как процесс отыскания пути для разных начальных клеток может затянуться, то рекомендуется сначала 
опробовать задачу на поле размером 6×6). В программе
необходимо использовать рекурсию.
"""

# Нашел решение в книге "Алгоритмы и структуры данных" Никлаус Вирт. Не смог разобраться.
# print("Задание 3.")
# n = 8
# game_field = [[]]
# dx = []
# dy = []
#
#
# def can_be_done(u: int, v: int, i: int) -> bool:
#     done: bool
#     game_field[u][v] = i
#     try_next_move(u, v, i, done)
#     if not done:
#         game_field[u][v] = 0
#     return done
#
#
# def try_next_move(x: int, y: int, i: int, done: bool):
#     eos: bool
#     u: int
#     v: int
#     k: int = 0
#
#     def next(eos: bool, u: int, v: int):
#         while True:
#             k += 1
#             if k < 8:
#                 u = x + dx[k]
#                 v = y + dy[k]
#             if (k == 8) or ((0 <= u) and (u < n) and (0 <= v) and (v < n) and (game_field[u][v] == 0)):
#                 break
#         eos = k = 8
#
#     def first(eos: bool, u: int, v: int):
#         eos = False
#         k = -1
#         next(eos, u, v)


"""
Задание 4
Написать игру «Пятнашки».
"""


# Функция, замешивающая цифры
def shuffle_field(field: list) -> list:
    playing_field = []
    for i in range(4):
        playing_field.append([])
        for j in range(4):
            choice_number = choice(field)
            playing_field[i].append(choice_number)
            field.remove(choice_number)
    return playing_field


# Проверяет возможный ход
def is_move(pl_x: int, pl_y: int, cur_x: int, cur_y: int) -> bool:
    is_x, is_y = False, False
    if pl_x in (range(cur_x - 1, cur_x + 2)):
        is_x = True
    if pl_y in (range(cur_y - 1, cur_y + 2)):
        is_y = True
    return is_x and is_y


# Координата х
def get_coord_x() -> int:
    while True:
        try:
            x = int(input("Введите координату по оси х (от 1 до 4), куда хотите сдвинуть цифру: "))
            if x not in (range(1, 5)):
                raise Exception("Число должно находится в диапазоне от 1 до 4.")
            if x in (range(1, 5)):
                break
        except ValueError:
            print("Ожидалась целая цифра.")
        except Exception as e:
            print(e)
    return x - 1


# Координата у
def get_coord_y() -> int:
    while True:
        try:
            y = int(input("Введите координату по оси у (от 1 до 4), куда хотите сдвинуть цифру: "))
            if y not in (range(1, 5)):
                raise Exception("Число должно находится в диапазоне от 1 до 4.")
            if y in (range(1, 5)):
                break
        except ValueError:
            print("Ожидалась целая цифра.")
        except Exception as e:
            print(e)
    return y - 1


# Текущие координаты пустого места
def get_curr_coord(pl_field: list) -> list:
    x, y = 0, 0
    for i in range(4):
        for j in range(4):
            if pl_field[i][j] == "  ":
                x = j
                y = i
                break
        if x > 0 and y > 0:
            break
    return [x, y]


# Выводит игровое поле
def print_field(pl_field: list) -> None:
    print()
    for i in pl_field:
        print(i)


# Правила
def rules_15() -> None:
    print("""
    Правила.
Расположите костяшки так, чтобы числа шли подряд слева направо и сверху вниз.""")


def game_15(pl_field: list, end_game_f: list) -> None:
    while True:
        print_field(pl_field)
        cur_x_y = get_curr_coord(pl_field)
        print(f"Текущие координаты пустой клетки x,y: {cur_x_y[0] + 1, cur_x_y[1] + 1}")
        pl_x = get_coord_x()
        pl_y = get_coord_y()
        if is_move(pl_x, pl_y, cur_x_y[0], cur_x_y[1]):
            pl_field[cur_x_y[1]][cur_x_y[0]], pl_field[pl_y][pl_x] = pl_field[pl_y][pl_x], pl_field[cur_x_y[1]][cur_x_y[0]]
        # В теории должен выйти из игры
        if pl_field == end_game_f:
            print("Поздравляю! Вы собрали 15!")

# end_game = False
# choices = ["1", "2", "3"]
# numbers_15 = [" 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", "13", "14", "15", "  "]
# end_game_field = [[" 1", " 2", " 3", " 4"], [" 5", " 6", " 7", " 8"], [" 9", "10", "11", "12"],
#                   ["13", "14", "15", "  "]]
# playing_field = shuffle_field(numbers_15)
# print("Задание 4.")
# while not end_game:
#     print("""
# Добро пожаловать в игру "Пятнашки".
# 1 - Новая игра.
# 2 - Правила.
# 3 - Выход.
#     """)
#
#     choice = input("Выберите действие: ")
#     if choice == choices[0]:
#         game_15(playing_field, end_game_field)
#     if choice == choices[1]:
#         rules_15()
#         input("Чтобы продолжить нажмите Enter.")
#     if choice == choices[2]:
#         end_game = True
#     if choice not in choices:
#         print("Ошибка! Такого действия нет.")
