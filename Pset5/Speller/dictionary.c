#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets
const unsigned int N = 65536;

// Hash table
node *table[N];

// Number of words in dictionary
unsigned int word_count = 0;

// Hash function
unsigned int hash(const char *word)
{
    unsigned long hash_value = 5381;

    while (*word)
    {
        hash_value = hash_value * 33 + tolower(*word);
        word++;
    }

    return hash_value % N;
}

// Loads dictionary into memory
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%45s", word) == 1)
    {
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            fclose(file);
            unload();
            return false;
        }

        strcpy(new_node->word, word);

        unsigned int index = hash(word);

        new_node->next = table[index];
        table[index] = new_node;

        word_count++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary
unsigned int size(void)
{
    return word_count;
}

// Checks if word is in dictionary
bool check(const char *word)
{
    unsigned int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Unloads dictionary from memory
bool unload(void)
{
    for (unsigned int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        table[i] = NULL;
    }

    return true;
}
