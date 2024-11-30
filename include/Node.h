#ifndef NODE_H
#define NODE_H


class Node {
public:
    char data;
    Node* next;
    Node*prev;
    explicit Node(char value) : data(value), next(nullptr), prev(nullptr) {}
};

#endif