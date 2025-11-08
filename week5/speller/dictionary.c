// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

void listFree(node *list);
unsigned int listSize(const node *list);

const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase for comparison
    char lower_word[LENGTH + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[strlen(word)] = '\0';

    const node *current = table[hash(lower_word)];
    if (current == NULL) return false;

    while (current != NULL)
    {
        if (strcmp(current->word, lower_word) == 0) return true;
        current = current->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // Initialize hash table to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Buffer to store each word
    char word[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // Create space for a new hash table node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            return false;
        }

        // Copy the word into the new node
        strcpy(new_node->word, word);

        // Hash the word to obtain its hash value
        const int index = hash(word);

        // Insert the new node into the hash table
        // (Insert at beginning of linked list)
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Close the dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            count += listSize(table[i]);
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            listFree(table[i]);
        }
    }
    return true;
}

void listFree(node *list)
{
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

unsigned int listSize(const node *list)
{
    unsigned int count = 0;
    const node *current = list;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}
