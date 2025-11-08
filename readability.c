#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int compute_grade(string input);
int get_sentences(string input);
int get_words(string input);
int get_letters(string input);

int main(void) {
    string text = get_string("Text : ");
    int grade = compute_grade(text);
    if (grade >= 16) {
        printf("Grade 16+");
    } else if (grade < 1) {
        printf("Before Grade 1");
    } else {
        printf("Grade %i", grade);
    }
    printf("\n");
}

int compute_grade(string input) {
    double sentences = (double) get_sentences(input);
    double words = (double) get_words(input);
    double letters = (double) get_letters(input);
    return (int) round(0.0588 * ((letters / words) * 100.0) - 0.296 * ((sentences / words) * 100.0) - 15.8);
}

int get_sentences(string input) {
    int res = 0;
    for (int i = 0, l = strlen(input); i < l; i++) {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?') {
            res++;
        }
    }
    return res;
}

int get_words(string input) {
    int res = 1;
    for (int i = 0, l = strlen(input); i < l; i++) {
        if (isspace(input[i])) {
            res++;
        }
    }
    return res;
}

int get_letters(string input) {
    int res = 0;
    for (int i = 0, l = strlen(input); i < l; i++) {
        if (isalpha(input[i])) {
            res++;
        }
    }
    return res;
}
