from typing import Final

invalid: Final[str] = "INVALID"
visa: Final[str] = "VISA"
visa_start: Final[str] = "4"
visa_len: Final[list[int]] = [13, 16]

master: Final[str] = "MASTERCARD"
master_start: Final[list[str]] = ["51", "52", "53", "54", "55"]
master_len: Final[int] = 16

amex: Final[str] = "AMEX"
amex_start: Final[list[str]] = ["34", "37"]
amex_len: Final[int] = 15

inp: str = input("Credit: ")

def luhn_validator(card_number: str) -> bool:
    digits = [int(d) for d in card_number]

    sum_doubled = 0
    for i in range(len(digits) - 2, -1, -2):
        doubled = digits[i] * 2
        sum_doubled += doubled // 10 + doubled % 10

    sum_not_doubled = 0
    for i in range(len(digits) - 1, -1, -2):
        sum_not_doubled += digits[i]

    total = sum_doubled + sum_not_doubled

    return total % 10 == 0

if not luhn_validator(inp):
    print(invalid)
    exit(1)

for length in visa_len:
    if len(inp) == length and inp.startswith(visa_start):
        print(visa)
        exit(0)
    else:
        print(f"{inp} not visa")

for start in master_start:
    if len(inp) == master_len and inp.startswith(start):
        print(master)
        exit(0)
    else:
        print(f"{inp} not master")

for start in amex_start:
    if len(inp) == amex_len and inp.startswith(start):
        print(amex)
        exit(0)
    else:
        print(f"{inp} not amex")

print(invalid)
exit(1)
