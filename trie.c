#include "trie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Trie *createTrie()
{
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void insert(Trie *trie, const char *word)
{

    Node *node = trie->root;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        char ch = word[i];
        if (!containsKey(node, ch))
        {
            Node *newNode = createNode();
            put(node, ch, newNode);
        }
        node = getNode(node, ch);
    }

    setEnd(node);
}

int search(Trie *trie, const char *word)
{
    Node *node = trie->root;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        char ch = word[i];
        if (!containsKey(node, ch))
        {
            return 0; // Word not found
        }
        node = getNode(node, ch);
    }

    return isEnd(node);
}

int startsWith(Trie *trie, const char *prefix)
{
    Node *node = trie->root;
    int length = strlen(prefix);

    for (int i = 0; i < length; i++)
    {
        char ch = prefix[i];
        if (!containsKey(node, ch))
        {
            return 0; // Prefix not found
        }
        node = getNode(node, ch);
    }

    return 1; // Prefix found
}
