#ifndef NODE_H
#define NODE_H

#include "product.h"

class Node
{
private:
    Product product;
    Node *nextPtr;

public:
    Node()
    {
        nextPtr = nullptr;
    }

    Node(Product p)
    {
        product = p;
        nextPtr = nullptr;
    }

    Product getData()
    {
        return product;
    }

    Node *getNextPtr()
    {
        return nextPtr;
    }

    void setData(Product p)
    {
        product = p;
    }

    void setNextPtr(Node *p)
    {
        nextPtr = p;
    }
};

#endif // NODE_H
