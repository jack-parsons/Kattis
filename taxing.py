# https://open.kattis.com/problems/taxing


def total_after_tax(bands, P, income):
    total = 0
    income_remaining = income
    for size, percentage in bands:
        if income_remaining > size:
            total += size * percentage
            income_remaining -= size
        else:
            total += income_remaining * percentage
            return total
    return total + income_remaining * P


def amount_to_friend(bands, P, income, after_tax_target):
    used_up = 0
    filled_up = False
    paid = 0
    recieved = 0
    i = 0
    for size, percentage in bands:
        i += 1
        if not filled_up:
            if used_up + size >= income:
                filled_up = True
                space_next_band = used_up+size-income
                if space_next_band >= after_tax_target and i == 1:
                    return after_tax_target/(1-percentage)
                paid = space_next_band
                recieved = space_next_band*(1-percentage)
            else:
                used_up += size
        else:
            if recieved + size*(1-percentage) >= after_tax_target:
                paid += (after_tax_target - recieved)/(1-percentage)
                return paid
            else:
                recieved += size*(1-percentage)
                paid += size
    paid += (after_tax_target - recieved)/(1-P)
    return paid

def main():
    B = int(input())

    bands = []
    for i in range(B):
        size, percentage = input().split()
        size, percentage = float(size), int(percentage)/100.0
        bands.append((size, percentage))

    P = float(input())/100.0
    F = int(input())

    friends = []
    for i in range(F):
        income, after_tax_target = input().split()
        income, after_tax_target = float(income), float(after_tax_target)
        friends.append((income, after_tax_target))

    for income, after_tax_target in friends:
        print("%.6f" % amount_to_friend(bands, P, income, after_tax_target))
        
if __name__ == '__main__':
    main()