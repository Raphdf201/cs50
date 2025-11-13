import csv
import sys

def main():
    head: list[str] = []
    db: list[dict[str, str]] = []
    seq: str

    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        exit(1)

    with open(sys.argv[1]) as database:
        reader: csv.DictReader = csv.DictReader(database)
        head = list(reader.fieldnames)
        for row in reader:
            db.append(row)

    with open(sys.argv[2]) as sequence:
        seq = sequence.read().strip()

    strs: list[str] = head[1:]
    str_counts: dict[str, int] = {}

    for str_name in strs:
        str_counts[str_name] = longest_match(seq, str_name)

    for person in db:
        match = True
        for str_name in strs:
            if int(person[str_name]) != str_counts[str_name]:
                match = False
                break

        if match:
            print(person['name'])
            return

    print("No match")
    return


def longest_match(sequence, subsequence) -> int:
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
