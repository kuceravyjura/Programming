_print = print


def create(size, begin, step):
    return [i for i in range(begin, begin + step * size, step)]


def sort(massive, size):
    for i in range(0, size):
        for j in range(i, 0, -1):
            if massive[j] < massive[j - 1]:
                massive[j], massive[j - 1] = massive[j - 1], massive[j]
    return massive


def print(massive, size):
    _print('[', end='')
    for i in range(0, size):
        _print(massive[i], ' ', end='')
    _print(']', end='')


_print('Введитедлину массива, начальный элемент, шаг прогресии')
size = int(input())
begin = int(input())
step = int(input())
massive = create(size, begin, step)
sort(massive, size)
print(massive, size)
