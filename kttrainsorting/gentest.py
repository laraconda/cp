from random import randint

n = randint(0, 2000)
print(n)

k = list()
for i in range(10001):
    k.append(0)

for _ in range(n):
    x = randint(1, 10000)
    while k[x] == 1:
        x = randint(1, 10000)
    print(x)
    k[x] = 1
