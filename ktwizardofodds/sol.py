l = list(input().split())

N = int(l[0])
K = int(l[1])

count = 0
while N > 1:
    N = N / 2
    count += 1

if count <= K:
    print('Your wish is granted!')
else:
    print('You will become a flying monkey!')


   
   



