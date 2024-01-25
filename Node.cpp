#include "product.cpp"

class Node
{
private:
    Product product;
    Node *nextPtr;

public:
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