n = int(input())
b = 0
for i in range(n-1, -1, -1):
    b += 2**i * (1 if input()=="Z" else 0)
print(2**n - b - 1)