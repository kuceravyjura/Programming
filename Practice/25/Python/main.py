import random
import typing


def IsSorted(array: list, ascending=True) -> bool:
    size = len(array)
    if ascending:
        for i in range(1, size):
            if array[i - 1] > array[i]:
                return False
    else:
        for i in range(1, size):
            if array[i - 1] < array[i]:
                return False
    return True


def BozoSort(array: list, ascending=True) -> typing.List[int]:
    answer = []

    if len(array) <= 1:
        return answer

    if type(array[0]) == list:
        for third in array:
            answer += third
    else:
        answer = array.copy()

    size = len(answer)
    while not IsSorted(answer, ascending):
        a, b = random.randint(0, size - 1), random.randint(0, size - 1)
        answer[a], answer[b] = answer[b], answer[a]

    return answer


def BozoSortthird(a: int, b: int, c: int, ascending=True) -> typing.List[int]:
    return BozoSort([a, b, c], ascending)


n = int(input('Введите количество эелементов для сортировки(должно соответствовать квадрату целого числа): '))
print('Введите эелементы подлежащие сортировке: ', end='')
first = list(map(int, input().split(' ')))
second = []
third = []
i = 0
for elem in first:
    third.append(elem)
    i += 1
    if i % (n ** 0.5) == 0:
        second.append(third)
        third = []
        i = 0
del third, i

print(' '.join(map(str, BozoSort(first, True))))
print(' '.join(map(str, BozoSort(first, False))))
print(' '.join(map(str, BozoSort(second, True))))
print(' '.join(map(str, BozoSort(second, False))))
print(' '.join(map(str, BozoSortthird(first[0], first[1], first[2], True))))
print(' '.join(map(str, BozoSortthird(first[0], first[1], first[2], False))))
