if __name__ == '__main__':
    n = int(input())
    while n != 0:
        line = input()
        numbers = [int(e) for e in line.split(' ')]
        m = {}

        for number in numbers:
            if number not in m:
                m[number] = 1
            else:
                m[number] = m[number] + 1

        best_value = 0
        best_key = None

        for key, value in m.items():
            if value > best_value:
                best_value = value
                best_key = key

        print(f'{best_key}')
        n = int(input())
