#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const string p1w = "Player 1 wins!";
const string p2w = "Player 2 wins!";
const string t = "Tie!";

string str_to_upper(string str);
int process_word(string word);

int main(void) {
    string p1 = get_string("Player 1 : ");
    string p2 = get_string("Player 2 : ");
    int sc1 = process_word(str_to_upper(p1));
    int sc2 = process_word(str_to_upper(p2));
    if (sc1 > sc2) {
        printf("%s", p1w);
    } else if (sc1 < sc2) {
        printf("%s", p2w);
    } else {
        printf("%s", t);
    }
}

int process_word(string word) {
    int p = 0;
    for (int i = 0, l = strlen(word); i < l; i++) {
        p += (POINTS[word[i] - 'A']);
    }
    return p;
}

string str_to_upper(string str) {
    for (int i = 0, l = strlen(str); i < l; i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

