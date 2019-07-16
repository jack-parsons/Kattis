

def main():
    c = float(input())
    l = int(input())

    cost = 0.0
    for i in range(l):
        li, wi = input().split(" ")
        li, wi = float(li), float(wi)
        cost += li*wi*c
    
    print("%.7f"%cost)

if __name__ == '__main__':
    main()