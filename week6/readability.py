def get_sentences(text: str) -> int:
    res: int = 0
    for char in text:
        if char == "." or char == "!" or char == "?":
            res += 1
    return res

def get_words(text: str) -> int:
    return len(text.split())

def get_letters(text: str) -> int:
    res: int = 0
    for char in text:
        if char.isalpha():
            res += 1
    return res

def compute_grade(text: str) -> int:
    sentences: int = get_sentences(text)
    words: int = get_words(text)
    letters: int = get_letters(text)
    return round(0.0588 * ((letters / words) * 100.0) - 0.296 * ((sentences / words) * 100.0) - 15.8)

inp: str = input("Text : ")
grade: int = compute_grade(inp)
if grade >= 16:
    print("Grade 16+")
    exit(0)
elif grade < 1:
    print("Before Grade 1")
    exit(0)
else:
    print(f"Grade {grade}")
    exit(0)
