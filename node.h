#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

struct Node
{
    Node *links[26];
    int flag; // Using an int as a boolean (0 for false, 1 for true)
};

Node *createNode();
Node *getNode(Node *node, char ch);
int containsKey(Node *node, char ch);

void put(Node *node, char ch, Node *newNode);
void setEnd(Node *node);
int isEnd(Node *node);

#endif /* NODE_H */
