note_fingers = {
    #     1  2  3  4  5  6  7  8  9  10
    'c': [0, 1, 1, 1, 0, 0, 1, 1, 1, 1],
    'd': [0, 1, 1, 1, 0, 0, 1, 1, 1, 0],
    'e': [0, 1, 1, 1, 0, 0, 1, 1, 0, 0],
    'f': [0, 1, 1, 1, 0, 0, 1, 0, 0, 0],
    'g': [0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    'a': [0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
    'b': [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    'C': [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    'D': [1, 1, 1, 1, 0, 0, 1, 1, 1, 0],
    'E': [1, 1, 1, 1, 0, 0, 1, 1, 0, 0],
    'F': [1, 1, 1, 1, 0, 0, 1, 0, 0, 0],
    'G': [1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    'A': [1, 1, 1, 0, 0, 0, 0, 0, 0, 0],
    'B': [1, 1, 0, 0, 0, 0, 0, 0, 0, 0]
}

for i in range(int(input())):
    total = [0] * 10
    last = [0] * 10
    for c in input():
        current = note_fingers[c]
        z = zip(current, last)
        for p in enumerate(z):
            if p[1][0] == 1 and p[1][1] == 0:
                total[p[0]] += 1
        last = current
    print(" ".join(map(lambda x: str(x), total)))