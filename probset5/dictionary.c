#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
const unsigned int N =26;
unsigned int hash_value;
unsigned int word_count;
node *table[N];

bool load(const char *dictionary)
{
     
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
         node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }

    fclose(file);
    return true;
}


unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *word++))        
    {
              
        toupper(c); // standardizing case
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % N;
}

unsigned int size(void)
{
  return word_count;
}



bool check(const char *word)
{
    hash_value = hash(word);
    node *cursor = table[hash_value]; //find and move to index value

  while (cursor != NULL)
    {
       if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
   cursor = cursor->next;
    }
return false;
}

bool unload(void)
{
    
    for (int i = 0; i < N; i++)
    {
          
        node *cursor = table[i];
  
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}

