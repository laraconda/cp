import math

t = int(input())

alf = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

def gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a % b)


for z in range(1, t+1):
    nl = list(map(int, input().split()))
    n = nl[0]
    l = nl[1]

    ls = list(map(int, input().split()))
    ansl = list()
    for _ in range(l+1):
        ansl.append('')

    primes = list()

    si = 0
    for i in range(l-1):
        if ls[i] != ls[i+1]:
            k = gcd(ls[i], ls[i+1])
            si = i
    
    g = k
    primes.append(ls[si]//k)
    ansl[si] = ls[si]//k
    primes.append(k)
    ansl[si+1] = k
    for i in range(si+1, l):
        k = ls[i]//k
        primes.append(k)
        ansl[i+1] = k

    k = ls[si]//g
    for i in range(si-1, -1, -1):
        k = ls[i]//k
        primes.append(k)
        ansl[i] = k

    primes = list(set(primes))
    primes.sort()

    ans = ''
    for a in ansl:
        ans += alf[primes.index(a)]
    print('Case #{}: {}'.format(z, ans))


