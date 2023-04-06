#!/usr/bin/env python3

n_ = int(input())
k_ = int(input())

kount = list()
w = list()
wo = list()

MAXN = 1900

for _ in range(MAXN):
    kount.append(0)
    w.append(0)
    wo.append(0)


def kountf(n, k):
    for i in range(1, n+1):
        if i == 1:
            kount[1] = k-1
            w[1] = 0
            wo[1] = k-1
        else:
            wo[i] = kount[i-1] * (k-1)
            w[i] = wo[i-1]
            kount[i] = wo[i] + w[i]
    return kount[n]
        

print(kountf(n_, k_))
