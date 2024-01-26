#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <iostream>
#include "Node.h"
#include "productsList.h"
using namespace std;

class Categories
{
private:
    Node<ProductsList *> *head;
    Node<ProductsList *> *tail;
    int size;

public:
    Node<ProductsList *> *getHead()
    {
        return head;
    }

    Categories()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int getSize() const
    {
        return size;
    }

    ProductsList *get_Category(int index)
    {
        if (index == 1)
            return head->getData();

        Node<ProductsList *> *curr = head;
        for (int i = 1; i < index; i++)
        {
            curr = curr->getNextPtr();
        }
        return curr->getData();
    }

    void addCategory(string category)
    {
        ProductsList *p = new ProductsList(category);
        Node<ProductsList *> *N = new Node(p);
        if (head == NULL)
        {
            N->setNextPtr(nullptr);
            head = N;
            tail = N;
            size++;
            return;
        }

        tail->setNextPtr(N);
        tail = tail->getNextPtr();
        size++;
        return;
    }

    bool deleteCategory(int ind)
    {
        if (size == 0 || ind > size)
            return false;

        if (size == ind == 1)
        {
            Node<ProductsList *> *curr = head;
            delete curr;
            size--;
            return true;
        }

        if (size > 1 && ind == 1)
        {
            Node<ProductsList *> *curr = head;
            head = curr->getNextPtr();
            size--;
            delete curr;
            return true;
        }

        Node<ProductsList *> *current = head;
        Node<ProductsList *> *previous;
        for (int i = 1; i < ind; i++)
        {
            previous = current;
            current = current->getNextPtr();
        }

        previous->setNextPtr(current->getNextPtr());
        size--;
        delete current;
        return true;
    }

    void Print()
    {
        Node<ProductsList *> *curr = head;
        while (curr != nullptr)
        {
            curr->getData()->print();
            curr = curr->getNextPtr();
        }
    }
};

#endif // CATEGORIES_H
