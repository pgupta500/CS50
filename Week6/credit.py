import re

card_no = input("Number: ")
digits = [int(d) for d in card_no]
digits_two = list(digits)
sum_one = 0
sum_two = 0

for i in range(len(card_no) - 2, -1, -2):
    digits[i] = digits[i] * 2
    if digits[i] > 9:
        p = int(str(digits[i])[0])
        q = int(str(digits[i])[1])
        sum_one = sum_one + p + q
    else:
        sum_one = sum_one + digits[i]

for a in range(len(card_no) - 1, -1, -2):
    sum_two += digits_two[a]

if (sum_one + sum_two) % 10 == 0:
    if len(card_no) == 15 and (re.match(r"^34", card_no) or re.match(r"^37", card_no)):
        print("AMEX")
    elif len(card_no) == 16 and (re.match(r"^5[1-5]", card_no)):
        print("MASTERCARD")
    elif (len(card_no) == 13 or len(card_no) == 16) and re.match(r"^4", card_no):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
