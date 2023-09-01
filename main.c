#include <stdio.h>
#include <string.h>
#include "trie.h"

int main()
{
    Trie *trie = createTrie();

    // Insert strings into the trie
    insert(trie, "apple");
    insert(trie, "app development");
    insert(trie, "racecar");
    insert(trie, "banana");
    insert(trie, "range");

    // Search for strings in the trie
    if (search(trie, "apple"))
    {
        printf("'apple' found in the trie.\n");
    }
    else
    {
        printf("'apple' not found in the trie.\n");
    }

    if (search(trie, "orange"))
    {
        printf("'orange' found in the trie.\n");
    }
    else
    {
        printf("'orange' not found in the trie.\n");
    }

    return 0;
}
