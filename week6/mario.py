from lib import print_no_ln

def is_valid_height(h: str) -> bool:
    if height.isdigit() and 0 < int(h) <= 8:
        return True
    return False

height: str = input("Height: ")

while not is_valid_height(height):
    height = input("Height: ")

for i in range(1, int(height) + 1):
    for j in range(int(height) - i):
        print_no_ln(" ")

    for j in range(i):
        print_no_ln("#")

    print_no_ln("  ")

    for j in range(i):
        print_no_ln("#")

    print()
