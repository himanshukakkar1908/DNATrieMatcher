#ifndef TRIE_H
#define TRIE_H

#include "node.h"

typedef struct Trie Trie;

struct Trie
{
    Node *root;
};

Trie *createTrie();
void insert(Trie *trie, const char *word);
int search(Trie *trie, const char *word);
int startsWith(Trie *trie, const char *prefix);
void searchWithPrefix(Trie *trie, const char *prefix);

#endif /* TRIE_H */
