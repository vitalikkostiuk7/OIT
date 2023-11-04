class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value
    def __lt__(self, other):
        return self.key > other.key


def read_data_from_file(file_name):
    pairs = []
    try:
        with open(file_name, 'r', encoding='utf-8') as file:
            for line in file:
                parts = line.strip().split(',')
                if len(parts) == 2:
                    key, value = parts
                    pairs.append(Pair(key, value))
                else:
                    print(f"Помилка: Некоректний рядок у файлі: {line}")
                    return
        return pairs
    except FileNotFoundError:
        print(f"Помилка: Файл '{file_name}' не знайдено.")
        return


# def merge_sort(arr):
#     if len(arr) <= 1: return arr
#     mid = len(arr) // 2
#     left_half = arr[:mid]
#     right_half = arr[mid:]
#     left_half = merge_sort(left_half)
#     right_half = merge_sort(right_half)
#     return merge(left_half, right_half)

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)
    result = merge(left_half, right_half)
    print("На поточному кроці:")
    for pair in result:
        print(f'Ключ: {pair.key}, Значення: {pair.value}')
        print('----------')
    print('============================')
    return result

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result


file_name = "data.txt"
data = read_data_from_file(file_name)
sorted_pairs = merge_sort(data)
for pair in sorted_pairs:
    print(f'Ключ: {pair.key}, Значення: {pair.value}')
