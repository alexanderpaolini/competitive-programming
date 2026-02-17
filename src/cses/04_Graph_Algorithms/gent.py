from random import randint 
n = int(1e5)
m = int(2 * 1e5)
print(n)
print(m)
for i in range(m):
    print(randint(1, n), randint(1, n), randint(1, 1e9))
