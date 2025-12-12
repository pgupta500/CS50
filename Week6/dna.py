import csv
import sys

def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database
    with open(sys.argv[1]) as f:
        reader = csv.DictReader(f)
        database = list(reader)

    # Read DNA sequence
    with open(sys.argv[2]) as f:
        sequence = f.read()

    # Get list of STRs from CSV header
    strs = reader.fieldnames[1:]

    # Count longest run of each STR
    counts = {}
    for s in strs:
        counts[s] = longest_match(sequence, s)

    # Check database for match
    for person in database:
        match = True
        for s in strs:
            if int(person[s]) != counts[s]:
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    longest_run = 0
    n = len(subsequence)

    for i in range(len(sequence)):
        count = 0
        while sequence[i + count*n : i + (count+1)*n] == subsequence:
            count += 1
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
