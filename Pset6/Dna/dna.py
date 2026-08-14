import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        return

    # Read database file
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        rows = list(reader)

    # Read DNA sequence
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # Find longest match of each STR
    strs = reader.fieldnames[1:]
    matches = {}

    for STR in strs:
        matches[STR] = longest_match(sequence, STR)

    # Check database for matching profiles
    for person in rows:
        match = True

        for STR in strs:
            if int(person[STR]) != matches[STR]:
                match = False
                break

        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


main()
