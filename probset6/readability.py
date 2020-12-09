l = 0
w = 0
s = 0

text = input("Text to be analysed: ")
n = len(text)
for i in range(n):
    if text[i].isalpha():
        l += 1
    elif text[i].isspace():
        w += 1
    elif text[i] == '.' or text[i] == '?' or text[i] == '!':
        s += 1
w=w+1 #last word is not followed by space
L = ((l * 100.00) / w)
S = ((s * 100.00) / w)

answer = 0.0588 * L - 0.296 * S - 15.8

answer = round(answer)


if answer < 1:
    print("Before Grade 1")
elif answer >= 16:
    print("Grade 16+")
elif answer >= 1:
    print("Grade", answer)
