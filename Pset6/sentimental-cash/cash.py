while True:
    try:
        money = float(input("Change owed: "))
        if money > 0:
            break
    except ValueError:
        pass

money = round(money * 100)
counter = 0

for coin in [25, 10, 5, 1]:
    counter += money // coin
    money %= coin

print(counter)
