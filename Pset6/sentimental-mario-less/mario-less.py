while True:
    try:
        height = int(input("Do you want how many stepness: "))
        if 1 <= height <= 8:
            break
    except ValueError:
        pass

for i in range(height):
    print(" " * (height - 1 - i) + "#" * (i + 1))
