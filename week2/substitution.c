#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string cipher(string text, string key);
bool is_valid_key(string key);

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    if (!is_valid_key(argv[1])) {
        printf("Key must contain 26 unique alphabetic characters\n");
        return 1;
    }
    string text = get_string("plaintext:  ");
    printf("ciphertext: %s\n", cipher(text, argv[1]));
}

string cipher(string text, string key) {
    string res = text;
    for (int i = 0, l = strlen(text); i < l; i++) {
        if (isalpha(text[i])) {
            int index = tolower(text[i]) - 'a';
            char tmp = key[index];

            if (isupper(text[i])) {
                res[i] = toupper(tmp);
            } else {
                res[i] = tolower(tmp);
            }
        }
    }
    return res;
}

bool is_valid_key(string key) {
    if (strlen(key) != 26) {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            return false;
        }

        int index = tolower(key[i]) - 'a';

        if (seen[index]) {
            return false;
        }

        seen[index] = true;
    }

    return true;
}
