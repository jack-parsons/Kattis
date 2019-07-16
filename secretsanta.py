import math

def main():
    n = int(input())

    if n > 20:
        print(1-1/math.e)
        return

    n+=1
    c = 0
    f = 1
    for i in range(1, n):
        f *= i
        c += ((-1)**(i+1))/f
    
    print(c)

if __name__ == '__main__':
    main()