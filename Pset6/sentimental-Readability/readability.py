text = input("Text: ")

letters = sum(char.isalpha() for char in text)
words = len(text.split())
sentences = sum(char in ".!?" for char in text)

L = letters / words * 100
S = sentences / words * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print("Grade 16+")
elif index >= 1:
    print(f"Grade {index}")
else:
    print("Before Grade 1")
