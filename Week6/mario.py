height = int(input("Height: "))
length_space = height
length_hash = 1
length_hash_two = 1
for a in range(0, height):
    for p in range(0, length_space):
        print(" ", end="")
    for q in range(0, length_hash):
        print("#", end="")
    print(" ", end="")
    for r in range(0, length_hash_two):
        print("#", end="")
    for p in range(0, height):
        print(" ", end="")
    print("\n")
    length_space = length_space - 1
    length_hash = length_hash + 1
    length_hash_two = length_hash_two + 1


