from random import randint

N=5
LIM = 1000000000
for i in range(N):
   n = randint(0, LIM) 
   m = randint(0, LIM) 
   a = randint(0, LIM) 
   k = randint(0, LIM)
   if n == 0 and m == 0 and a == 0 and k == 0: continue
   print('{} {} {} {}'.format(n, m, a, k))

print('0 0 0 0')
