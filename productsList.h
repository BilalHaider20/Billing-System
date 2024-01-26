#ifndef PRODUCTSLIST_H
#define PRODUCTSLIST_H

#include <iostream>
#include "Node.h"
#include "Product.h"
using namespace std;

class ProductsList
{
private:
    string category;
    Node<Product> *head;
    Node<Product> *tail;
    int size;

public:
    Node<Product> *getHead()
    {
        return head;
    }

    ProductsList()
    {
        category = "-";
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ProductsList(string category)
    {
        this->category = category;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int getSize() const
    {
        return size;
    }

    string getCategory()
    {
        return category;
    }

    Product getProduct(int index)
    {
        if (index == 1)
            return head->getData();

        Node<Product> *curr = head;
        for (int i = 1; i < index; i++)
        {
            curr = curr->getNextPtr();
        }
        return curr->getData();
    }

    void addProduct(Product p)
    {
        Node<Product> *N = new Node(p);
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

    bool deleteProduct(int ind)
    {
        if (size == 0)
            return false;
        if (ind == head->getData().getSr())
        {
            Node<Product> *current = head;
            head = nullptr;
            tail = nullptr;
            delete current;
            size--;
            return true;
        }

        Node<Product> *current = head;
        Node<Product> *previous;
        while (current->getNextPtr() != NULL)
        {
            previous = current;
            current = current->getNextPtr();
            if (ind == (current->getData().getSr()))
            {
                previous->setNextPtr(current->getNextPtr());
                size--;
                delete current;
                return true;
            }
        }
        return false;
    }

    void print()
    {
        Node<Product> *curr = head;
        cout << "\n-----------------------------------------\n "
             << category << "\t\t\t\t\t\n-----------------------------------------\n";
        cout << "Sr. \tName\t\t\tPrice" << endl;
        while (curr != nullptr)
        {
            cout << curr->getData().getSr() << "\t" << curr->getData().getProduct_name() << "\t\t\tRs." << curr->getData().getProduct_price() << endl;
            curr = curr->getNextPtr();
        }
        cout << "\n\n\n";
    }
};

#endif // PRODUCTSLIST_H
