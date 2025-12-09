while True:
    try:
        height = int(input("Height: "))
        if height>=1 and height<=8:
            break
    except ValueError:
        pass

length_space = height -1
length_hash = 1
length_hash_two = 1
for a in range(0, height):
    for p in range(0, length_space):
        print(" ", end="")
    for q in range(0, length_hash):
        print("#", end="")
    print("  ", end="")
    for r in range(0, length_hash_two):
        print("#", end="")
    print()
    length_space = length_space - 1
    length_hash = length_hash + 1
    length_hash_two = length_hash_two + 1


