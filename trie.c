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

void dfs(Node *node, char *currentPrefix)
{
    if (node->flag)
    {
        printf("%s\n", currentPrefix);
    }

    for (int i = 0; i < 26; i++)
    {
        if (node->links[i])
        {
            char nextCharacter = 'a' + i;
            char *nextPrefix = (char *)malloc(strlen(currentPrefix) + 2);
            sprintf(nextPrefix, "%s%c", currentPrefix, nextCharacter);
            dfs(node->links[i], nextPrefix);
            free(nextPrefix);
        }
    }
}

// Function to search for all words with a given prefix
void searchWithPrefix(Trie *trie, const char *prefix)
{
    Node *node = trie->root;

    for (int i = 0; i < strlen(prefix); i++)
    {
        char ch = prefix[i];
        if (!containsKey(node, ch))
        {
            printf("No words found with the prefix '%s'\n", prefix);
            return;
        }
        node = getNode(node, ch);
    }

    dfs(node, (char *)prefix);
}