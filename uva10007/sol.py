
cats = list()
cats.append(1)

facts = list()
facts.append(1)


def cat(n):
    return (cats[n-1] * (2*n * (2*n - 1)) // ((n+1) * n))


for i in range(1, 304):
    facts.append(i * facts[i-1])
    cats.append(cat(i))


while True:
    x = int(input())
    if (x == 0):
        break
    print(cats[x] * facts[x])

