#include "node.h"
#include <stdlib.h>

Node *createNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < 26; i++)
    {
        newNode->links[i] = NULL;
    }
    newNode->flag = 0; // Initialize 'flag' as 0 (false)
    return newNode;
}

int containsKey(Node *node, char ch)
{
    return (node->links[ch - 'a'] != NULL);
}

Node *getNode(Node *node, char ch)
{
    return node->links[ch - 'a'];
}

void put(Node *node, char ch, Node *newNode)
{
    node->links[ch - 'a'] = newNode;
}

void setEnd(Node *node)
{
    node->flag = 1; // Set 'flag' as 1 (true)
}

int isEnd(Node *node)
{
    return node->flag;
}
