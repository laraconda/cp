#!/usr/bin/env python3

nk = list(map(int, input().split()))
n = nk[0]
k = nk[1]

MAXN = 10004

l = list()
t = list()

for _ in range(MAXN):
    l.append(-1)
    t.append(-1)

def T(i):
    if i < 1:
        return 1
    if i == 1:
        if k == 0:
            return 1
        else:
            return 2
    elif t[i] == -1:
        t[i] = B(i) + L(i)
    return t[i]

def B(i):
    if i <= 1:
        return 1
    return T(i-1)

def L(i):
    if i <= k and l[i] == -1:
        l[i] = T(i-1)
    elif l[i] == -1:
        l[i] = T(i-1) - T(i - k - 2)
    return l[i]


for i in range(1, n+1):
    T(i)

print(T(i))
