q = int(input())

cats = list()
cats.append(1)


def cat(n):
    return (cats[n-1] * (2*n * (2*n - 1)) // ((n+1) * n))


for i in range(1, 5003):
    x = cat(i)
    cats.append(x)


for _ in range(q):
    x = int(input())
    print(cats[x])

