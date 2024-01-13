import re

# print('Задание 1')
# palindrome = input('Введите строку: ')
# is_palindrome = palindrome.replace(' ', '').lower()
# center = len(is_palindrome) // 2
# end = len(is_palindrome)-1
# if is_palindrome[:center] == is_palindrome[end:center:-1]:
#     print("Строка: " + palindrome + ". Является палиндромом!")
# else:
#     print("Строка: " + palindrome + ". Не является палиндромом!")


# print('Задание 2')
# text = input("Введите текст:\n")
# words = input("Введите список слов\n").title().split(" ")
# for word in words:
#     text = text.replace(word.lower(), word)
# print("Измененный текст:\n")
# print(text)

print('Задание 3')
text = input('Введите текст:\n')
reg_ex = r'[.!?]+'
count_proposal = len(re.findall(reg_ex, text))
print('В тексте:', count_proposal, "предложений!")
