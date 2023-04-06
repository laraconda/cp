#!/usr/bin/env python3

nab = list(map(int, input().split()))
n = nab[0]
a = nab[1]
b = nab[2]

MAXN = 50003
MOD  = 10**9 + 7

c = list()
aa = list()
bb = list()

for i in range(MAXN):
    c.append(0)
    aa.append(0)
    bb.append(0)

def C(i):
    if c[i] == 0:
        c[i] = (A(i) + B(i)) % MOD
    return c[i]


def A(i):
    if (i <= 1):
        aa[i] = 1
    elif i <= a:
        aa[i] = C(i-1)
    elif aa[i] == 0:
        aa[i] = (C(i-1) - B(i - a - 1)) % MOD
    return aa[i]


def B(i):
    if (i <= 1):
        bb[i] = 1
    elif i <= b:
        bb[i] = C(i-1)
    elif bb[i] == 0:
        bb[i] = (C(i-1) - A(i - b - 1)) % MOD
    return bb[i]


for i in range(1, n+1):
    C(i)

print(c[n] % MOD)
