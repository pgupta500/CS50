def main():
    text = input("Text: ")
    size = len(text)

    sentences = 0
    letters = 0
    words = 1

    for c in text:
        if c in ".!?":
            sentences += 1
        elif c.isalpha():
            letters += 1
        elif c == " ":
            words += 1

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
